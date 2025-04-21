#include <SFML/Graphics.hpp>
#include<ctime>
#include"Mole.hpp"
#include<iostream>
#include<sstream>
#include<fstream>
#include"Menu.hpp"
#include"ScoreRecord.hpp"

const int MOLE_NUM = 10;

enum class GameState {
    Menu,
    Playing,
    Score,
    Records
};

int main(void) {

    srand(static_cast<unsigned>(time(0)));

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML works!");
    sf::Texture moleTexture;
    sf::Font font;
  //  std::cout << "Working directory: " << std::filesystem::current_path() << std::endl;
    moleTexture.loadFromFile("mole_image.png");
    font.openFromFile("WinkyRough-VariableFont_wght.ttf");

    std::ifstream in("HighScores.txt");
    ScoreRecord scores;
    scores.import(in);

    

    sf::Clock gameClock;
    std::string time = "";
    int hitCount = 0, difficulty=0;
    float curScore = 0.0;
    

    sf::Text runtime(font, time, 30);
    runtime.setFillColor(sf::Color::White);
    runtime.setPosition(sf::Vector2f(0, 0));

   
    std::vector<Mole> moles;
    Menu menu(font);

    for (int i = 0; i < MOLE_NUM; i++) {
        moles.push_back(Mole(moleTexture, 1)); 
    }

    int spaceOut = 0;

    GameState current = GameState::Menu;
    
    while (window.isOpen())
    {
        
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                std::ofstream out("HighScores.txt");
                scores.exportScores(out);
                out.close();
                window.close();
            }
            
            if (current == GameState::Menu) {
                
                if (event->is<sf::Event::MouseButtonPressed>()) {
                    sf::Vector2f pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (menu.getEasyBounds().contains(pos)) {
                        difficulty = 1;
                        spaceOut = 0;
                        current = GameState::Playing;
                        gameClock.restart();
                    }
                    else if (menu.getMediumBounds().contains(pos)) {
                        difficulty = 2;
                        spaceOut = 0;
                        current = GameState::Playing;
                        gameClock.restart();
                    }
                    else if (menu.getHardBounds().contains(pos)) {
                        difficulty = 3;
                        spaceOut = 0;
                        current = GameState::Playing;
                        gameClock.restart();
                    }
                    else if (menu.getRecordsBounds().contains(pos)) {
                        current = GameState::Records;
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
            else if (current == GameState::Score || current == GameState::Records) {
                if (event->is<sf::Event::KeyPressed>()) {
                    runtime.setPosition(sf::Vector2f(0, 0));
                    runtime.setCharacterSize(30);
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
                curScore = gameClock.getElapsedTime().asSeconds();
                stream << std::fixed << std::setprecision(2) <<curScore;
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

            

            spaceOut = gameClock.getElapsedTime().asSeconds();
        }
        else if (current == GameState::Score) {

            curScore = std::round(curScore*100)/100;

            switch (difficulty) {
            case 1:
                if (curScore < scores.getEasy()) {
                    scores.setEasy(curScore);
                }
                break;
            case 2:
                if (curScore < scores.getMedium()) {
                    scores.setMedium(curScore);
                }
                break;
            case 3:
                if (curScore < scores.getHard()) {
                    scores.setHard(curScore);
                }
                break;
            }
            

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
        else if (current == GameState::Records) {
            std::stringstream recordStream;
            recordStream<<"Easy Record: "<<std::fixed << std::setprecision(2) << scores.getEasy();
            std::string temp = recordStream.str();
            recordStream.str("");
            recordStream.clear();

            sf::Text easyMessage(font, temp, 40);
            easyMessage.setPosition(sf::Vector2f(250, 100));
            easyMessage.setFillColor(sf::Color::White);

            recordStream << "Intermediate Record: " << std::fixed << std::setprecision(2) << scores.getMedium();
            temp = recordStream.str();
            recordStream.str("");
            recordStream.clear();

            sf::Text mediumMessage(font, temp, 40);
            mediumMessage.setPosition(sf::Vector2f(175, 200));
            mediumMessage.setFillColor(sf::Color::White);

            recordStream << "Hard Record: " << std::fixed << std::setprecision(2) << scores.getHard();
            temp = recordStream.str();
            recordStream.str("");
            recordStream.clear();
            sf::Text hardMessage(font, temp, 40);
            hardMessage.setPosition(sf::Vector2f(250, 300));
            hardMessage.setFillColor(sf::Color::White);

            sf::Text returnPrompt(font, "(Press any key to return to menu)", 20);
            returnPrompt.setPosition(sf::Vector2f(250, 400));
            returnPrompt.setFillColor(sf::Color::White);

            window.draw(easyMessage);
            window.draw(mediumMessage);
            window.draw(hardMessage);
            window.draw(returnPrompt);
        }
        window.display();
        
    }
    in.close();
}