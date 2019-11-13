//
//  Projectile.cpp
//  SFML
//
//  Created by ZEMIN on 27/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

Projectile::Projectile()
{
    
}

Projectile::Projectile(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind) : Movable(x, y, length, height, texture, numHorizontal, numVertical, _kind)
{
    speed = 500.0f;
    isUsing = false;
}

void Projectile::Disappear()
{
    isUsing = false;
}

void Projectile::Update(const float deltaTime, vector<Element> &obstacles, vector<Enemy> &enemies, vector<MovableEnemy> &eggs, Level &level)
{
    // the projectile of player
    if (isUsing)
    {
        UpdatePosition();
        if (GetCurrentDir() == 1)
            real.move(speed * deltaTime * 0, speed * deltaTime * 1);
        else if (GetCurrentDir() == 2)
            real.move(speed * deltaTime * 0, speed * deltaTime * -1);
        else if (GetCurrentDir() == 3)
            real.move(speed * deltaTime * -1, speed * deltaTime * 0);
        else if (GetCurrentDir() == 4)
            real.move(speed * deltaTime * 1, speed * deltaTime * 0);
        for (int i = 0 ; i < obstacles.size(); i++)
        {
            if (obstacles[i].kind == 26 && DetectCollision(&obstacles[i]))
            {
                Collision(&obstacles[i]);
                if (canMove == false)
                {
                    Disappear();
                    MovableEnemy egg(obstacles[i].centerX - LIB::LENGTH_UNIT / 2, obstacles[i].centerY - LIB::LENGTH_UNIT / 2, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &level.textureEgg, 1, 1, 22, 26);
                    obstacles.erase(obstacles.begin() + i);
                    eggs.push_back(egg);
                    return ;
                }
                   
            }
        }
        
        if (centerX < 0 || centerX > GameController::LENGTH ||
            centerY < 0 || centerY > GameController::HEIGHT)
            Disappear();
    }
}
