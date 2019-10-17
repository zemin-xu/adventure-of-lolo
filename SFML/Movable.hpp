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
private:
    // 0 : cannot move / stable
    // 1 : moving down
    // 2 : moving up
    // 3 : moving left
    // 4 : moving down
    int currentDir;
    
public:
    Movable(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody);
    void DetectObsCollision(Map map);
    int GetCurrentDir();
    void SetCurrentDir(int _currentDir);
};

#endif /* Movable_hpp */
