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

class MovableEnemy : public Movable
{
private:
    bool isInEgg;
public:
    MovableEnemy();
    MovableEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);
    void TurnTowardsPlayer(Element *player);
    void Update(Element *player);
};

#endif /* MovableEnemy_hpp */
