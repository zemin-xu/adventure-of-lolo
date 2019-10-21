//
//  Player.cpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "Player.hpp"


Player::Player()
{
    
}

Player::Player(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody) : Creature(x, y, length, height, texture, numHorizontal, numVertical, _isRigidbody)
{
    speed = 100.0f;
    dirHorizontal = 1;
    dirVertical = 1;
    weaponPoint = 3;
    canMove = false;
    
    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(sf::Color::Black);
}

/*
void Player::DetectCollision(Map map, vector<Collectable> &collectables, vector<Movable> &movables, const float deltaTime)
{
    
    Creature::DetectObsCollision(map);
    
    if (canMove)
    {
        if (state == Forward_M)
        {
            // meet obstacle
            int a = map.level[(int)(y2/HEIGHT_UNIT)][(int)((x1 + 6.0f)/LENGTH_UNIT)];
            int b = map.level[(int)(y2/HEIGHT_UNIT)][(int)((x2 - 6.0f)/LENGTH_UNIT)];
            if (a == 2 || b == 2)
                Collision(collectables);
            if (a == 4 || b == 4)
            {
                cout << "moveable" << endl;
                Collision(movables, deltaTime);
            }
                
        }
        else if (state == Backward_M)
        {
            int a = map.level[(int)(y1/HEIGHT_UNIT)][(int)((x1 + 6.0f)/LENGTH_UNIT)];
            int b = map.level[(int)(y1/HEIGHT_UNIT)][(int)((x2 - 6.0f)/LENGTH_UNIT)];
            if (a == 2 || b == 2)
                Collision(collectables);
            if (a == 4 || b == 4)
            {
                cout << "moveable" << endl;
                Collision(movables, deltaTime);
            }
        }
        else if (state == Leftward_M)
        {
            int a = map.level[(int)((y1 + 6.0f)/HEIGHT_UNIT)][(int)(x1/LENGTH_UNIT)];
            int b = map.level[(int)((y2 - 6.0f)/HEIGHT_UNIT)][(int)(x1/LENGTH_UNIT)];
            if (a == 2 || b == 2)
                Collision(collectables);
            if (a == 4 || b == 4)
            {
                cout << "moveable" << endl;
                Collision(movables, deltaTime);
            }
        }
        else if (state == Rightward_M)
        {
            int a = map.level[(int)((y1 + 6.0f)/HEIGHT_UNIT)][(int)(x2/LENGTH_UNIT)];
            int b = map.level[(int)((y2 - 6.0f)/HEIGHT_UNIT)][(int)(x2/LENGTH_UNIT)];
            if (a == 2 || b == 2)
                Collision(collectables);
            if (a == 4 || b == 4)
            {
                cout << "moveable" << endl;
                Collision(movables, deltaTime);
            }
        }
        
    }
}
 
 */

void Player::ScanAround(Element &e)
{
    
}

void Player::Collision(vector<Collectable> &collectables)
{
    for (int i = 0; i < collectables.size(); i++)
    {
        if (collectables[i].x1 < x2 && collectables[i].x2 > x1 &&
            collectables[i].y1 < y2 && collectables[i].y2 > y1)
        {
            
            
            collectables.erase(collectables.begin() + i);
        }
    }
}

void Player::Collision(Map map, vector<Movable> &movables, const float deltaTime)
{
    for (int i = 0; i < movables.size(); i++)
    {
        
        if (movables[i].x1 < x2 - 6.0f && movables[i].x2 > x1 + 6.0f &&
            movables[i].y1 < y2 - 6.0f && movables[i].y2 > y1 + 6.0f)
        {
            canMove = false;
            movables[i].SetCurrentDir(state - 3);
            movables[i].DetectObsCollision(map);
            if (movables[i].GetCurrentDir() != 0)
            {
                movables[i].shape.move(speed * dirHorizontal * deltaTime, speed * dirVertical * deltaTime);
                movables[i].UpdatePosition();
                movables[i].SetCurrentDir(0);
            }
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

void Player::Update(const float deltaTime, Map map, vector<Collectable> &collectables, vector<Movable> &movables)
{
    UpdateVariable();
    
    DetectObsCollision(map);
    
    Collision(map, movables, deltaTime);
    
    Collision(collectables);
    
    Move(deltaTime);
    
}

// the functions in render will be update each frame of about 0.1s
void Player::Render(sf::RenderWindow &window)
{
    UpdateIdleAnimation(1, 3, 3, 3, 2, 3, 4, 3);
    UpdateMoveAnimation(5, 10, 7, 10, 6, 10, 8, 10);
    
    Element::Render(window);
    
    UpdateState();
    
}
