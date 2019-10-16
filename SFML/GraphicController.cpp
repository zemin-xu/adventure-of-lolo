//
//  GraphicController.cpp
//  SFML
//
//  Created by ZEMIN on 15/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "GraphicController.hpp"
#include "GameController.hpp"

GraphicController::GraphicController() 
{
    ReadTextureFile();
    for (int i = 0 ; i < GameController::LENGTH / LENGTH_UNIT; i++)
    {
        for (int j = 0 ; j < GameController::HEIGHT/HEIGHT_UNIT; j++)
        {
            // create background
            Element backgroundUnit(i * LENGTH_UNIT, j * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureBG, 1, 1, false);
            elements.push_back(backgroundUnit);
            
            // create obstacle
            if((i == 0 || i == 3 || i == GameController::LENGTH / LENGTH_UNIT - 1 || j == 0 || j == 3 || j == GameController::HEIGHT/HEIGHT_UNIT - 1))
            {
                Element obstacleUnit(i * LENGTH_UNIT, j * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureObstacle,1,1, true);
               
                elements.push_back(obstacleUnit);
            }
        }
    }
    player = Player(0,0,LENGTH_UNIT, HEIGHT_UNIT, &texturePlayer, ANIM_PLAYER_NUM_HORIZONTAL, ANIM_PLAYER_NUM_VERTICAL, true);
    //elements.push_back(player);
    
}

void GraphicController::ReadTextureFile()
{
    if (!texturePlayer.loadFromFile("Sources/player.png"))
        return ;
    if (!textureEnemy.loadFromFile("Sources/player.png"))
        return ;
    if (!textureBG.loadFromFile("Sources/sable.jpg"))
        return ;
    if (!textureObstacle.loadFromFile("Sources/obstacle.png"))
        return ;
    if (!textureCollectable.loadFromFile("Sources/obstacle.png"))
        return ;
}

void GraphicController::Update(const float deltaTime)
{
    player.Update(deltaTime);
}


void GraphicController::Render(sf::RenderWindow &window)
{
    for (int i = 0; i < elements.size(); i++)
    {
        elements[i].Render(window);
    }
    player.UpdateAnimation();
    player.UpdateState();
    player.Render(window);
    
    
}

InputController::InputController()
{
    
}

void InputController::UpdateInput(Player &player)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        player.state = Player::Backward_M;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        player.state = Player::Forward_M;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        player.state = Player::Leftward_M;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        player.state = Player::Rightward_M;
}
