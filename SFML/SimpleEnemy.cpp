//
//  SimpleEnemy.cpp
//  SFML
//
//  Created by ZEMIN on 26/11/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//
#include "LIB.hpp"

SimpleEnemy::SimpleEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int kind) : Creature(x, y, length, height, texture, numHorizontal, numVertical, kind)
{
    speed = 150.0f;
    state = Forward_M;
    timer = 0;
}

void SimpleEnemy::ScanAround(vector<Element> &obstacles, vector<Movable> &movables, vector<Collectable> &collectables, vector<Trigger> &triggers ,vector<MovableEnemy> &eggs, vector<Enemy> &enemies, const float deltaTime, Level & level)
{
    Creature::ScanAround(obstacles, movables, collectables, triggers, eggs, enemies, deltaTime, level);
    if (!canMove)
    {
        ChangeDirection();
    }
}

void SimpleEnemy::ChangeDirection()
{
    int random = rand() % 3;
    if (state == Forward_M)
    {
        if (random == 0)
            state = Leftward_M;
        else if (random == 1)
            state = Rightward_M;
        else
            state = Backward_M;
    }
    if (state == Backward_M)
    {
        if (random == 0)
            state = Rightward_M;
        else if (random == 1)
        state = Leftward_M;
        else
            state = Forward_M;
    }
    else if (state == Leftward_M)
    {
       if (random == 0)
           state = Rightward_M;
        else if (random == 1)
        state = Forward_M;
       else
           state = Backward_M;
    }
    else if (state == Rightward_M)
    {
       if (random == 0)
           state = Leftward_M;
        else if (random == 1)
        state = Backward_M;
       else
           state = Forward_M;
    }
}

void SimpleEnemy::UpdateVariable()
{
    switch (state) {
        case Forward_M:
        {
            dirHorizontal = 0;
            dirVertical = 1;
        }
            break;
        case Backward_M:
        {
            dirHorizontal = 0;
            dirVertical = -1;
        }
            break;
        case Leftward_M:
        {
            dirHorizontal = -1;
            dirVertical = 0;
        }
            break;
        case Rightward_M:
        {
            dirHorizontal = 1;
            dirVertical = 0;
        }
            break;
            
        default:
            break;
    }
}

void SimpleEnemy::Update(const float deltaTime, vector<Element> &obstacles, vector<Collectable> &collectables, vector<Movable> &movables, vector<Trigger> &triggers, vector<MovableEnemy> &eggs, vector<Enemy> &enemies, Element* player, Level & level)
{
    timer += deltaTime;
    canMove = true;
    ScanAround(obstacles, movables, collectables, triggers, eggs, enemies, deltaTime, level);
    UpdateVariable();
    UpdateMoveAnimation(1, 4, 4, 4, 2, 4, 3, 4);
    
    if (timer > 2.0f)
    {
        timer = 0;
        ChangeDirection();
    }
    
    Move(deltaTime);
}

void SimpleEnemy::Fire(Level& level, Projectile& projectile)
{
    cout << " enemy fire";
}
