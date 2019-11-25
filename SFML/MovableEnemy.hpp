//
//  MovableEnemy.hpp
//  SFML
//
//  Created by ZEMIN on 25/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

#ifndef MovableEnemy_hpp
#define MovableEnemy_hpp
class Level;

/* This class is to implement the enemy egg that player can move.
The egg will break and restore the origin enemy. */
class MovableEnemy : public Movable
{
private:
    // How long will the enemy be locked in the egg.
    float eggTime;
    // The 'kind' value of the origin enemy.
    int enemyKind;

public:
    MovableEnemy();
    MovableEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind, int _enemyKind);
    float GetEggTime(){return (eggTime);};
    int GetEnemyKind(){return (enemyKind);};
    
    // Calculate the elapsed time.
    void Update(Element *player, Level &level, const float deltaTime);
};

#endif /* MovableEnemy_hpp */
