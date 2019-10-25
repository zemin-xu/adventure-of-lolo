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

class Player : public Creature
{
public:
    
    
protected:
    
public:
    
    Player();
    Player(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);
    
    virtual void Move(const float deltaTime);
    
    void UpdateState();
    void Update(const float deltaTime, vector<Element> &obstacles, vector<Collectable> &collectables, vector<Movable> &movables, vector<Trigger> &triggers);
    void Render(sf::RenderWindow &window);
};


#endif /* Player_hpp */
