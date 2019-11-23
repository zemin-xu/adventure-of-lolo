//
//  Player.cpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

Player::Player()
{
    
}

Player::Player(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind) : Creature(x, y, length, height, texture, numHorizontal, numVertical, _kind)
{
    speed = 100.0f;
    dirHorizontal = 1;
    dirVertical = 1;
    canMove = false;
    kind = _kind;
    
    
    if (!bufferPlayerStep.loadFromFile("Sources/Sounds/footstep.wav"))
        return ;
    playerStep.setBuffer(bufferPlayerStep);
    playerStep.setVolume(500.0f);
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

void Player::Update(const float deltaTime, vector<Element> &obstacles, vector<Collectable> &collectables, vector<Movable> &movables, vector<Trigger> &triggers, vector<MovableEnemy> &eggs, Level & level)
{
    UpdateVariable();
    
    ScanAround(obstacles, movables, collectables, triggers, eggs, deltaTime, level);
    
    Move(deltaTime);

}

// the functions in render will be update each frame of about 0.1s
void Player::Render(sf::RenderWindow &window)
{
    UpdateIdleAnimation(1, 4, 4, 4, 2, 4, 3, 4);
    UpdateMoveAnimation(1, 4, 4, 4, 2, 4, 3, 4);
    
    Element::Render(window);
    
    UpdateState();
}

void Player::Fire(Level& level, Projectile& projectile)
{
    if (level.GetPlayerProjectileNum() > 0 && !projectile.GetIsUsing())
    {
        level.SetPlayerProjectileNum(level.GetPlayerProjectileNum() - 1);
        projectile.SetIsUsing(true);
           
           if (state == Forward || state == Forward_M)
               projectile.SetCurrentDir(1);
           else if (state == Backward || state == Backward_M)
               projectile.SetCurrentDir(2);
           else if (state == Leftward || state == Leftward_M)
               projectile.SetCurrentDir(3);
           else if (state == Rightward || state == Rightward_M)
               projectile.SetCurrentDir(4);
           
           projectile.real.setPosition(centerX, centerY);
           projectile.canMove = true;
    }
}
