//
//  Game.cpp
//  SFML
//
//  Created by ZEMIN on 10/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "Game.hpp"


void Game::InitWindow()
{
    std::ifstream ifs("Sources/window.init");
    
    std::string title = "None";
    sf::VideoMode window_boundary(800,600);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;
    
    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_boundary.width >> window_boundary.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }
    ifs.close();
    
    this->window = new sf::RenderWindow(window_boundary, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void    Game::InitStates()
{
    this->states.push(new GameState(this->window));
}

Game::Game()
{
    this->InitWindow();
    this->InitStates();
}
Game::~Game()
{
    delete (this->window);
    
    while(!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
        
}


void Game::EndApplication()
{
    std::cout << "\n !!!Ending Application!!! \n";
}

/* update the 'deltaTime' with the time it takes to update and render one frame */
void Game::UpdateDeltaTime()
{
    this->deltaTime = this ->deltaTimeClock.restart().asSeconds();
}

void Game::UpdateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::Update()
{
    this->UpdateSFMLEvents();
    
    if (!this->states.empty())
    {
        this->states.top()->Update(this->deltaTime);
        
        if (this->states.top()->GetQuit())
        {
            this->states.top()->EndState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else
    {
        this->EndApplication();
        this->window->close();
    }
        
}

void Game::Render()
{
    this->window->clear();
    
    if(!this->states.empty())
        this->states.top()->Render();
    
    this->window->display();
}

void Game::Run()
{
    while (this->window->isOpen())
    {
        this->UpdateDeltaTime();
        this->Update();
        this->Render();
    }
}
