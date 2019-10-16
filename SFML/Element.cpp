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
    shape.setSize(sf::Vector2f(length, height));
    shape.setPosition(x, y);
    spritePos = sf::IntRect(0,0, texture->getSize().x/ numHorizontal, texture->getSize().y/ numVertical);
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
    speed = 1.0f;
    dirHorizontal = 1;
    dirVertical = 1;
    canMove = true;
    state = Forward;

    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(sf::Color::Black);
    
    shape.setPosition(330.f, 400.f);
}

void Player::Collision(Element other)
{
    
}

void Player::Move()
{
    canMove = false;
    cout << "state = " << to_string(state) << endl;
    speed = 0.01f;
    dirVertical = dirHorizontal = 0;
    //cout << Backward_M << endl;
    switch (state) {
        case Forward_M:
        {
            
            dirHorizontal = 0;
            dirVertical = 1;
            canMove = true;
            cout << "forward\n";
        }
            break;
        case Backward_M:
        {
            dirHorizontal = 0;
            dirVertical = -1;
            canMove = true;
            cout << "backward\n";
        }
            break;
        case Leftward_M:
        {
            dirHorizontal = -1;
            dirVertical = 0;
            canMove = true;
            cout << "leftward\n";
        }
            break;
        case Rightward_M:
        {
            dirHorizontal = 1;
            dirVertical = 0;
            canMove = true;
            cout << "rightward\n";
        }
            break;
            
        default:
            break;
    }
    cout << "the speed of player is" << speed << endl;
    cout << "the dirHorizontal is" << dirHorizontal << endl;
    cout << "the dirVertical is" << dirVertical << endl;
    
    shape.move(speed * dirHorizontal, speed * dirVertical); 
}

void Player::Update()
{
    Move();
    
    /*
    switch (state)
    {
        case Forward_M:
        {
            spritePos.top = (1040 / 8) * 5;
            if (spritePos.left < (1200 / 10) * 9)
                spritePos.left += 1200 / 10;
            else
                spritePos.left = 0;
            //state = Forward;
            cout << "move" << endl;
        }
        break;
            
    }
    cout << "move move" << endl;
     */
     
    shape.setTextureRect(spritePos);
    
}



