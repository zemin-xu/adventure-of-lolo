//
//  GameController.cpp
//  SFML
//
//  Created by ZEMIN on 14/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//
#include "LIB.hpp"

GameController::GameController() : window(sf::VideoMode(LENGTH, HEIGHT), "C++ Game"),  inputController(), level(1)
{
    window.setFramerateLimit(120);
}




void GameController::EndApplication()
{
    cout << "\n !!!Ending Application!!! \n";
}

// update the 'deltaTime' with the time it takes to update and render one frame
void GameController::UpdateTime()
{
    deltaTime = deltaTimeClock.restart().asSeconds();
    
    renderTime = renderClock.getElapsedTime().asSeconds();
    if (renderTime > 0.12f)
    {
        renderTime = renderClock.restart().asSeconds();
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
    inputController.UpdateInput(level.player);
    
    level.Update(deltaTime);
    
    UpdateTime();
    
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
    
    level.Render(window);
    
    window.display();
}

void GameController::Run()
{
    while (window.isOpen())
    {
        Update();
    }
}
