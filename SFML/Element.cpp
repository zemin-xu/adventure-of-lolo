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

Creature::Creature()
{
    
}

Creature::Creature(int x, int y, int length, int height, sf::Texture *texture,  int numHorizontal, int numVertical, bool _isRigidbody) : Element(x, y, length, height, texture, numHorizontal, numVertical, _isRigidbody)
{
    life = 100;
    isAlive = true;
    state = Forward;
    
}


void Creature::Damage(Creature &other, int damage)
{
    other.life -= damage;
    if (other.life <= 0)
        other.isAlive = false;
}

Player::Player()
{
    
}

Player::Player(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody) : Creature(x, y, length, height, texture, numHorizontal, numVertical, _isRigidbody)
{
    speed = 100.0f;
    dirHorizontal = 1;
    dirVertical = 1;
    canMove = false;
    
    
    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(sf::Color::Black);
}

void Creature::DetectCollision(Map map)
{
    if (canMove)
    {
        // the 4.0f here is a defaut value to avoid intersect situation
        if (state == Forward_M)
        {
            cout << "y2 : " << y2 << endl;
            cout << "y2 place : " << (int)(y2/HEIGHT_UNIT) << endl;
            cout << " x1 place : " <<(int)(x1/LENGTH_UNIT) << endl;
            cout << " x2 place : " <<(int)(x2/LENGTH_UNIT) << endl;
            
            if ((((int)(y2/HEIGHT_UNIT) + 1) <= 12) &&
            ((y2 - ((int)(y2/HEIGHT_UNIT) + 1) * HEIGHT_UNIT) < 0) &&
            (map.level[(int)(y2/HEIGHT_UNIT)][(int)((x1 + 4.0f)/LENGTH_UNIT)] != 1) &&
            (map.level[(int)(y2/HEIGHT_UNIT)][(int)((x2 - 4.0f)/LENGTH_UNIT)] != 1))
                canMove = true;
            else
                canMove = false;
        }
        else if (state == Backward_M)
        {
            if ((((int)(y1/HEIGHT_UNIT) + 1) > 0) &&
                ((y1 - (int)(y1/HEIGHT_UNIT) * HEIGHT_UNIT) > 0) &&
                (map.level[(int)(y1/HEIGHT_UNIT)][(int)((x1 + 4.0f)/LENGTH_UNIT)] != 1) &&
                (map.level[(int)(y1/HEIGHT_UNIT)][(int)((x2 - 4.0f)/LENGTH_UNIT)] != 1))
                canMove = true;
            else
                canMove = false;
        }
        else if (state == Leftward_M)
        {
            if ((((int)(x1/LENGTH_UNIT) + 1) > 0) &&
                ((x1 - (int)(x1/LENGTH_UNIT) * LENGTH_UNIT) > 0) &&
                (map.level[(int)((y1 + 4.0f)/HEIGHT_UNIT)][(int)(x1/LENGTH_UNIT)] != 1) &&
                (map.level[(int)((y2 - 4.0f)/HEIGHT_UNIT)][(int)(x1/LENGTH_UNIT)] != 1))
                canMove = true;
            else
                canMove = false;
        }
        else if (state == Rightward_M)
        {
            if ((((int)(x2/LENGTH_UNIT) + 1) <= 16) &&
                ((x2 - ((int)(x2/LENGTH_UNIT) + 1) * LENGTH_UNIT) < 0) &&
                (map.level[(int)((y1 + 4.0f)/HEIGHT_UNIT)][(int)(x2/LENGTH_UNIT)] != 1) &&
                (map.level[(int)((y2 - 4.0f)/HEIGHT_UNIT)][(int)(x2/LENGTH_UNIT)] != 1))
                canMove = true;
            else
                canMove = false;
        }
    }
}

void Player::Move(const float deltaTime)
{
    
    if (canMove)
    {
        shape.move(speed * dirHorizontal * deltaTime, speed * dirVertical * deltaTime);
        UpdatePosition();
    }
        
}

// the corresponding changement because of the changement of state of player
void Player::UpdateVariable()
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

void Player::UpdateAnimation()
{
    switch (state) {
        case Forward:
        {
            spritePos.top = animUnitHeight * 0;
            if (spritePos.left < animUnitLength * 2)
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case Backward:
        {
            spritePos.top = animUnitHeight * 2;
            if (spritePos.left < animUnitLength * 0)
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case Leftward:
        {
            spritePos.top = animUnitHeight * 1;
            if (spritePos.left < animUnitLength * 2)
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case Rightward:
        {
            spritePos.top = animUnitHeight * 3;
            if (spritePos.left < animUnitLength * 2)
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case Forward_M:
        {
            spritePos.top = animUnitHeight * 4;
            if (spritePos.left < animUnitLength * 9)
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case Backward_M:
        {
            spritePos.top = animUnitHeight * 6;
            if (spritePos.left < animUnitLength * 9)
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case Leftward_M:
        {
            spritePos.top = animUnitHeight * 5;
            if (spritePos.left < animUnitLength * 9)
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
        case Rightward_M:
        {
            spritePos.top = animUnitHeight * 7;
            if (spritePos.left < animUnitLength * 9)
                spritePos.left += animUnitLength;
            else
                spritePos.left = 0;
        }
            break;
    }
}

void Player::UpdateState()
{
    
    switch (state) {
        case Forward_M:
        {
            state = Forward;
        }
            break;
        case Backward_M:
        {
            state = Backward;
        }
            break;
        case Leftward_M:
        {
            state = Leftward;
        }
            break;
        case Rightward_M:
        {
            state = Rightward;
        }
            break;
            
        default:
            break;
    }
     
}

void Player::Update(const float deltaTime, Map map)
{
    UpdateVariable();
    
    DetectCollision(map);
    
    Move(deltaTime);
    
}

// the functions in render will be update each frame of about 0.1s
void Player::Render(sf::RenderWindow &window)
{
    UpdateAnimation();
    
    Element::Render(window);
    
    UpdateState();
    
}



