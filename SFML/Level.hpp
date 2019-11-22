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

class Level
{
private:
    int currentLevel;
    int heartLeft;
    int playerLife;
    int playerProjectileNum;
    
    bool isEnemyAwake;
    
    struct coord
    {
        int x;
        int y;
        int type;
    };
    
    static const int MAX_LEVEL = 3;

    sf::Music bgMusic;
    sf::Music winMusic;
    sf::Music loseMusic;
    
public:
    
    sf::Texture texturePlayer;
    sf::Texture textureEnemyStaticSleep;
    sf::Texture textureEnemyStaticAwake;
    sf::Texture textureEgg;
    sf::Texture textureObstacleEnemy;
    sf::Texture textureBG;
    sf::Texture textureBG2;
    sf::Texture textureClosedKeyBox;
    
    sf::Texture textureOuterWall;
    sf::Texture textureOpenDoor;
    sf::Texture textureClosedDoor;
    sf::Texture textureObstacle1;
    sf::Texture textureObstacle2;
    sf::Texture textureObstacle3;
    
    sf::Texture textureCollectable;
    sf::Texture textureCollectable2;
    sf::Texture textureMovable;
    sf::Texture textureUI;
    
    sf::Texture textureBackground;
    
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
    vector<MovableEnemy> eggs;
    vector<Projectile> enemyProjectiles;
    
    Player player;
    Element uiLife;
    Element uiWeapon;
    
    Projectile playerProjectile;
    vector<coord> currentMap;
  
    
    // 00: background_black
    // 11: background1      12: background2
    // 21: flower           22: outerwall        23: tree
    // 24: closed door      25: water            26: obstacle enemy
    // 27: sleep enemy      28: static enemy
    // 31: collectable      32: p_projectile     33: e_projectile
    // 41: movable          42: enemy in egg
    // 51: static enemy
    // 61: closed door      62: closed key box
    // 71: player
    // 81: playerProjectile 82: enemyProjectile
    
    const int level1[12][16] =
    {
        {00,22,22,22, 22,22,22,22, 61,22,22,22, 22,22,00,00},
        {00,22,21,21, 21,21,21,21, 11,21,21,23, 23,22,00,00},
        {00,22,21,23, 23,21,31,11, 11,21,21,23, 23,22,00,00},
        {00,22,11,11, 23,23,21,21, 11,21,21,21, 23,22,00,00},
        {00,22,71,11, 11,11,21,21, 11,21,21,23, 31,22,00,00},
        {00,22,11,11, 11,11,11,11, 26,11,21,11, 11,22,00,00},
        {00,22,11,11, 11,11,11,11, 11,11,11,32, 11,22,00,00},
        {00,22,11,23, 23,11,11,11, 11,23,23,51, 11,22,00,00},
        {00,22,23,23, 23,23,11,11, 11,23,23,23, 11,22,00,00},
        {00,22,21,23, 23,21,62,11, 11,11,23,23, 11,22,00,00},
        {00,22,21,21, 21,21,21,21, 11,11,11,11, 11,22,00,00},
        {00,22,22,22, 22,22,22,22, 22,22,22,22, 22,22,00,00}
    };
    
    const int level2[12][16] =
    {
        {00,22,22,22, 22,22,22,22, 22,22,22,61, 22,22,00,00},
        {00,22,11,11, 11,27,11,21, 21,21,11,11, 11,22,00,00},
        {00,22,21,31, 11,11,11,21, 21,21,11,31, 11,22,00,00},
        {00,22,11,11, 11,11,11,11, 23,23,11,11, 11,22,00,00},
        {00,22,25,25, 25,25,12,25, 25,25,25,12, 25,22,00,00},
        {00,22,62,11, 23,23,11,11, 11,11,11,32, 25,22,00,00},
        {00,22,11,11, 23,23,11,11, 11,23,23,11, 25,22,00,00},
        {00,22,11,11, 11,11,11,21, 21,23,23,11, 25,22,00,00},
        {00,22,27,11, 11,11,11,21, 21,31,11,11, 25,22,00,00},
        {00,22,11,11, 11,11,11,11, 41,11,11,11, 25,22,00,00},
        {00,22,31,11, 11,11,71,11, 25,25,25,25, 25,22,00,00},
        {00,22,22,22, 22,22,22,22, 22,22,22,22, 22,22,00,00}
    };
    
    const int level3[12][16] =
    {
        {00,22,22,22, 22,22,22,22, 22,22,22,61, 22,22,00,00},
        {00,22,11,11, 11,11,11,21, 21,21,11,11, 11,22,00,00},
        {00,22,21,31, 11,11,11,21, 21,21,11,31, 11,22,00,00},
        {00,22,11,11, 11,11,11,11, 23,23,11,11, 11,22,00,00},
        {00,22,25,25, 25,25,12,25, 25,25,25,12, 25,22,00,00},
        {00,22,62,11, 23,23,11,11, 11,11,11,11, 25,22,00,00},
        {00,22,11,11, 23,23,11,11, 11,23,23,11, 25,22,00,00},
        {00,22,11,11, 11,11,11,21, 21,23,23,11, 25,22,00,00},
        {00,22,11,11, 11,11,11,21, 21,31,11,11, 25,22,00,00},
        {00,22,11,11, 11,11,11,11, 41,11,11,11, 25,22,00,00},
        {00,22,31,11, 11,11,71,11, 25,25,25,25, 25,22,00,00},
        {00,22,22,22, 22,22,22,22, 22,22,22,22, 22,22,00,00}
    };
    
    Level();
    Level(int _currentLevel);
    
    int GetPlayerProjectileNum(){return (playerProjectileNum);};
    void SetPlayerProjectileNum(int i){playerProjectileNum = i;};
    int GetHeartLeft(){return (heartLeft);};
    
    void ReadTextureFile();
    void UpdateCurrentMap();
    void InitLevel(int level);

    void UpdateHeartLeft();
    void AwakenEnemy();
    void UpdatePlayerProjectileNum();
    void HeartCollected();
    void CleanLevelEnemy();
    
    void Update(const float deltaTime);
    void Render(sf::RenderWindow &window);
};

#endif /* Level_hpp */
