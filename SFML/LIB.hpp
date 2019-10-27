//
//  LIB.hpp
//  SFML
//
//  Created by ZEMIN on 24/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#ifndef LIB_hpp
#define LIB_hpp

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Element.hpp"
#include "ObstacleEnemy.hpp"
#include "Trigger.hpp"
#include "Movable.hpp"
#include "MovableEnemy.hpp"
#include "Projectile.hpp"
#include "Collectable.hpp"
#include "Creature.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Level.hpp"
#include "GameMenu.hpp"
#include "InputController.hpp"
#include "GameController.hpp"

using namespace std;

class LIB
{
public:    
    static const int LENGTH_UNIT = 48;
    static const int HEIGHT_UNIT = 48;

    static const int ANIM_PLAYER_NUM_HORIZONTAL = 10;
    static const int ANIM_PLAYER_NUM_VERTICAL = 8;

    static const int ANIM_ENEMY1_NUM_HORIZONTAL = 4;
    static const int ANIM_ENEMY1_NUM_VERTICAL = 4;
};



#endif /* LIB_hpp */
