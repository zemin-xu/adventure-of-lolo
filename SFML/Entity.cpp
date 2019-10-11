//
//  Entity.cpp
//  SFML
//
//  Created by ZEMIN on 10/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "Entity.hpp"


Entity::Entity()
{
    this->shape.setSize(sf::Vector2f(50.0f,50.0f));
    this->speed = 100.0f;
}

Entity::~Entity()
{
    
}

void Entity::Move(const float& dt,const float dir_x, const float dir_y)
{
    this->shape.move(dir_x * this->speed * dt, dir_y * this->speed * dt);
}

void Entity::Update(const float& dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->Move(dt, -1.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->Move(dt, 1.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->Move(dt, 0.0f, 1.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->Move(dt, 0.0f, -1.0f);
}

void Entity::Render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}


