//
//  Creature.cpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//
#include "LIB.hpp"

Creature::Creature()
{
    
}

Creature::Creature(int x, int y, int length, int height, sf::Texture *texture,  int numHorizontal, int numVertical, int _kind) : Element(x, y, length, height, texture, numHorizontal, numVertical, _kind)
{
    lifePoint = 5;
    isAlive = true;
    state = Forward;
}

void Creature::ScanAround(vector<Element> &obstacles, vector<Movable> &movables, vector<Collectable> &collectables, vector<Trigger> &triggers, vector<MovableEnemy> &eggs, vector<Enemy> &enemies, const float deltaTime, Level & level)
{
    for (int i = 0; i < obstacles.size(); i++)
    {
        if (DetectCollision(&obstacles[i]))
        {
            CollisionObstacle(&obstacles[i]);
        }
    }
    for (int i = 0; i < movables.size(); i++)
    {
        if (DetectCollision(&movables[i]))
        {
            CollisionMovable(&movables[i], deltaTime);
        }
    }
    
    for (int i = 0; i < eggs.size(); i++)
    {
        if (DetectCollision(&eggs[i]))
        {
            CollisionMovable(&eggs[i], deltaTime);
        }
    }
    
    for (int i = 0; i < collectables.size(); i++)
    {
        if (DetectCollision(&collectables[i]))
        {
            CollisionCollectable(&collectables[i]);
        }
    }
    
    for (int i = 0; i < triggers.size(); i++)
    {
        if (DetectCollision(&triggers[i]))
        {
            CollisionTrigger(&triggers[i], level);
        }
    }
    
    for (int i = 0; i < enemies.size(); i++)
    {
        if (DetectCollision(&enemies[i]))
        {
            CollisionEnemy(&enemies[i], level);
        }
    }
}

void Creature::CollisionEnemy(Enemy* other, Level & level)
{
        if (kind == 71)
        {
            if (abs(centerX - other->centerX) <= TRY_DISTANCE &&
                abs(centerY - other->centerY) <= TRY_DISTANCE)
                level.LoseLife();
        }
}


void Creature::CollisionTrigger(Trigger* other, Level & level)
{
    if (kind == 71 && other->GetIsTriggerActive())
    {
        // door
        if (other->kind == 61)
        {
            other->SetTrigger(true);
        }
        // key box
        else if (other->kind == 62)
        {
            other->SetTrigger(true);
            other->shape.setTexture(&level.textureOpenKeyBox);
        }
    }
}

void Creature::CollisionCollectable(Collectable *other)
{
    // player's type is 71
    if (kind == 71 && other->GetIsActive())
    {
        if (abs(centerX - other->centerX) <= TRY_DISTANCE &&
            abs(centerY - other->centerY) <= TRY_DISTANCE)
            other->SetIsCollided(true);
    }
}


void Creature::CollisionMovable(Movable *other, const float deltaTime)
{
    if (kind == 71 && state == Forward_M)
    {
        if (((centerY + HEIGHT_UNIT / 2) > (other->centerY - HEIGHT_UNIT / 2)) &&
            ((centerX - LENGTH_UNIT * FACTOR / 2) < (other->centerX + LENGTH_UNIT * FACTOR / 2)) &&
            ((centerX + LENGTH_UNIT * FACTOR / 2) > (other->centerX - LENGTH_UNIT * FACTOR / 2)) &&
            (centerY < other->centerY))
        {
            if (!other->canMove)
                canMove = false;
            other->SetCurrentDir(state - 3);
            if (other->canMove)
            {
                other->real.move(speed * dirHorizontal * deltaTime, speed * dirVertical * deltaTime);
                other->UpdatePosition();
            }
        }
    }
    else if (kind == 71 && state == Backward_M)
    {
        if (((centerY - HEIGHT_UNIT / 2) < (other->centerY + HEIGHT_UNIT / 2)) &&
            ((centerX - LENGTH_UNIT * FACTOR / 2) < (other->centerX + LENGTH_UNIT * FACTOR / 2)) &&
            ((centerX + LENGTH_UNIT * FACTOR / 2) > (other->centerX - LENGTH_UNIT * FACTOR / 2)) &&
            (centerY > other->centerY))
        {
            if (!other->canMove)
            canMove = false;
            other->SetCurrentDir(state - 3);
            if (other->canMove)
            {
                other->real.move(speed * dirHorizontal * deltaTime, speed * dirVertical * deltaTime);
                other->UpdatePosition();
            }
        }
    }
    else if (kind == 71 && state == Leftward_M)
    {
        if (((centerX - LENGTH_UNIT / 2) < (other->centerX + LENGTH_UNIT / 2)) &&
            ((centerY - HEIGHT_UNIT * FACTOR / 2) < (other->centerY + HEIGHT_UNIT * FACTOR / 2)) &&
            ((centerY + HEIGHT_UNIT * FACTOR / 2) > (other->centerY - HEIGHT_UNIT * FACTOR / 2)) &&
            (centerX > other->centerX))
        {
            if (!other->canMove)
            canMove = false;
            
            other->SetCurrentDir(state - 3);
            if (other->canMove)
            {
                other->real.move(speed * dirHorizontal * deltaTime, speed * dirVertical * deltaTime);
                other->UpdatePosition();
            }
        }
    }
    else if (kind == 71 && state == Rightward_M)
    {
        if (((centerX + LENGTH_UNIT / 2) > (other->centerX - LENGTH_UNIT / 2)) &&
            ((centerY - HEIGHT_UNIT * FACTOR / 2) < (other->centerY + HEIGHT_UNIT * FACTOR / 2)) &&
            ((centerY + HEIGHT_UNIT * FACTOR / 2) > (other->centerY - HEIGHT_UNIT * FACTOR / 2)) &&
            (centerX < other->centerX))
        {
            if (!other->canMove)
            canMove = false;
            
            other->SetCurrentDir(state - 3);
            if (other->canMove)
            {
                other->real.move(speed * dirHorizontal * deltaTime, speed * dirVertical * deltaTime);
                other->UpdatePosition();
            }
        }
    }
    
}

void Creature::CollisionObstacle(Element *other)
{
    if (state == Forward_M)
    {
        if (((centerY + HEIGHT_UNIT / 2) > (other->centerY - HEIGHT_UNIT / 2)) &&
            ((centerX - LENGTH_UNIT * FACTOR / 2) < (other->centerX + LENGTH_UNIT * FACTOR / 2)) &&
            ((centerX + LENGTH_UNIT * FACTOR / 2) > (other->centerX - LENGTH_UNIT * FACTOR / 2)) &&
            (centerY < other->centerY))
        {
            canMove = false;
        }
    }
    else if (state == Backward_M)
    {
        if (((centerY - HEIGHT_UNIT / 2) < (other->centerY + HEIGHT_UNIT / 2)) &&
            ((centerX - LENGTH_UNIT * FACTOR / 2) < (other->centerX + LENGTH_UNIT * FACTOR / 2)) &&
            ((centerX + LENGTH_UNIT * FACTOR / 2) > (other->centerX - LENGTH_UNIT * FACTOR / 2)) &&
            (centerY > other->centerY))
        {
            canMove = false;
        }
    }
    else if (state == Leftward_M)
    {
        if (((centerX - LENGTH_UNIT / 2) < (other->centerX + LENGTH_UNIT / 2)) &&
            ((centerY - HEIGHT_UNIT * FACTOR / 2) < (other->centerY + HEIGHT_UNIT * FACTOR / 2)) &&
            ((centerY + HEIGHT_UNIT * FACTOR / 2) > (other->centerY - HEIGHT_UNIT * FACTOR / 2)) &&
            (centerX > other->centerX))
        {
            canMove = false;
        }
    }
    else if (state == Rightward_M)
    {
        if (((centerX + LENGTH_UNIT / 2) > (other->centerX - LENGTH_UNIT / 2)) &&
            ((centerY - HEIGHT_UNIT * FACTOR / 2) < (other->centerY + HEIGHT_UNIT * FACTOR / 2)) &&
            ((centerY + HEIGHT_UNIT * FACTOR / 2) > (other->centerY - HEIGHT_UNIT * FACTOR / 2)) &&
            (centerX < other->centerX))
        {
            canMove = false;
        }
    }
}


void Creature::UpdateMoveAnimation(int forwardAnimRow, int forwardAnimCol, int backwardAnimRow, int backwardAnimCol, int leftwardAnimRow, int leftwardAnimCol, int rightwardAnimRow, int rightwardAnimCol)
{
    switch (state) {
        case Forward_M:
        {
            spritePos.top = animUnitHeight * (forwardAnimRow - 1);
            if (spritePos.left < animUnitLength * (forwardAnimCol - 1))
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case Backward_M:
        {
            spritePos.top = animUnitHeight * (backwardAnimRow - 1);
            if (spritePos.left < animUnitLength * (backwardAnimCol - 1))
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case Leftward_M:
        {
            spritePos.top = animUnitHeight * (leftwardAnimRow - 1);
            if (spritePos.left < animUnitLength * (leftwardAnimCol - 1))
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case Rightward_M:
        {
            spritePos.top = animUnitHeight * (rightwardAnimRow - 1);
            if (spritePos.left < animUnitLength * (rightwardAnimCol - 1))
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        default:
            break;
    }
}


void Creature::UpdateIdleAnimation(int forwardAnimRow, int forwardAnimCol, int backwardAnimRow, int backwardAnimCol, int leftwardAnimRow, int leftwardAnimCol, int rightwardAnimRow, int rightwardAnimCol)
{
    switch (state) {
        case Forward:
        {
            spritePos.top = animUnitHeight * (forwardAnimRow - 1);
            if (spritePos.left < animUnitLength * (forwardAnimCol - 1))
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case Backward:
        {
            spritePos.top = animUnitHeight * (backwardAnimRow - 1);
            if (spritePos.left < animUnitLength * (backwardAnimCol - 1))
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case Leftward:
        {
            spritePos.top = animUnitHeight * (leftwardAnimRow - 1);
            if (spritePos.left < animUnitLength * (leftwardAnimCol - 1))
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case Rightward:
        {
            spritePos.top = animUnitHeight * (rightwardAnimRow - 1);
            if (spritePos.left < animUnitLength * (rightwardAnimCol - 1))
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        default:
            break;
    }
}

void Creature::Move(const float deltaTime)
{
    if (canMove)
    {
        real.move(speed * dirHorizontal * deltaTime, speed * dirVertical * deltaTime);
        UpdatePosition();
        
            
        
    }
}
