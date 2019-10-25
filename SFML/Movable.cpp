//
//  Movable.cpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

Movable::Movable()
{
    
}

Movable::Movable(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind) : Element(x, y, length, height, texture, numHorizontal, numVertical, _kind)
{
    SetCurrentDir(0);
    canMove = true;
}


void Movable::Collision(Element *other)
{
    
    if (GetCurrentDir() == 1)
    {
        if (((centerY + HEIGHT_UNIT / 2) > (other->centerY - HEIGHT_UNIT / 2)) &&
            ((centerX - LENGTH_UNIT * FACTOR / 2) < (other->centerX + LENGTH_UNIT * FACTOR / 2)) &&
            ((centerX + LENGTH_UNIT * FACTOR / 2) > (other->centerX - LENGTH_UNIT * FACTOR / 2)) &&
            (centerY < other->centerY))
        {
            canMove = false;
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
        }
    }
}
