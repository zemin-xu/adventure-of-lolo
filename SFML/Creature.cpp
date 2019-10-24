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

void Creature::ScanAround(vector<Element> &obstacles, vector<Movable> &movables, vector<Collectable> &collectables, const float deltaTime)
{
    for (int i = 0; i < obstacles.size(); i++)
    {
        if (DetectCollision(&obstacles[i]))
        {
            CollisionObstacle(&obstacles[i]);
            obstacles[i].shape.setFillColor(sf::Color::Red);
        }
    }
    for (int i = 0; i < movables.size(); i++)
    {
        if (DetectCollision(&movables[i]))
        {
            CollisionMovable(&movables[i], deltaTime);
            movables[i].shape.setFillColor(sf::Color::Black);
        }
    }
    
    for (int i = 0; i < collectables.size(); i++)
    {
        if (DetectCollision(&collectables[i]))
        {
            CollisionCollectable(&collectables[i]);
        }
    }
}

void Creature::CollisionCollectable(Collectable *other)
{
    // player's type is 71
    if (kind == 71 && other->GetIsActive())
        other->SetIsCollided(true);
}


void Creature::CollisionMovable(Movable *other, const float deltaTime)
{
    if (state == Forward_M)
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
    else if (state == Backward_M)
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
    else if (state == Leftward_M)
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
    else if (state == Rightward_M)
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

void Creature::Damage(Creature &other, int damage)
{
    other.lifePoint -= damage;
    if (other.lifePoint <= 0)
        other.isAlive = false;
}

// the corresponding changement because of the changement of state of a creature
void Creature::UpdateVariable()
{
    switch (state) {
        case Forward:
        case Backward:
        case Leftward:
        case Rightward:
            canMove = false;
            break;
            
        case Forward_M:
        {
            dirHorizontal = 0;
            dirVertical = 1;
            canMove = true;
        }
            break;
        case Backward_M:
        {
            dirHorizontal = 0;
            dirVertical = -1;
            canMove = true;
        }
            break;
        case Leftward_M:
        {
            dirHorizontal = -1;
            dirVertical = 0;
            canMove = true;
        }
            break;
        case Rightward_M:
        {
            dirHorizontal = 1;
            dirVertical = 0;
            canMove = true;
        }
            break;
            
        default:
            break;
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
