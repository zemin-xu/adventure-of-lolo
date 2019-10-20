//
//  Movable.cpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "Movable.hpp"

Movable::Movable()
{
    
}

Movable::Movable(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody) : Element(x, y, length, height, texture, numHorizontal, numVertical, _isRigidbody)
{
    currentDir = 0;
}

void Movable::DetectObsCollision(Map map)
{
    if (currentDir != 0)
    {
        // the 6.0f here is a defaut value to avoid intersect situation
        if (currentDir == 1)
        {
            int a = map.level[(int)(y2/HEIGHT_UNIT)][(int)((x1 + 6.0f)/LENGTH_UNIT)];
            int b = map.level[(int)(y2/HEIGHT_UNIT)][(int)((x2 - 6.0f)/LENGTH_UNIT)];
            if ((a / 10) != 2 && ( b / 10) != 2 && (a / 10) != 4 && ( b / 10) != 4)
                currentDir = 1;
            else
                currentDir = 0;
        }
        
        else if (currentDir == 2)
        {
            int a =map.level[(int)(y1/HEIGHT_UNIT)][(int)((x1 + 6.0f)/LENGTH_UNIT)];
            int b =map.level[(int)(y1/HEIGHT_UNIT)][(int)((x2 - 6.0f)/LENGTH_UNIT)];
            if ((a / 10) != 2 && ( b / 10) != 2 && (a / 10) != 4 && ( b / 10) != 4)
                    currentDir = 2;
                else
                    currentDir = 0;
        }
        else if (currentDir == 3)
        {
            int a =map.level[(int)((y1 + 6.0f)/HEIGHT_UNIT)][(int)(x1/LENGTH_UNIT)];
            int b =map.level[(int)((y2 - 6.0f)/HEIGHT_UNIT)][(int)(x1/LENGTH_UNIT)];
            if ((a / 10) != 2 && ( b / 10) != 2 && (a / 10) != 4 && ( b / 10) != 4)
                currentDir = 3;
            else
                currentDir = 0;
        }
        else if (currentDir == 4)
        {
            int a =map.level[(int)((y1 + 6.0f)/HEIGHT_UNIT)][(int)(x2/LENGTH_UNIT)];
            int b = map.level[(int)((y2 - 6.0f)/HEIGHT_UNIT)][(int)(x2/LENGTH_UNIT)];
            if ((a / 10) != 2 && ( b / 10) != 2 && (a / 10) != 4 && ( b / 10) != 4)
                currentDir = 4;
            else
                currentDir = 0;
        }
    }
}

int Movable::GetCurrentDir()
{
    return (currentDir);
}

void Movable::SetCurrentDir(int _currentDir)
{
    currentDir = _currentDir;
}
