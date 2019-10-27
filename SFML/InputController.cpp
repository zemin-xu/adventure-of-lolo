//
//  InputController.cpp
//  SFML
//
//  Created by ZEMIN on 25/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"
InputController::InputController()
{
    
}

void InputController::UpdateInput(Player &player)
{
  
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            player.state = Creature::Backward_M;
            /*
            if (player.playerStep.getStatus() != sf::Sound::Status::Playing)
            {
                player.playerStep.play();
            }
             */
              
        }
                
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                player.state = Creature::Forward_M;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                player.state = Creature::Leftward_M;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                player.state = Creature::Rightward_M;
        
}
    
