//
//  InputController.cpp
//  SFML
//
//  Created by ZEMIN on 25/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

/* Control the input of player */

#include "LIB.hpp"
InputController::InputController()
{
    
}

void InputController::UpdateInput(Level &level)
{
    if (!level.GetHasLost())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            level.player.state = Creature::Backward_M;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            level.player.state = Creature::Forward_M;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            level.player.state = Creature::Leftward_M;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            level.player.state = Creature::Rightward_M;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
            level.player.Fire(level, level.playerProjectile);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
    level.RestartGame();
}

