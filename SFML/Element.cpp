//
//  Element.cpp
//  SFML
//
//  Created by ZEMIN on 14/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "Element.hpp"

Element::Element()
{
    
}

Element::Element(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody)
{
    animNumVertical = numHorizontal;
    animNumVertical = numVertical;
    
    animUnitLength = (texture->getSize().x) / numHorizontal;
    animUnitHeight = (texture->getSize().y) / numVertical;
    
    shape.setSize(sf::Vector2f(length, height));
    shape.setPosition(x, y);
    spritePos = sf::IntRect(0,0, animUnitLength, animUnitHeight);
    shape.setTexture(texture);
    isRigidbody = _isRigidbody;
    UpdatePosition();
    
}

void Element::UpdatePosition()
{
    x1 = shape.getPosition().x;
    y1 = shape.getPosition().y;
    x2 = x1 + LENGTH_UNIT;
    y2 = y1 + HEIGHT_UNIT;
}

void Element::Render(sf::RenderWindow &window)
{
    shape.setTextureRect(spritePos);
    window.draw(shape);
}


