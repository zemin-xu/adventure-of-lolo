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
    state = Forward;
    
    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(sf::Color::Black);
    
    shape.setPosition(330.f, 400.f);
}

void Player::Collision(Element other)
{
    
}

void Player::Move(const float deltaTime)
{
    if (canMove)
        shape.move(speed * dirHorizontal * deltaTime, speed * dirVertical * deltaTime);
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

void Player::Update(const float deltaTime)
{
    UpdateVariable();
    
    Move(deltaTime);
    
}



