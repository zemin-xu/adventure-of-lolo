//
//  MusicController.cpp
//  SFML
//
//  Created by ZEMIN on 23/11/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

MusicController::MusicController()
{
    if (!menuMusic.openFromFile("Sources/Sounds/menu.ogg"))
    return ;
    if (!bgMusic.openFromFile("Sources/Sounds/ingame.ogg"))
        return ;
    if (!winMusic.openFromFile("Sources/Sounds/win.ogg"))
        return ;
    if (!loseMusic.openFromFile("Sources/Sounds/gameover.ogg"))
        return ;
}

void MusicController::MenuMusicPlay()
{
    if (menuMusic.getStatus() != sf::Music::Playing)
        menuMusic.play();
    if (bgMusic.getStatus() == sf::Music::Playing)
    bgMusic.stop();
    menuMusic.setLoop(true);
}

void MusicController::InGameMusicPlay()
{
    if (bgMusic.getStatus() != sf::Music::Playing)
        bgMusic.play();
    if (menuMusic.getStatus() == sf::Music::Playing)
    menuMusic.stop();
    bgMusic.setLoop(true);
}

void MusicController::WinMusicPlay()
{
    
    if (bgMusic.getStatus() == sf::Music::Playing)
        bgMusic.stop();
    if (winMusic.getStatus() != sf::Music::Playing)
        winMusic.play();
}

void MusicController::LoseMusicPlay()
{
    cout << "lost";
    if (bgMusic.getStatus() == sf::Music::Playing)
        bgMusic.stop();
    if (loseMusic.getStatus() != sf::Music::Playing)
        loseMusic.play();
    
    
}
