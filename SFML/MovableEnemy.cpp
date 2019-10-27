//
//  MovableEnemy.cpp
//  SFML
//
//  Created by ZEMIN on 25/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

MovableEnemy::MovableEnemy()
{
    
}

MovableEnemy::MovableEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind) : Movable(x, y, length, height, texture, numHorizontal, numVertical, _kind)
{

}

void MovableEnemy::Update(Element *player)
{
    cout << "egg update";
}
