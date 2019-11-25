//
//  Enemy.hpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

#ifndef Enemy_hpp
#define Enemy_hpp

class Enemy: public Creature
{
protected:
    float timer;
public:
    int isUpDownBlocked;
    int isLeftRightBlocked;
    Enemy();
    Enemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int kind);
    
    void ScanAround(vector<Element> &obstacles, vector<Movable> &movables, vector<Collectable> &collectables, vector<Trigger> &triggers, vector<MovableEnemy> &eggs, vector<Enemy> &enemies, const float deltaTime, Level & level);
    
    void ChangeDirection();
    
    void FollowDirection(Element* player);
    
    void UpdateVariable();
    
    void Update(const float deltaTime, vector<Element> &obstacles, vector<Collectable> &collectables, vector<Movable> &movables, vector<Trigger> &triggers, vector<MovableEnemy> &eggs, vector<Enemy> &enemies, Element* player,Level & level);
    
    void Render(sf::RenderWindow &window);
    virtual void Fire(Level& level, Projectile& projectile);
};


#endif /* Enemy_hpp */
