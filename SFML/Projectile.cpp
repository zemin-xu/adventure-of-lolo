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

void Projectile::CollisionObstacle(Element *other)
{
    if (GetCurrentDir() == 1)
    {
        if (((centerY + HEIGHT_UNIT / 2) > (other->centerY - HEIGHT_UNIT / 2)) &&
            ((centerX - LENGTH_UNIT * FACTOR / 2) < (other->centerX + LENGTH_UNIT * FACTOR / 2)) &&
            ((centerX + LENGTH_UNIT * FACTOR / 2) > (other->centerX - LENGTH_UNIT * FACTOR / 2)) &&
            (centerY < other->centerY))
        {
            canMove = false;
            Disappear();
        }
    }
    else if (GetCurrentDir() == 2)
    {
        if (((centerY - HEIGHT_UNIT / 2) < (other->centerY + HEIGHT_UNIT / 2)) &&
            ((centerX - LENGTH_UNIT * FACTOR / 2) < (other->centerX + LENGTH_UNIT * FACTOR / 2)) &&
            ((centerX + LENGTH_UNIT * FACTOR / 2) > (other->centerX - LENGTH_UNIT * FACTOR / 2)) &&
            (centerY > other->centerY))
        {
            canMove = false;
            Disappear();
        }
    }
    else if (GetCurrentDir() == 3)
    {
        if (((centerX - LENGTH_UNIT / 2) < (other->centerX + LENGTH_UNIT / 2)) &&
            ((centerY - HEIGHT_UNIT * FACTOR / 2) < (other->centerY + HEIGHT_UNIT * FACTOR / 2)) &&
            ((centerY + HEIGHT_UNIT * FACTOR / 2) > (other->centerY - HEIGHT_UNIT * FACTOR / 2)) &&
            (centerX > other->centerX))
        {
            canMove = false;
            Disappear();
        }
    }
    else if (GetCurrentDir() == 4)
    {
        if (((centerX + LENGTH_UNIT / 2) > (other->centerX - LENGTH_UNIT / 2)) &&
            ((centerY - HEIGHT_UNIT * FACTOR / 2) < (other->centerY + HEIGHT_UNIT * FACTOR / 2)) &&
            ((centerY + HEIGHT_UNIT * FACTOR / 2) > (other->centerY - HEIGHT_UNIT * FACTOR / 2)) &&
            (centerX < other->centerX))
        {
            canMove = false;
            Disappear();
        }
    }
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
        if (kind == 32)
        {
            for (int i = 0 ; i < obstacles.size(); i++)
            {
                if (DetectCollision(&obstacles[i]))
                {
                    if (obstacles[i].kind == 26 || obstacles[i].kind == 27 || obstacles[i].kind == 28)
                    {
                        Collision(&obstacles[i]);
                        if (canMove == false)
                        {
                            Disappear();
                            MovableEnemy egg(obstacles[i].centerX - LIB::LENGTH_UNIT / 2, obstacles[i].centerY - LIB::LENGTH_UNIT / 2, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &level.textureEgg, 1, 1, 22, obstacles[i].kind);
                            obstacles.erase(obstacles.begin() + i);
                            eggs.push_back(egg);
                            return ;
                        }
                    }
                }
            }
            for (int i = 0; i < enemies.size(); i++)
            {
                if (DetectCollision(&enemies[i]))
                {
                    Collision(&enemies[i]);
                    if (canMove == false)
                    {
                        Disappear();
                        MovableEnemy egg(enemies[i].centerX - LIB::LENGTH_UNIT / 2, enemies[i].centerY - LIB::LENGTH_UNIT / 2, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &level.textureEgg, 1, 1, 22, enemies[i].kind);
                        enemies.erase(enemies.begin() + i);
                        eggs.push_back(egg);
                        return ;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < level.obstacles.size(); i++)
            {
                if (DetectCollision(&level.obstacles[i]))
                {
                    CollisionObstacle(&level.obstacles[i]);
                }
                
            }
            for (int i = 0; i < level.movables.size(); i++)
            {
                if (DetectCollision(&level.movables[i]))
                {
                    CollisionObstacle(&level.movables[i]);
                }
            }
            
            if (DetectCollision(&level.player))
            {
                Collision(&level.player);
                if (canMove == false)
                {
                    Disappear();
                    level.LoseLife();
                    return ;
                }
            }
        }
        
        if (centerX < 0 || centerX > GameController::LENGTH ||
            centerY < 0 || centerY > GameController::HEIGHT)
            Disappear();
    }
}
