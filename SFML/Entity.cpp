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
    this->shape.setFillColor(sf::Color::White);
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
   
}

void Entity::Render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}


