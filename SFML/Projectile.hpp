//
//  Projectile.hpp
//  SFML
//
//  Created by ZEMIN on 27/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//
#include "LIB.hpp"
#ifndef Projectile_hpp
#define Projectile_hpp

using namespace std;
class Enemy;
class Level;
class Projectile : public Movable
{
private:
    bool isUsing;
    float speed;
public:
    
    Projectile();
    Projectile(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);
    void SetIsUsing(bool b) {isUsing = b;};
    bool GetIsUsing() {return (isUsing);};
    void Disappear();
    
    void CollisionObstacle(Element *other);
    void Update(const float deltaTime, vector<Element> &obstacles, vector<Enemy> &enemies, vector<MovableEnemy> &eggs, Level &level);
};

#endif /* Projectile_hpp */
