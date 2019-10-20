//
//  Collectable.cpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "Collectable.hpp"

Collectable::Collectable()
{
    
}

Collectable::Collectable(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody) : Element(x, y, length, height, texture, numHorizontal, numVertical, _isRigidbody)
{
    value = 10;
    isActive = true;
}

bool Collectable::GetIsActive()
{
    return (isActive);
}

void Collectable::SetIsActive(bool _isActive)
{
    isActive = _isActive;
}

int  Collectable::GetValue()
{
    return (value);
}
