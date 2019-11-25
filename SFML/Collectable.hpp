//
//  Collectable.hpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

#ifndef Collectable_hpp
#define Collectable_hpp

/* This class is for the collectables like the hearts and projectiles. */
class Collectable: public Element
{
protected:
    bool isCollided;
    bool isActive;
    
public:
    Collectable();
    Collectable(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);
    bool GetIsActive() { return (isActive);};
    void SetIsActive(bool _isActive) {isActive = _isActive;};
    
    void SetIsCollided(bool _isCollided) {isCollided = _isCollided;};
    bool GetIsCollided() { return (isCollided);};
};


#endif /* Collectable_hpp */
