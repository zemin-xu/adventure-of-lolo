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

/* Movable is for those element that player can move, like box and enemy egg. */

class Movable : public Element
{
private:
public:
    // Weather the movable element has collided something.
    bool canMove;
    
    Movable();
    Movable(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);
    
    // When the box is pushed, check whether it has collision with obstacles.
    // If so, 'canMove' will turn to be false.
    void Collision(Element *other);
};

#endif /* Movable_hpp */
