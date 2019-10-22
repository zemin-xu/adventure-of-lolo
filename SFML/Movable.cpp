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

Movable::Movable(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind) : Element(x, y, length, height, texture, numHorizontal, numVertical, _kind)
{
    currentDir = 0;
}

int Movable::GetCurrentDir()
{
    return (currentDir);
}

void Movable::SetCurrentDir(int _currentDir)
{
    currentDir = _currentDir;
}
