//
//  Enemy.hpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

#ifndef Enemy_hpp
#define Enemy_hpp

class Enemy: public Creature
{
public:
    Enemy();
    Enemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody);
    
    void Move(const float deltaTime);
};

#endif /* Enemy_hpp */
