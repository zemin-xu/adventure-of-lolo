//
//  State.cpp
//  SFML
//
//  Created by ZEMIN on 10/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "State.hpp"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
{
    this->window = window;
    this->supportedKeys = supportedKeys;
    this->quit = false;
}

State::~State()
{
    
}
void GameState::InitKeybinds()
{
    this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("A"));
    this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("D"));
    this->keybinds.emplace("MOVE_UP", this->supportedKeys->at("W"));
    this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("S"));
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys)
{
    this->InitKeybinds();
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

void GameState::UpdateInput(const float &dt)
{
    this->CheckForQuit();
    
    // Update player input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->player.Move(dt, -1.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->player.Move(dt, 1.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
        this->player.Move(dt, 0.0f, -1.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
        this->player.Move(dt, 0.0f, 1.0f);
     
  
    
}

void GameState::Update(const float &dt)
{
    this->UpdateInput(dt);
    
    this->player.Update(dt);
}

void GameState::Render(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;
    
    this->player.Render(target);
    
}

