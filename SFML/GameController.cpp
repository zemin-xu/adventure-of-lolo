//
//  GameController.cpp
//  SFML
//
//  Created by ZEMIN on 14/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "GameController.hpp"

GameController::GameController() : window(sf::VideoMode(LENGTH, HEIGHT), "C++ Game"), graphicController(), inputController()
{
    window.setFramerateLimit(120);
}




void GameController::EndApplication()
{
    cout << "\n !!!Ending Application!!! \n";
}

// update the 'deltaTime' with the time it takes to update and render one frame
void GameController::UpdateDeltaTime()
{
    deltaTime = deltaTimeClock.getElapsedTime().asSeconds();
    if (deltaTime > 0.1f)
    {
        deltaTime = deltaTimeClock.restart().asSeconds();
        
        Render();
        
    }
        
}

void GameController::UpdateSFMLEvents()
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        window.close();
    }
}

void GameController::Update()
{
    UpdateSFMLEvents();
    inputController.UpdateInput(graphicController.player);
    graphicController.Update();
    
    UpdateDeltaTime();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        EndApplication();
        window.close();
    }
}

// execute nearest state's render functions
void GameController::Render()
{
    window.clear();
    
    graphicController.Render(window);
    
    window.display();
}

void GameController::Run()
{
    //the code to be execute all along the program
    graphicController.ReadTextureFile();
    
    while (window.isOpen())
    {
        Update();
    }
}
