#include "Test.hpp"

void test::testEasy()
{
    sf::Texture texture; 
    Mole mole(texture, sf::Vector2f(100, 100), 1);
    mole.show();
    if (mole.getIsVisible() >= 0.8f && mole.getIsVisible() <= 1.5f)
    {
        std::cout << "Easy works visible duration is correct" << std::endl;
    }
    else
    {
        std::cout << "Easy does not work visible duration is incorrect" << std::endl;
    }
}

void test::testMedium()
{
    sf::Texture texture;
    Mole mole(texture, sf::Vector2f(100, 100), 1);
    mole.show();
    if (mole.getIsVisible() >= 0.4f && mole.getIsVisible() <= 1.1f)
    {
        std::cout << "Medium works visible duration is correct" << std::endl;
    }
    else
    {
        std::cout << "Medium does not work visible duration is incorrect" << std::endl;
    }
}

void test::testHard()
{
    sf::Texture texture;
    Mole mole(texture, sf::Vector2f(100, 100), 1);
    mole.show();
    if (mole.getIsVisible() >= 0.0f && mole.getIsVisible() <= 0.7f)
    {
        std::cout << "Hard works visible duration is correct" << std::endl;
    }
    else
    {
        std::cout << "Hard does not work visible duration is incorrect" << std::endl;
    }
}

void test::testShow()
{
    sf::Texture texture;
    Mole mole(texture, sf::Vector2f(100, 100), 1);
    mole.show();
    if (mole.getIsVisible())
    {
        std::cout << "Mole is visible" << std::endl;
    }
    else
    {
        std::cout << "Mole is not visible" << std::endl;
    }
}

void test::testHide()
{
    sf::Texture texture;
    Mole mole(texture, sf::Vector2f(100, 100), 1);
    mole.show();
    mole.hide(); 
    if (!mole.getIsVisible())
    {
        std::cout << "Mole is visible" << std::endl;
    }
    else
    {
        std::cout << "Mole is not visible" << std::endl;
    }
}