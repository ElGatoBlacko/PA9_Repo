#include <SFML/Graphics.hpp>
#include<ctime>
#include"Mole.hpp"
#include<iostream>
#include<sstream>
#include"Menu.hpp"

const int MOLE_NUM = 10;

enum class GameState {
    Menu,
    Playing,
    Score
};

int main(void) {

    srand(static_cast<unsigned>(time(0)));

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML works!");
    sf::Texture moleTexture;
    sf::Font font;
  //  std::cout << "Working directory: " << std::filesystem::current_path() << std::endl;
    moleTexture.loadFromFile("mole_image.png");
    font.openFromFile("C:\\Users\\ariet\\source\\repos\\PA9_Repo_Spot\\PA9_Tai_Town\\PA9_Tai_Town\\WinkyRough-VariableFont_wght.ttf");

    sf::Clock gameClock;
    std::string time = "";
    int hitCount = 0, difficulty=0;
    

    sf::Text runtime(font, time, 30);
    runtime.setFillColor(sf::Color::White);
    runtime.setPosition(sf::Vector2f(0, 0));

   
    std::vector<Mole> moles;
    Menu menu(font);

    for (int i = 0; i < MOLE_NUM; i++) {
        moles.push_back(Mole(moleTexture, 1)); 
    }

    int spaceOut = -1;

    GameState current = GameState::Menu;
    
    while (window.isOpen())
    {
        
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            
            if (current == GameState::Menu) {
                
                if (event->is<sf::Event::MouseButtonPressed>()) {
                    sf::Vector2f pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (menu.getEasyBounds().contains(pos)) {
                        difficulty = 1;
                        current = GameState::Playing;
                        gameClock.restart();
                    }
                    else if (menu.getMediumBounds().contains(pos)) {
                        difficulty = 2;
                        current = GameState::Playing;
                        gameClock.restart();
                    }
                    else if (menu.getHardBounds().contains(pos)) {
                        difficulty = 3;
                        current = GameState::Playing;
                        gameClock.restart();
                    }
                    for (int i = 0; i < MOLE_NUM; i++) {
                        moles[i].initialize(difficulty);
                    }
                }
            }
            else if (current == GameState::Playing) {
                if (event->is<sf::Event::MouseButtonPressed>()) {
                    for (int i = 0; i < MOLE_NUM; ++i) {
                        if (moles[i].isHit(*event, window)) {
                            std::cout << "MOLE HIT" << std::endl;
                            moles[i].hide();
                            moles[i].setHitState(true);
                        }
                    }
                }
            }
            else if (current == GameState::Score) {
                if (event->is<sf::Event::KeyPressed>()) {
                    runtime.setPosition(sf::Vector2f(0, 0));
                    current = GameState::Menu;
                }
            }
        }

        
        window.clear();

        if (current == GameState::Menu) {
            menu.draw(window);
        }
        else if (current == GameState::Playing) {
            for (int i = 0; i < MOLE_NUM; i++) {
                if (moles[i].getHitState()) {
                    hitCount++;
                }
                else {
                    hitCount = 0;
                }
            }
            if (hitCount < MOLE_NUM) {
                std::stringstream stream;
                stream << std::fixed << std::setprecision(2) << gameClock.getElapsedTime().asSeconds();
                time = stream.str();
                runtime.setString(time);
            }
            else {
                current = GameState::Score;
            }

            for (int i = 0; i < spaceOut && i < MOLE_NUM; i++) {
                window.draw(moles[i]);
                moles[i].update();
            }
            window.draw(runtime);

            

            spaceOut = gameClock.getElapsedTime().asSeconds() - 1;
        }
        else if (current == GameState::Score) {
            sf::Text displayMessage(font, "Score:", 60);
            displayMessage.setPosition(sf::Vector2f(245, 250));
            displayMessage.setFillColor(sf::Color::White);

            runtime.setPosition(sf::Vector2f(400, 250));
            runtime.setCharacterSize(60);


            sf::Text returnPrompt(font, "(Press any key to return to menu)", 30);

            returnPrompt.setPosition(sf::Vector2f(200, 300));
            returnPrompt.setFillColor(sf::Color::White);

            window.draw(displayMessage);
            window.draw(runtime);
            window.draw(returnPrompt);
        }
        window.display();
        
    }
}