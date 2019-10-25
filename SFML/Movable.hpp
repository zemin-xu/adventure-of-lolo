//
//  Movable.hpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

#ifndef Movable_hpp
#define Movable_hpp

class Movable : public Element
{
private:
    // 0 : cannot move / stable
    // 1 : moving down
    // 2 : moving up
    // 3 : moving left
    // 4 : moving down
    
    
    
public:
    bool canMove;
    
    Movable();
    Movable(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);
    
    void Collision(Element *other);
};

#endif /* Movable_hpp */
