#include <SFML/Graphics.hpp>
#include<ctime>
#include"Mole.hpp"
#include<iostream>
int main(void) {

    srand(static_cast<unsigned>(time(0)));

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML works!");
    sf::Texture moleTexture;
  //  std::cout << "Working directory: " << std::filesystem::current_path() << std::endl;
    moleTexture.loadFromFile("mole_image.png");

    std::vector<Mole> moles;

    for (int i = 0; i < 10; i++) {
        moles.push_back(Mole(moleTexture, 1)); 
    }

    int spaceOut = -1;
    sf::Clock gameClock;
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
        for (int i = 0; i < spaceOut && i <10; i++) {
            window.draw(moles[i]);
            moles[i].update();
        }
        window.display();
        
        spaceOut= gameClock.getElapsedTime().asSeconds()-1;
    }
}