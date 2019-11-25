//
//  Element.cpp
//  SFML
//
//  Created by ZEMIN on 14/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.

#include "LIB.hpp"

Element::Element()
{
    isShowing = true;
}

Element::Element(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind)
{
    isShowing = true;
    
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
    
    int ranNumX = (rand() % numHorizontal) * animUnitLength;
    spritePos = sf::IntRect(ranNumX,1, animUnitLength, animUnitHeight);
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

int Element::DetectCollision(Element *other)
{
    // use the shape's bounding to detect
    if ((other->centerX - LENGTH_UNIT / 2) < (centerX + LENGTH_UNIT / 2) &&
        (other->centerX + LENGTH_UNIT / 2) > (centerX - LENGTH_UNIT / 2) &&
        (other->centerY - HEIGHT_UNIT / 2) < (centerY + HEIGHT_UNIT / 2) &&
        (other->centerY + HEIGHT_UNIT / 2) > (centerY - HEIGHT_UNIT / 2))
        return (other->kind);
    return (0);

}

// To play animation by indicating the aimed row how many sprite in it in the texture.
void Element::UpdateIdleAnimation(int forwardAnimRow, int forwardAnimCol, int backwardAnimRow, int backwardAnimCol, int leftwardAnimRow, int leftwardAnimCol, int rightwardAnimRow, int rightwardAnimCol)
{
    switch (currentDir) {
        case 1:
        {
            spritePos.top = animUnitHeight * (forwardAnimRow - 1);
            if (spritePos.left < animUnitLength * (forwardAnimCol - 1))
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case 2:
        {
            spritePos.top = animUnitHeight * (backwardAnimRow - 1);
            if (spritePos.left < animUnitLength * (backwardAnimCol - 1))
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case 3:
        {
            spritePos.top = animUnitHeight * (leftwardAnimRow - 1);
            if (spritePos.left < animUnitLength * (leftwardAnimCol - 1))
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case 4:
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
