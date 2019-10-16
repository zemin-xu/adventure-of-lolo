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
    
public:
    sf::RectangleShape shape;
    Element();
    Element(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody);

    virtual void Render(sf::RenderWindow &window);
};

class Creature : public Element
{
protected:
    int life;
    bool isAlive;

    
public:
    Creature();
    Creature(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody);
    virtual void Move() = 0;
    virtual void Collision(Element other) = 0;
    void Damage(Creature &other, int damage);
    
};

class Player : public Creature
{
public:
    enum State{Forward,Backward,Leftward,Rightward, Forward_M, Backward_M,Leftward_M, Rightward_M} state;
    
protected:
    
    int dirHorizontal;
    int dirVertical;
    bool canMove;

public:
    float speed;
    Player();
    Player(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool isRigidbody);
    
    virtual void Collision(Element other);
    virtual void Move();
    
    void UpdateVariable();
    void UpdateAnimation();
    void UpdateState();
    void Update();
    
    
    
};

#endif /* Element_hpp */
