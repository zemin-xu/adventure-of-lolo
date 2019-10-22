//
//  Collectable.hpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#ifndef Collectable_hpp
#define Collectable_hpp

#include "Element.hpp"
class Collectable: public Element
{
protected:
    int value;
    bool isActive;
    
public:
    Collectable();
    Collectable(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);
    bool GetIsActive();
    void SetIsActive(bool _isActive);
    int  GetValue();
    
};


#endif /* Collectable_hpp */
