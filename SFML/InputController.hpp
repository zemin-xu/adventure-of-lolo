//
//  InputController.hpp
//  SFML
//
//  Created by ZEMIN on 25/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//
#include "LIB.hpp"
#ifndef InputController_hpp
#define InputController_hpp


class InputController
{
public:
    InputController();
    
    void UpdateInput(Level &level);
};

#endif /* InputController_hpp */
