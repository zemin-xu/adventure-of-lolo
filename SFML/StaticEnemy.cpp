//
//  StaticEnemy.cpp
//  SFML
//
//  Created by ZEMIN on 22/11/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"


StaticEnemy::StaticEnemy()
{

}

StaticEnemy::StaticEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind) : ObstacleEnemy(x, y, length, height, texture, numHorizontal, numVertical, _kind)
{

}

void StaticEnemy::Update(Element *player, const float deltaTime)
{
    ObstacleEnemy::Update(player, deltaTime);
    
}
