//
//  GraphicController.hpp
//  SFML
//
//  Created by ZEMIN on 15/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#ifndef GraphicController_hpp
#define GraphicController_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Movable.hpp"
#include "Collectable.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Map.hpp"



using namespace std;

class GraphicController
{
private:

public:
    
    sf::Texture texturePlayer;
    sf::Texture textureEnemy;
    sf::Texture textureBG;
    sf::Texture textureClosedKeyBox;
    
    sf::Texture textureOuterWall;
    sf::Texture textureClosedDoor;
    sf::Texture textureObstacle1;
    sf::Texture textureObstacle2;
    
    sf::Texture textureCollectable;
    sf::Texture textureMovable;
    sf::Texture textureUI;
    
    static const int LENGTH_UNIT = 48;
    static const int HEIGHT_UNIT = 48;
    
    static const int ANIM_PLAYER_NUM_HORIZONTAL = 10;
    static const int ANIM_PLAYER_NUM_VERTICAL = 8;
    
    static const int ANIM_ENEMY1_NUM_HORIZONTAL = 4;
    static const int ANIM_ENEMY1_NUM_VERTICAL = 4;
    
    Map map;
    
    sf::Font font;
    sf::Text title;
    sf::Text textLife;
    sf::Text textWeapon;
    
    vector<Element> background;
    vector<Element> obstacles;
    vector<Collectable> collectables;
    vector<Movable> movables;
    vector<Enemy> enemies;
    Player player;
    Element keyBox;
    Element door;
    Element uiLife;
    Element uiWeapon;
    
    GraphicController();
    
    void ReadTextureFile();
    void Update(const float deltaTime);
    void Render(sf::RenderWindow &window);
};

class InputController
{
public:
    InputController();
    
    void UpdateInput(Player &player);
};

    

#endif /* GraphicController_hpp */
