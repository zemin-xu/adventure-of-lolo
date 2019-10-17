//
//  Movable.cpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "Movable.hpp"

Movable::Movable(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody) : Element(x, y, length, height, texture, numHorizontal, numVertical, _isRigidbody)
{
    shape.setFillColor(sf::Color::Red);
}
