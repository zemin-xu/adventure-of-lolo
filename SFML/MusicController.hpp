//
//  MusicController.hpp
//  SFML
//
//  Created by ZEMIN on 23/11/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//
#include "LIB.hpp"

#ifndef MusicController_hpp
#define MusicController_hpp

class MusicController
{
private:
    sf::Music menuMusic;
    sf::Music bgMusic;
    sf::Music winMusic;
    sf::Music loseMusic;
public:
    MusicController();
    void MenuMusicPlay();
    void InGameMusicPlay();
    void WinMusicPlay();
    void LoseMusicPlay();
};

#endif /* MusicController_hpp */
