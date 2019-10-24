//
//  Collectable.cpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

Collectable::Collectable()
{
    
}

Collectable::Collectable(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind) : Element(x, y, length, height, texture, numHorizontal, numVertical, _kind)
{
    isActive = true;
    isCollided = false;
}

