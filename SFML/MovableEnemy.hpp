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
class MovableEnemy : public Movable
{
private:
    float eggTime;
    int enemyKind;

public:
    MovableEnemy();
    MovableEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind, int _enemyKind);
    float GetEggTime(){return (eggTime);};
    int GetEnemyKind(){return (enemyKind);};
    void Update(Element *player, Level &level, const float deltaTime);
};

#endif /* MovableEnemy_hpp */
