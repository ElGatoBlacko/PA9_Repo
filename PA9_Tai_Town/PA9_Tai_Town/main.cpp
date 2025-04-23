/*
    Programmers: Arie Tai and Emery Town
    Class: CptS 122, Spring 2025; Lab Section 7 and Lab Section 10
    Programming Assignment: PA 9
    Date: April 22, 2025
    Description: This is the main for our whack-a-mole game
*/
#include <SFML/Graphics.hpp>
#include<ctime>
#include"Mole.hpp"
#include<iostream>
#include<sstream>
#include<fstream>
#include"Menu.hpp"
#include"ScoreRecord.hpp"
#include "Test.hpp"

//number of moles
const int MOLE_NUM = 10;

//enum representing state of the game
enum class GameState {
    Menu,
    Playing,
    Score,
    Records,
    Description
};

int main(void) {

    //runs test cases and prints to console
    Test tester;
    tester.testEasy();
    tester.testMedium();
    tester.testHard();
    tester.testHide();
    tester.testShow();

    //setting the seed for randomization
    srand(static_cast<unsigned>(time(0)));

    //create the window object
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "We Love You Andy <3");

    //base texture for mole and font for text
    sf::Texture moleTexture;
    sf::Font font;

    //load mole and font from files
    moleTexture.loadFromFile("mole_image.png");
    font.openFromFile("WinkyRough-VariableFont_wght.ttf");

    //open in stream for high scores and import to object
    std::ifstream in("HighScores.txt");
    ScoreRecord scores;
    scores.import(in);

    
    //create game clock for tracking time
    sf::Clock gameClock;
    std::string time = "";

    //variables for tracking current hits, difficulty level, and time/score
    int hitCount = 0, difficulty=0;
    float curScore = 0.0;
    
    //text for displaying time
    sf::Text runtime(font, time, 30);
    runtime.setFillColor(sf::Color::White);
    runtime.setPosition(sf::Vector2f(0, 0));

   //vector to store all 10 mole objects
    std::vector<Mole> moles;

    //create the menu
    Menu menu(font);

    //add all 10 moles into vector
    for (int i = 0; i < MOLE_NUM; i++) {
        moles.push_back(Mole(moleTexture, 1)); 
    }

    //variable for smooth introduction of moles
    int spaceOut = 0;

    //set initial gamestate to menu
    GameState current = GameState::Menu;
    
    //game loop
    while (window.isOpen())
    {
        
        //checking for event loop
        while (const std::optional event = window.pollEvent())
        {
            //if close button hit, export new high scores and close window
            if (event->is<sf::Event::Closed>()) {
                std::ofstream out("HighScores.txt");
                scores.exportScores(out);
                out.close();
                window.close();
            }
            
            //if current state is menu 
            if (current == GameState::Menu) {
                
                //if mouse is clicked
                if (event->is<sf::Event::MouseButtonPressed>()) {
                    //mouse position when clicked
                    sf::Vector2f pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    //depending on button pressed set appropriate difficulty and game state, restart clock if entering game
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
                    else if (menu.getDescriptionBounds().contains(pos)) {
                        current = GameState::Description;
                    }
                    //re initialize each mole to correct difficulty
                    for (int i = 0; i < MOLE_NUM; i++) {
                        moles[i].initialize(difficulty);
                    }
                }
            }
            //if game state is playing
            else if (current == GameState::Playing) {
                //if mouse is clicked check if it hit any moles and hide them accordingly
                if (event->is<sf::Event::MouseButtonPressed>()) {
                    for (int i = 0; i < MOLE_NUM; ++i) {
                        if (moles[i].isHit(*event, window)) {
                            moles[i].hide();
                            moles[i].setHitState(true);
                        }
                    }
                }
            }
            //if game state is score, records, or description 
            else if (current == GameState::Score || current == GameState::Records || current == GameState::Description) {
                //if any button is pressed reset clock to corner and set state to menu
                if (event->is<sf::Event::KeyPressed>()) {
                    runtime.setPosition(sf::Vector2f(0, 0));
                    runtime.setCharacterSize(30);
                    current = GameState::Menu;
                }
            }
        }

        //clear window before each frame
        window.clear();

        //if game state is menu draw the menu
        if (current == GameState::Menu) {
            menu.draw(window);

        }
        //if game state is playing
        else if (current == GameState::Playing) {
            //check how many moles are hit
            for (int i = 0; i < MOLE_NUM; i++) {
                if (moles[i].getHitState()) {
                    hitCount++;
                }
                else {
                    hitCount = 0;
                }
            }
            //if not all moles are hit update clock
            if (hitCount < MOLE_NUM) {
                std::stringstream stream;
                curScore = gameClock.getElapsedTime().asSeconds();
                stream << std::fixed << std::setprecision(2) <<curScore;
                time = stream.str();
                runtime.setString(time);
            }
            //if all mole are hit switch game state to score screen
            else {
                current = GameState::Score;
            }

            //introduce 2 moles per second for the first 10 seconds
            for (int i = 0; i < spaceOut && i < MOLE_NUM; i++) {
                window.draw(moles[i]);
                moles[i].update();
            }
            //draw clock
            window.draw(runtime);

            
            //update space out variable based on time
            spaceOut = gameClock.getElapsedTime().asSeconds()*2;
        }
        //if game state is score 
        else if (current == GameState::Score) {
            //round time to 2 decimals
            curScore = std::round(curScore*100)/100;

            //update high score of correct game mode
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
            
            //display score after round
            sf::Text displayMessage(font, "Score:", 60);
            displayMessage.setPosition(sf::Vector2f(250, 250));
            displayMessage.setFillColor(sf::Color::White);

            runtime.setPosition(sf::Vector2f(405, 250));
            runtime.setCharacterSize(60);


            sf::Text returnPrompt(font, "(Press any key to return to menu)", 30);

            returnPrompt.setPosition(sf::Vector2f(175, 350));
            returnPrompt.setFillColor(sf::Color::White);

            window.draw(displayMessage);
            window.draw(runtime);
            window.draw(returnPrompt);
        }
        //if game state is records
        else if (current == GameState::Records) {
            //display easy medium and hard high scores
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
        //if game state is description
        else if (current == GameState::Description) {
            //instructions/description of game
            std::string message = "Welcome to Whack-A-Mole!\nOur game is a fresh take on the "
                "classic carnival game you all know and\nlove :) Instead of the normal grid of "
                "moles holes, these pesky buggers\ncan pop up anywhere on the screen! The "
                "objective has changed slightly too!\nInstead of racking up points-per-whack "
                "in a set amount of time on the\nsame few moles, your goal is now to eliminate "
                "all ten of the pesky critters\nas quick as you can. Once you click a mole its "
                "out for the count and won't\npop up again. The timer stops counting up when you "
                "whack the last mole.\nChoose your prefered difficulty from the beginner friendly "
                "easy mode, up to\nthe neck-breakingly fast hard mode and try to set the high "
                "score for each!\nThat's all, get to whacking!";
            sf::Text displayMessage(font, message, 25);
            displayMessage.setPosition(sf::Vector2f(10, 40));
            displayMessage.setFillColor(sf::Color::White);

            sf::Text returnPrompt(font, "(Press any key to return to menu)", 20);
            returnPrompt.setPosition(sf::Vector2f(250, 550));
            returnPrompt.setFillColor(sf::Color::White);

            window.draw(displayMessage);
            window.draw(returnPrompt);
        }
        //display each frame
        window.display();
        
    }
    //close file instream 
    in.close();
    return 0;
}