#include <SFML/Graphics.hpp>
#include<ctime>
#include"Mole.hpp"
#include<iostream>
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

    sf::Text runtime(font, time, 30);
    runtime.setFillColor(sf::Color::White);
    runtime.setPosition(sf::Vector2f(50, 0));

    std::vector<Mole> moles;

    for (int i = 0; i < 10; i++) {
        moles.push_back(Mole(moleTexture, 1)); 
    }

    int spaceOut = -1;
    
    while (window.isOpen())
    {
        
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
                    
            if (event->is<sf::Event::MouseButtonPressed>()) {
                for (int i = 0; i < 10; ++i) {
                    if (moles[i].isHit(*event, window)) {
                        std::cout << "MOLE HIT" << std::endl;
                        moles[i].hide();
                        moles[i].setHitState(true);
                    }
                }
            }

        }

        
        window.clear();

        time = std::to_string(gameClock.getElapsedTime().asSeconds());
        runtime.setString(time);
        for (int i = 0; i < spaceOut && i <10; i++) {
            window.draw(moles[i]);
            moles[i].update();
        }
        window.draw(runtime);
        window.display();
        
        spaceOut= gameClock.getElapsedTime().asSeconds()-1;
    }
}