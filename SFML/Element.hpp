//
//  Element.hpp
//  SFML
//
//  Created by ZEMIN on 14/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#ifndef Element_hpp
#define Element_hpp

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Map.hpp"


using namespace std;
class Element
{
private:
protected:
    
    sf::IntRect spritePos;
    bool isRigidbody;
    
    int animNumHorizontal;
    int animNumVertical;
    float animUnitLength;
    float animUnitHeight;
    
    static const int LENGTH_UNIT = 48;
    static const int HEIGHT_UNIT = 48;
    
    
    
public:
    float x1;
    float y1;
    float x2;
    float y2;
    
    sf::RectangleShape shape;
    Element();
    Element(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody);

    void UpdatePosition();
    virtual void Render(sf::RenderWindow &window);
    
};

class Collectable: public Element
{
protected:
    int value;
    bool isActive;
    
public:
    Collectable(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody);
    bool GetIsActive();
    void SetIsActive(bool _isActive);
    int  GetValue();
    
};

class Creature : public Element
{
protected:
    int life;
    bool isAlive;
    bool canMove;
    
public:
    enum State{Forward,Backward,Leftward,Rightward, Forward_M, Backward_M,Leftward_M, Rightward_M} state;
    
    Creature();
    Creature(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody);
    virtual void Move(const float deltaTime) = 0;
    virtual void DetectCollision(Map map);
    void Damage(Creature &other, int damage);
    
};

class Player : public Creature
{
public:
    
    
protected:
    
    int dirHorizontal;
    int dirVertical;
    
public:
    float speed;
    Player();
    Player(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool isRigidbody);

    void DetectCollision(Map map, vector<Collectable> &collectables);
    
    void Collision(vector<Collectable> &collectables);
    
    virtual void Move(const float deltaTime);
    
    
    void GetCollectable(Collectable &c);
    
    void UpdateVariable();
    void UpdateAnimation();
    void UpdateState();
    void Update(const float deltaTime, Map map, vector<Collectable> &collectables);
    void Render(sf::RenderWindow &window);

};

#endif /* Element_hpp */
