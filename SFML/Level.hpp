//
//  Level.hpp
//  SFML
//
//  Created by ZEMIN on 24/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//
#include "LIB.hpp"

#ifndef Level_hpp
#define Level_hpp

/* the index of level start from 1 */

class Level
{
private:
    int currentLevel;
    int heartLeft;
    int playerLife;
    int playerWeapon;
    
    struct coord
    {
        int x;
        int y;
        int type;
    };
    
    static const int MAX_LEVEL = 2;

    sf::Music bgMusic;
    sf::Music winMusic;
    sf::Music loseMusic;
    
public:
    
    sf::Texture texturePlayer;
    sf::Texture textureEnemy;
    sf::Texture textureMovableEnemy;
    sf::Texture textureBG;
    sf::Texture textureClosedKeyBox;
    
    sf::Texture textureOuterWall;
    sf::Texture textureClosedDoor;
    sf::Texture textureObstacle1;
    sf::Texture textureObstacle2;
    
    sf::Texture textureCollectable;
    sf::Texture textureMovable;
    sf::Texture textureUI;
    
    sf::Font font;
    sf::Text title;
    sf::Text textLife;
    sf::Text textWeapon;
    
    vector<Element> background;
    vector<Element> obstacles;
    vector<Collectable> collectables;
    vector<Movable> movables;
    vector<Enemy> enemies;
    vector<Trigger> triggers;
    
    Player player;
    Element uiLife;
    Element uiWeapon;
    
    vector<coord> currentMap;
  
    
    // 00: background_black
    // 11: background1      12: background2
    // 21: obstacle1        22: outerwall       23: obstacle2       24: closed door
    // 31: collectable
    // 41: movable          42: movableEnemy
    // 51: enemy1
    // 61: door             62: closed key box
    // 71: player
    
    const int level1[12][16] =
    {
        {00,22,22,22, 22,22,22,22, 61,22,22,22, 22,22,00,00},
        {00,22,21,21, 21,51,21,21, 11,11,11,11, 11,22,00,00},
        {00,22,21,11, 11,11,11,11, 11,41,11,11, 11,22,00,00},
        {00,22,11,11, 31,11,11,11, 11,41,11,11, 11,22,00,00},
        {00,22,11,11, 11,11,11,11, 11,41,11,11, 11,22,00,00},
        {00,22,11,11, 31,11,11,11, 11,11,11,11, 11,22,00,00},
        {00,22,11,11, 11,11,11,11, 11,11,42,11, 11,22,00,00},
        {00,22,11,23, 23,11,11,11, 11,11,11,11, 11,22,00,00},
        {00,22,23,23, 23,23,11,11, 71,23,42,42, 11,22,00,00},
        {00,22,21,11, 11,21,13,62, 11,11,23,23, 11,22,00,00},
        {00,22,21,21, 21,21,21,21, 11,11,11,11, 11,22,00,00},
        {00,22,22,22, 22,22,22,22, 22,22,22,22, 22,22,00,00}
    };
    
    const int level2[12][16] =
    {
        {00,22,22,22, 22,22,22,22, 22,22,22,22, 22,22,00,00},
        {00,22,21,21, 21,21,21,21, 11,11,11,11, 11,22,00,00},
        {00,22,21,11, 11,11,11,11, 11,41,11,11, 11,22,00,00},
        {00,22,11,11, 11,11,11,11, 11,41,11,11, 11,22,00,00},
        {00,22,11,11, 11,11,11,11, 11,41,11,11, 11,22,00,00},
        {00,22,11,11, 11,11,11,11, 11,11,11,11, 11,61,00,00},
        {00,22,31,11, 11,11,11,11, 11,11,11,11, 11,22,00,00},
        {00,22,11,23, 11,11,11,11, 11,11,11,11, 11,22,00,00},
        {00,22,23,23, 11,23,11,62, 11,23,11,11, 11,22,00,00},
        {00,22,21,11, 11,21,13,11, 11,11,11,11, 11,22,00,00},
        {00,22,21,21, 21,21,21,21, 11,11,11,11, 11,22,00,00},
        {00,22,22,22, 22,22,22,22, 22,22,22,22, 22,22,00,00}
    };
    
    Level();
    Level(int _currentLevel);
    
    void InitLevel(int level);
    void ReadTextureFile();
    void UpdateHeartLeft();
    void Render(sf::RenderWindow &window);
    void UpdateCurrentMap();
    void Update(const float deltaTime);
    void HeartCollected();
    void CleanLevelEnemy();
};

#endif /* Level_hpp */
