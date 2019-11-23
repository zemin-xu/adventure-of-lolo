//
//  InputController.cpp
//  SFML
//
//  Created by ZEMIN on 25/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

// Control the input of player

#include "LIB.hpp"
InputController::InputController()
{
    
}

void InputController::UpdateInput(Level &level)
{
    if (!level.GetHasLost())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            level.player.state = Creature::Backward_M;
            /*
             if (player.playerStep.getStatus() != sf::Sound::Status::Playing)
             {
             player.playerStep.play();
             }
             */
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            level.player.state = Creature::Forward_M;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            level.player.state = Creature::Leftward_M;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            level.player.state = Creature::Rightward_M;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
        {
            level.player.Fire(level, level.playerProjectile);
        }
    }
    
    
}

