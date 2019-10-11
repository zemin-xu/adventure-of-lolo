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

const bool& State::GetQuit() const
{
    return (this->quit);
}

void State::CheckForQuit()
{
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
        this->quit = true;
   
}
void State::UpdateMousePositions()
{
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void GameState::InitKeybinds()
{
    std::ifstream ifs("Sources/gamestate_keybinds.init");
    
    if (ifs.is_open())
    {
        std::string key = "";
        std::string key_inner = "";
          
          while (ifs >> key >> key_inner)
          {
              this->keybinds[key] = this->supportedKeys->at(key_inner);
          }
    }
    ifs.close();
    
    this->keybinds["CLOSE"] =  this->supportedKeys->at("Escape");
    this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
    this->keybinds["MOVE_RIGHT"] =  this->supportedKeys->at("D");
    this->keybinds["MOVE_UP"] =  this->supportedKeys->at("W");
    this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys)
{
    this->InitKeybinds();
}

GameState::~GameState()
{
     
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

void MainMenuState::InitFonts()
{
    if(!this->font.loadFromFile("Sources/arial.ttf"))
    {
        throw("ERROR IN MAINMENUSTATE::COULD NOT LOAD FONT FILE");
    }
}

void MainMenuState::InitKeybinds()
{
    std::ifstream ifs("Sources/gamestate_keybinds.init");
    
    if (ifs.is_open())
    {
        std::string key = "";
        std::string key_inner = "";
          
          while (ifs >> key >> key_inner)
          {
              this->keybinds[key] = this->supportedKeys->at(key_inner);
          }
    }
    ifs.close();
    
    this->keybinds["CLOSE"] =  this->supportedKeys->at("Escape");
    this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
    this->keybinds["MOVE_RIGHT"] =  this->supportedKeys->at("D");
    this->keybinds["MOVE_UP"] =  this->supportedKeys->at("W");
    this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys)
{
    this->InitFonts();
    this->InitKeybinds();
    
    this->gamestate_btn = new Button(100,100,150,50,&this->font,"New Game",sf::Color(70,70,70,200), sf::Color(150,150,150,255),sf::Color(20,20,20,200));
    
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Black);
    
    std::cout << "OK!!!\n";
}

MainMenuState::~MainMenuState()
{
     
}

void MainMenuState::EndState()
{
    std::cout << "\n!!! End Game !!!\n";
}

void MainMenuState::UpdateInput(const float& dt)
{
    this->CheckForQuit();
}

void MainMenuState::Update(const float& dt)
{
    this->UpdateMousePositions();
    this->UpdateInput(dt);
    
    this->gamestate_btn->Update(this->mousePosView);
    
    
   
}

void MainMenuState::Render(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;
 
    target->draw(this->background);
    this->gamestate_btn->Render(target);
}

