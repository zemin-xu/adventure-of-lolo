//
//  Enemy.cpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"
using namespace std;
Enemy::Enemy()
{
    
}

Enemy::Enemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody) : Creature(x, y, length, height, texture, numHorizontal, numVertical, _isRigidbody)
{
    speed = 70.0f;
    dirHorizontal = 1;
    dirVertical = 1;
    canMove = true;
    isUpDownBlocked = 0;
    isLeftRightBlocked = 0;
    timer = 0;
}

void Enemy::ScanAround(vector<Element> &obstacles, vector<Movable> &movables, vector<Collectable> &collectables, vector<Trigger> &triggers ,vector<MovableEnemy> &eggs, const float deltaTime)
{
    Creature::ScanAround(obstacles, movables, collectables, triggers, eggs, deltaTime);
    if (!canMove)
    {
        if (state == Forward_M && isUpDownBlocked == 0)
            isUpDownBlocked = 1;
        if (state == Backward_M && isUpDownBlocked == 0)
            isUpDownBlocked = 2;
        if (state == Backward_M && isUpDownBlocked == 1)
            isUpDownBlocked = 3;
        if (state == Forward_M && isUpDownBlocked == 2)
            isUpDownBlocked = 3;
        
        if (state == Leftward_M && isLeftRightBlocked == 0)
            isLeftRightBlocked = 1;
        if (state == Rightward_M && isLeftRightBlocked == 0)
            isLeftRightBlocked = 2;
        if (state == Rightward_M && isLeftRightBlocked == 1)
            isLeftRightBlocked = 3;
        if (state == Leftward_M && isLeftRightBlocked == 2)
            isLeftRightBlocked = 3;
    }
}

void Enemy::ChangeDirection()
{
    if (isUpDownBlocked ==3 && isLeftRightBlocked == 3)
        state = Forward_M;
    
    else if (isUpDownBlocked == 3 && isLeftRightBlocked == 1)
        state = Rightward_M;
    else if (isUpDownBlocked == 3 && isLeftRightBlocked == 2)
        state = Leftward_M;
    else if (isLeftRightBlocked == 3 && isUpDownBlocked == 1)
        state = Backward_M;
    else if (isLeftRightBlocked == 3 && isUpDownBlocked == 2)
        state = Forward_M;
    
    else if (isUpDownBlocked == 2 && isLeftRightBlocked == 1)
        state = Forward_M;
    else if (isUpDownBlocked == 1 && isLeftRightBlocked == 1)
        state = Backward_M;
    else if (isUpDownBlocked == 2 && isLeftRightBlocked == 2)
        state = Forward_M;
    else if (isUpDownBlocked == 1 && isLeftRightBlocked == 2)
        state = Backward_M;
    else if (isUpDownBlocked == 3 && isLeftRightBlocked == 0)
        state = Leftward_M;
    else if (isUpDownBlocked == 0 && isLeftRightBlocked == 3)
        state = Forward_M;
    
    else if (isUpDownBlocked == 0 && isLeftRightBlocked == 1)
    state = Forward_M;
    else if (isUpDownBlocked == 0 && isLeftRightBlocked == 2)
    state = Forward_M;
    else if (isUpDownBlocked == 1 && isLeftRightBlocked == 0)
    state = Leftward_M;
    else if (isUpDownBlocked == 2 && isLeftRightBlocked == 0)
    state = Leftward_M;
}

/* be executed each 1 sec to redirect */
void Enemy::FollowDirection(Element* player)
{
    float a = abs(player->centerX - centerX);
    float b = abs(player->centerY - centerY);
        if ((player->centerX - centerX < -4) && a > b)
            state = Leftward_M;
        else if (player->centerX - centerX > 4)
            state = Rightward_M;

        else if (player->centerY - centerY < 0)
            state = Backward_M;
        else if (player->centerY - centerY > 0)
            state = Forward_M;
}

void Enemy::UpdateVariable()
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

void Enemy::Update(const float deltaTime, vector<Element> &obstacles, vector<Collectable> &collectables, vector<Movable> &movables, vector<Trigger> &triggers, vector<MovableEnemy> &eggs, Element* player)
{
    timer += deltaTime;
    if (timer > 0.2f)
    {
        FollowDirection(player);
        isLeftRightBlocked = 0;
        isUpDownBlocked = 0;
        
        timer = 0.0f;
    }
    canMove = true;
    ScanAround(obstacles, movables, collectables, triggers, eggs, deltaTime);
    UpdateVariable();
    
    ChangeDirection();
    
    Move(deltaTime);
    
    
    
}

void Enemy::Render(sf::RenderWindow &window)
{
    UpdateIdleAnimation(1, 4, 4, 4, 2, 4, 3, 4);
    
    Element::Render(window);
}

void Enemy::Fire(Level& level, Projectile& projectile)
{
    cout << " enemy fire";
}
