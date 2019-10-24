//
//  Level.cpp
//  SFML
//
//  Created by ZEMIN on 24/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

Level::Level()
{
    
}

Level::Level(int _currentLevel)
{
    InitLevel(_currentLevel);
    playerLife = 5;
}

void Level::InitLevel(int level)
{
    currentLevel = level;
    heartLeft = 0;
    switch (currentLevel) {
        case 1:
            {
                for (int i = 0; i <12; i++)
                {
                    for (int j = 0; j < 16; j++)
                    {
                        if (level1[i][j] / 10 == 3)
                            heartLeft++;
                    }
                }
            }
            break;
        case 2:
        {
            for (int i = 0; i < 12; i++)
            {
                for (int j = 0; j < 16; j++)
                {
                    if (level2[i][j] / 10 == 3)
                        heartLeft++;
                }
            }
        }
            break;
            
        default:
            break;
    }
}

void Level::UpdateHeartLeft()
{
    heartLeft--;
    if (heartLeft <= 0 && currentLevel < MAX_LEVEL)
    {
        currentLevel++;
        InitLevel(currentLevel);
    }
}
