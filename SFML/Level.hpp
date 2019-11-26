//
//  Level.hpp
//  SFML
//
//  Created by ZEMIN on 24/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//


/*
 
 All the list of objects, textures as well as level maps will exist here.
 All the corresponding initilization and update of list and objects will be here.
 There are also the variables that are not supposed to be reinitialized like
 the num of playerLife and that of playerProjectile, UI, etc.
 
 */
#include "LIB.hpp"

#ifndef Level_hpp
#define Level_hpp

class Level
{
private:
    // index of current level
    int currentLevel;
    // the heart Left in the map
    int heartLeft;
    // the life that player has
    int playerLife;
    // the number of projectile that player has
    int playerProjectileNum;
    
    bool isEnemyAwake;
    bool hasWin;
    bool hasLost;
    
    // The structure of an elements in map which includes its coord index
    // and the type of element it will take.
    struct coord
    {
        int x;
        int y;
        int type;
    };
    
    // Max level number
    static const int MAX_LEVEL = 4;

public:
    sf::Texture texturePlayer;
    sf::Texture textureEnemyStaticSleep;
    sf::Texture textureEnemyStaticAwake;
    sf::Texture textureEgg;
    sf::Texture textureObstacleEnemy;
    sf::Texture textureChasingEnemy;
    sf::Texture textureSimpleEnemy;
    sf::Texture textureBG;
    sf::Texture textureBG2;
    sf::Texture textureClosedKeyBox;
    sf::Texture textureMiKeyBox;
    sf::Texture textureOpenKeyBox;
    sf::Texture textureBackground;
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
    
    sf::Texture textureWin;
    sf::Texture textureLose;
    sf::Texture textureIndication;
    
    sf::Font font;
    sf::Text title;
    sf::Text textLife;
    sf::Text textWeapon;
    sf::Sprite imageWin;
    sf::Sprite imageLose;
    sf::Sprite spriteIndication;
    
    /*
     The list of each kind of element.
     There might be several kinds of elements in the same list.
     For example, there will be obstacle enemy in list "obstacles".
     */
    vector<Element> background;
    vector<Element> obstacles;
    vector<Collectable> collectables;
    vector<Movable> movables;
    vector<Enemy> enemies;
    vector<SimpleEnemy> simpleEnemies;
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
        {00,22,11,23, 23,11,11,11, 11,23,23,11, 11,22,00,00},
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
        {00,22,25,25, 25,25,11,25, 25,25,25,11, 25,22,00,00},
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
        {00,22,11,11, 11,11,11,11, 11,11,11,11, 11,22,00,00},
        {00,22,11,25, 21,21,21,21, 32,25,25,25, 11,22,00,00},
        {00,22,11,25, 25,25,25,25, 25,25,25,25, 11,22,00,00},
        {00,22,11,25, 62,23,11,26, 11,11,11,11, 11,22,00,00},
        {00,22,11,11, 11,23,11,23, 11,21,11,11, 11,22,00,00},
        {00,22,11,25, 11,23,31,23, 31,11,11,11, 11,22,00,00},
        {00,22,11,25, 11,23,11,23, 21,25,25,25, 11,22,00,00},
        {00,22,51,25, 11,21,32,11, 71,25,25,25, 11,22,00,00},
        {00,22,11,25, 11,25,25,25, 25,25,25,25, 31,22,00,00},
        {00,22,11,11, 11,11,11,11, 11,31,11,11, 21,22,00,00},
        {00,22,22,22, 22,22,22,22, 22,22,22,22, 22,22,00,00}
    };
    
    const int level4[12][16] =
    {
        {00,22,22,22, 22,22,22,61, 22,22,22,22, 22,22,00,00},
        {00,22,11,11, 11,52,11,11, 11,11,11,11, 11,22,00,00},
        {00,22,11,21, 21,21,21,21, 21,41,11,11, 11,22,00,00},
        {00,22,11,11, 41,11,11,11, 11,11,11,21, 11,22,00,00},
        {00,22,11,11, 25,25,25,11, 21,21,21,21, 11,22,00,00},
        {00,22,31,25, 25,25,25,11, 21,31,11,11, 11,22,00,00},
        {00,22,32,25, 25,62,11,11, 21,31,52,11, 11,22,00,00},
        {00,22,11,11, 25,25,25,11, 21,21,21,21, 11,22,00,00},
        {00,22,11,11, 41,11,11,11, 11,11,11,21, 11,22,00,00},
        {00,22,11,21, 21,21,21,21, 21,41,11,11, 11,22,00,00},
        {00,22,11,11, 11,52,11,71, 11,11,11,11, 11,22,00,00},
        {00,22,22,22, 22,22,22,22, 22,22,22,22, 22,22,00,00}
    };
    
    Level();
    Level(int _currentLevel);
    
    int GetPlayerProjectileNum(){return (playerProjectileNum);};
    void SetPlayerProjectileNum(int i){playerProjectileNum = i;};
    int GetHeartLeft(){return (heartLeft);};
    bool GetHasWin(){return (hasWin);};
    bool GetHasLost(){return (hasLost);};
    
    // Import all texture files
    void ReadTextureFile();
    
    // Update the map index when player finish current one.
    void UpdateCurrentMap();
    
    // Initialize the indicated level, including clearing list, resetting the playerProjectileNum and heartLeft value. After that, the elements will be created according to the index of current map and will be push into list.
    void InitLevel(int level);
    
    // When player collects a heart(mushroom red), the index of heart left on map will be update.
    void UpdateHeartLeft();
    
    // When player get damaged by enemy.
    void LoseLife();
    
    void GameOver();
    void GameWin();
    
    // to restart the game if get struct
    void RestartGame();
    
    // If there is only one heart left on map, the static enemy will be awaked. The trick here is to erase the element of obstacle element and create static enemy
    void AwakenEnemy();
    
    void UpdatePlayerProjectileNum();
    void HeartCollected();
    
    // When player reaches the key, all the enemies will disappear.
    void CleanLevelEnemy();
    
    // All the collision detection will be happened here.
    void Update(const float deltaTime);
    
    void Render(sf::RenderWindow &window);
};

#endif /* Level_hpp */
