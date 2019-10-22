//
//  Map.hpp
//  SFML
//
//  Created by ZEMIN on 16/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>

class Map
{
public:
    // 00: background_black
    // 11: background1      12: background2     13: closed key box
    // 21: obstacle1        22: outerwall       23: obstacle2       24: closed door
    // 31: collectable
    // 41: movable
    // 51: enemy1
    // 61: door
    // 71: player
    
    const int level[12][16] =
    {
        {00,22,22,22, 22,22,22,22, 24,22,22,22, 22,22,00,00},
        {00,22,21,21, 21,21,21,21, 11,11,11,11, 11,22,00,00},
        {00,22,21,11, 11,11,11,11, 11,41,11,11, 11,22,00,00},
        {00,22,11,11, 31,11,11,11, 11,41,11,11, 11,22,00,00},
        {00,22,11,11, 11,11,11,11, 11,41,11,11, 11,22,00,00},
        {00,22,11,11, 31,11,11,11, 11,11,51,11, 11,22,00,00},
        {00,22,11,11, 11,11,11,11, 11,11,11,11, 11,22,00,00},
        {00,22,11,23, 23,11,11,11, 11,11,11,11, 11,22,00,00},
        {00,22,23,23, 23,23,11,11, 71,23,23,11, 11,22,00,00},
        {00,22,21,11, 11,21,13,11, 11,11,23,23, 11,22,00,00},
        {00,22,21,21, 21,21,21,21, 11,11,11,11, 11,22,00,00},
        {00,22,22,22, 22,22,22,22, 22,22,22,22, 22,22,00,00}
    };
};

#endif /* Map_hpp */
