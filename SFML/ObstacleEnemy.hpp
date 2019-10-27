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


class ObstacleEnemy : public Element
{
private:
    float eggTime;
    
    float timer;
public:
    ObstacleEnemy();
    ObstacleEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);
    
    
    void TurnTowardsPlayer(Element *player);
    void Update(Element *player, const float deltaTime);
};

#endif /* ObstacleEnemy_hpp */
