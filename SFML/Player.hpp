//
//  Player.hpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"


#ifndef Player_hpp
#define Player_hpp
class Level;
class Player : public Creature
{
public:
    sf::SoundBuffer bufferPlayerStep;
    sf::SoundBuffer bufferPlayerFire;
protected:
    
public:
    
    sf::Sound playerStep;
    sf::Sound playerFire;
    
    Player();
    Player(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);
    
    void UpdateState();
    void UpdateVariable();
    void Update(const float deltaTime, vector<Element> &obstacles, vector<Collectable> &collectables, vector<Movable> &movables, vector<Trigger> &triggers, vector<MovableEnemy> &eggs, Level & level);
    void Render(sf::RenderWindow &window);
    
    virtual void Fire(Level& level, Projectile& projectile);
};


#endif /* Player_hpp */
