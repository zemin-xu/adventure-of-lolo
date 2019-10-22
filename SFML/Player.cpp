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
        if (state == Forward_M)
        {
            if (movables[i].x1 < x2 && movables[i].x2 > x1 &&
                movables[i].y1 < y2 + TRY_DISTANCE && movables[i].y2 > y1)
            {
                canMove = false;
                movables[i].SetCurrentDir(state - 3);
                movables[i].DetectObsCollision(map);
                movables[i].shape.move(speed * dirHorizontal * deltaTime, speed * dirVertical * deltaTime);
                movables[i].UpdatePosition();
                movables[i].SetCurrentDir(0);
            }
        }
        else if (state == Backward_M)
        {
            if (movables[i].x1 < x2 && movables[i].x2 > x1 &&
                movables[i].y1 < y2 && movables[i].y2 > y1 - TRY_DISTANCE)
            {
                canMove = false;
                movables[i].SetCurrentDir(state - 3);
                movables[i].DetectObsCollision(map);
                movables[i].shape.move(speed * dirHorizontal * deltaTime, speed * dirVertical * deltaTime);
                movables[i].UpdatePosition();
                movables[i].SetCurrentDir(0);
            }
        }
        else if (state == Leftward_M)
        {
            if (movables[i].x1 < x2 && movables[i].x2 > x1 - TRY_DISTANCE &&
                movables[i].y1 < y2 && movables[i].y2 > y1)
            {
                canMove = false;
                movables[i].SetCurrentDir(state - 3);
                movables[i].DetectObsCollision(map);
                movables[i].shape.move(speed * dirHorizontal * deltaTime, speed * dirVertical * deltaTime);
                movables[i].UpdatePosition();
                movables[i].SetCurrentDir(0);
            }
        }
        else if (state == Rightward_M)
        {
            if (movables[i].x1 < x2 + TRY_DISTANCE && movables[i].x2 > x1 &&
                movables[i].y1 < y2 && movables[i].y2 > y1)
            {
                canMove = false;
                movables[i].SetCurrentDir(state - 3);
                movables[i].DetectObsCollision(map);
                movables[i].shape.move(speed * dirHorizontal * deltaTime, speed * dirVertical * deltaTime);
                movables[i].UpdatePosition();
                movables[i].SetCurrentDir(0);
            }
        }
    }
}
*/

/*
   {
          
          
          if (movables[i].GetCurrentDir() != 0)
          {
              
          }
      }
*/
void Player::Move(const float deltaTime)
{
    if (canMove)
    {
        real.move(speed * dirHorizontal * deltaTime, speed * dirVertical * deltaTime);
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

void Player::Update(const float deltaTime, Map map, vector<Element> &obstacles, vector<Collectable> &collectables, vector<Movable> &movables)
{
    UpdateVariable();
    
    ScanAround(obstacles, movables, deltaTime);
    
    Move(deltaTime);
    /*
    if (canMove)
        DetectObsCollision(map);
    if (canMove)
        Collision(map, movables, deltaTime);
    if (canMove)
        Move(deltaTime);
        
        // Collision(collectables);
        
     */

}

// the functions in render will be update each frame of about 0.1s
void Player::Render(sf::RenderWindow &window)
{
    UpdateIdleAnimation(1, 3, 3, 1, 2, 3, 4, 3);
    UpdateMoveAnimation(5, 10, 7, 10, 6, 10, 8, 10);
    
    Element::Render(window);
    
    UpdateState();
    
}
