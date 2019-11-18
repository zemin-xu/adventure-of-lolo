//
//  StaticEnemy.hpp
//  SFML
//
//  Created by ZEMIN on 13/11/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

#ifndef StaticEnemy_hpp
#define StaticEnemy_hpp
class Level;
class StaticEnemy : public ObstacleEnemy
{
private:
    bool isAwake;
public:
    StaticEnemy();
    StaticEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);
    void Update(Level &level);
};

#endif /* StaticEnemy_hpp */
