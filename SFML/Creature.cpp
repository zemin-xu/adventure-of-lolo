//
//  Creature.cpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "Creature.hpp"

Creature::Creature()
{
    
}

Creature::Creature(int x, int y, int length, int height, sf::Texture *texture,  int numHorizontal, int numVertical, bool _isRigidbody) : Element(x, y, length, height, texture, numHorizontal, numVertical, _isRigidbody)
{
    lifePoint = 5;
    isAlive = true;
    state = Forward;
}

// detect if there is obstacle
void Creature::DetectObsCollision(Map map)
{
    if (canMove)
    {
        // the 16.0f here is a defaut value to avoid intersect situation
        // there is a little bug : when player push rightward an movable, it will get himself in
        if (state == Forward_M)
        {
            // meet obstacle
            int a = map.level[(int)(y2/HEIGHT_UNIT)][(int)((x1 + 16.0f)/LENGTH_UNIT)];
            int b = map.level[(int)(y2/HEIGHT_UNIT)][(int)((x2 - 16.0f)/LENGTH_UNIT)];
            if ((a / 10) != 2 && ( b / 10) != 2)
               canMove = true;
            else
                canMove = false;
        }
        
        else if (state == Backward_M)
        {
            int a =map.level[(int)(y1/HEIGHT_UNIT)][(int)((x1 + 16.0f)/LENGTH_UNIT)];
            int b =map.level[(int)(y1/HEIGHT_UNIT)][(int)((x2 - 16.0f)/LENGTH_UNIT)];
            if ((a / 10) != 2 && ( b / 10) != 2)
                canMove = true;
            else
                canMove = false;
        }
        else if (state == Leftward_M)
        {
            int a =map.level[(int)((y1 + 16.0f)/HEIGHT_UNIT)][(int)(x1/LENGTH_UNIT)];
            int b =map.level[(int)((y2 - 16.0f)/HEIGHT_UNIT)][(int)(x1/LENGTH_UNIT)];
            if ((a / 10) != 2 && ( b / 10) != 2)
                canMove = true;
            else
                canMove = false;
        }
        else if (state == Rightward_M)
        {
            int a =map.level[(int)((y1 + 16.0f)/HEIGHT_UNIT)][(int)(x2/LENGTH_UNIT)];
            int b = map.level[(int)((y2 - 16.0f)/HEIGHT_UNIT)][(int)(x2/LENGTH_UNIT)];
            if ((a / 10) != 2 && ( b / 10) != 2)
                canMove = true;
            else
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
