//
//  SimpleEnemy.hpp
//  SFML
//
//  Created by ZEMIN on 26/11/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"
#ifndef SimpleEnemy_hpp
#define SimpleEnemy_hpp

class SimpleEnemy : public Creature
{
private:
    float timer;
public:
    SimpleEnemy();
    SimpleEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int kind);
    
    void ScanAround(vector<Element> &obstacles, vector<Movable> &movables, vector<Collectable> &collectables, vector<Trigger> &triggers ,vector<MovableEnemy> &eggs, vector<Enemy> &enemies, const float deltaTime, Level & level);
    
    void ChangeDirection();
    void UpdateVariable();
    void Update(const float deltaTime, vector<Element> &obstacles, vector<Collectable> &collectables, vector<Movable> &movables, vector<Trigger> &triggers, vector<MovableEnemy> &eggs, vector<Enemy> &enemies, Element* player, Level & level);

    void Fire(Level& level, Projectile& projectile);
};



#endif /* SimpleEnemy_hpp */
