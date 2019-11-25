//
//  ObstacleEnemy.hpp
//  SFML
//
//  Created by ZEMIN on 27/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//
#include "LIB.hpp"

#ifndef ObstacleEnemy_hpp
#define ObstacleEnemy_hpp

/* The obstacle enemy is those that will not move on the map, their existance is to serve as an obstacle to the player. */
class ObstacleEnemy : public Element
{
private:

public:
    ObstacleEnemy();
    ObstacleEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int kind);
    
    // The obstacle enemies will turn towards player when they are alive.
    void TurnTowardsPlayer(Element *player);
    void Update(Element *player, const float deltaTime);
};

#endif /* ObstacleEnemy_hpp */
