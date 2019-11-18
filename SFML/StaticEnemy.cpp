//
//  StaticEnemy.cpp
//  SFML
//
//  Created by ZEMIN on 13/11/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

StaticEnemy::StaticEnemy()
{
    isAwake = false;
}

StaticEnemy::StaticEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind) : ObstacleEnemy(x, y, length, height, texture, numHorizontal, numVertical, _kind)
{
    isAwake = false;
}

void StaticEnemy::Update(Level &level)
{
    if (level.GetHeartLeft() <= 1)
    {
        isAwake = false;
    }
}
