//
//  State.cpp
//  SFML
//
//  Created by ZEMIN on 10/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "State.hpp"

State::State(sf::RenderWindow* window)
{
    this->window = window;
    this->quit = false;
}

State::~State()
{
    
}

GameState::GameState(sf::RenderWindow* window) :
    State(window)
{
    
}

GameState::~GameState()
{
     
}



const bool& State::GetQuit() const
{
    return (this->quit);
}

void State::CheckForQuit()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->quit = true;
    }
}

void GameState::EndState()
{
    std::cout << "\n!!! End Game !!!\n";
}

void GameState::UpdateKeyBinds(const float &dt)
{
    this->CheckForQuit();
}

void GameState::Update(const float &dt)
{
    this->UpdateKeyBinds(dt);
    
    this->player.Update(dt);
}

void GameState::Render(sf::RenderTarget* target)
{
    this->player.Render(target);
}

