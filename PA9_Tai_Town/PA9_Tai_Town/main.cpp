#include <SFML/Graphics.hpp>
#include<ctime>
#include"Mole.hpp"
#include<iostream>
int main(void) {
	//actual PA9 test
	//hi

    srand(static_cast<unsigned>(time(0)));

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML works!");
//    sf::CircleShape shape(100.f);
    sf::Texture moleTexture;
  //  std::cout << "Working directory: " << std::filesystem::current_path() << std::endl;
    moleTexture.loadFromFile("mole_image.png");

    std::vector<Mole> moles;

    for (int i = 0; i < 10; ++i) {
        moles.push_back(Mole(moleTexture, 1)); 
    }
  //  Mole test(moleTexture,3);

   // shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
                    

        }

        
        window.clear();
   //     window.draw(shape);
        for (int i = 0; i < 10; i++) {
            window.draw(moles[i]);
            moles[i].update();
        }
      ///  window.draw(test);
        window.display();
      //  test.update();
    }
}