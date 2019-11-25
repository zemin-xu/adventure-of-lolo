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

/* Static enemy is for those that will fire projectile towards player when they are alive, and they cannot move. */
class StaticEnemy : public ObstacleEnemy
{
private:
    float fireDelay;
    float time;
public:
    StaticEnemy();
    StaticEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);
    
    // To see weather player is in its horizontal or vertical array.
    void Update(Element *player, const float deltaTime, Level & level);
    void Fire(Level& level);
    
};


#endif /* StaticEnemy_hpp */
