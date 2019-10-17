//
//  Player.hpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "Element.hpp"
#include "Collectable.hpp"
#include "Movable.hpp"
#include "Creature.hpp"

class Player : public Creature
{
public:
    
    
protected:
    
public:
    
    Player();
    Player(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool isRigidbody);

    //void DetectCollision(Map map, vector<Collectable> &collectables, vector<Movable> &movables, const float deltaTime);
    
    
    void ScanAround(Element &e);
    
    // reaction when meeting a collision
    void Collision(vector<Collectable> &collectables);
    void Collision(Map map, vector<Movable> &movables, const float deltaTime);
    
    virtual void Move(const float deltaTime);
    
    
    void UpdateAnimation();
    void UpdateState();
    void Update(const float deltaTime, Map map, vector<Collectable> &collectables, vector<Movable> &movables);
    void Render(sf::RenderWindow &window);

};


#endif /* Player_hpp */
