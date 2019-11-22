//
//  StaticEnemy.hpp
//  SFML
//
//  Created by ZEMIN on 22/11/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

#ifndef StaticEnemy_hpp
#define StaticEnemy_hpp

class Projectile;
class Level;

class StaticEnemy : public ObstacleEnemy
{
private:
    float fireDelay;
    float time;
public:
    StaticEnemy();
    StaticEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);
    void Update(Element *player, const float deltaTime, Level & level);
    void Fire(Level& level);
    
};


#endif /* StaticEnemy_hpp */
