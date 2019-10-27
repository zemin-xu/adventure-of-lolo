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
    Enemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody);
    
    void ScanAround(vector<Element> &obstacles, vector<Movable> &movables, vector<Collectable> &collectables, vector<Trigger> &triggers, vector<MovableEnemy> &eggs, const float deltaTime);
    
    void ChangeDirection();
    
    void FollowDirection(Element* player);
    
    void UpdateVariable();
    
    void Update(const float deltaTime, vector<Element> &obstacles, vector<Collectable> &collectables, vector<Movable> &movables, vector<Trigger> &triggers, vector<MovableEnemy> &eggs, Element* player);
    
  
    void Render(sf::RenderWindow &window);
    
    virtual void Fire(Level& level, Projectile& projectile);
};


#endif /* Enemy_hpp */
