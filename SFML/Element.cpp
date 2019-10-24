//
//  Element.cpp
//  SFML
//
//  Created by ZEMIN on 14/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

Element::Element()
{
    
}

Element::Element(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind)
{
    animNumVertical = numHorizontal;
    animNumVertical = numVertical;
    
    animUnitLength = (texture->getSize().x) / numHorizontal;
    animUnitHeight = (texture->getSize().y) / numVertical;
    
    shape.setSize(sf::Vector2f(length, height));
    real.setSize(sf::Vector2f(length * FACTOR, height * FACTOR));
    
    shape.setOrigin(length / 2, height / 2);
    real.setOrigin(length * FACTOR / 2, length * FACTOR / 2);
    
    shape.setPosition(x + length / 2, y + length / 2);
    real.setPosition(x + length / 2, y + length / 2);
    
    spritePos = sf::IntRect(0,0, animUnitLength, animUnitHeight);
    shape.setTexture(texture);
    kind = _kind;
    UpdatePosition();
    
}



void Element::UpdatePosition()
{
    centerX = real.getPosition().x;
    centerY = real.getPosition().y;
    shape.setPosition(centerX, centerY);
}

void Element::Render(sf::RenderWindow &window)
{
    shape.setTextureRect(spritePos);
    window.draw(shape);
}

int Element::GetObjectType()
{
    return (kind);
}

int Element::DetectCollision(Element *other)
{
    // use the shape's bounding to detect
    if ((other->centerX - LENGTH_UNIT / 2) < (centerX + LENGTH_UNIT / 2) &&
        (other->centerX + LENGTH_UNIT / 2) > (centerX - LENGTH_UNIT / 2) &&
        (other->centerY - HEIGHT_UNIT / 2) < (centerY + HEIGHT_UNIT / 2) &&
        (other->centerY + HEIGHT_UNIT / 2) > (centerY - HEIGHT_UNIT / 2))
        return (other->GetObjectType());
    return (0);

}

