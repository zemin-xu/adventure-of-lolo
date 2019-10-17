//
//  Movable.hpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#ifndef Movable_hpp
#define Movable_hpp

#include "Element.hpp"

class Movable : public Element
{
    
public:
    Movable(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody);
};

#endif /* Movable_hpp */
