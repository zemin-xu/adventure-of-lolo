//
//  Creature.hpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//
#include "LIB.hpp"
using namespace std;

#ifndef Creature_hpp
#define Creature_hpp

class Level;

class Creature : public Element
{
protected:
    int lifePoint;
    bool isAlive;
    bool canMove;
    
    int dirHorizontal;
    int dirVertical;
    float speed;
    
public:
    enum State{Forward,Backward,Leftward,Rightward, Forward_M, Backward_M,Leftward_M, Rightward_M} state;
    
    Creature();
    Creature(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);
    
    bool GetCanMove() { return (canMove);};
    
     
    
    int GetLifePoint() {return (lifePoint); }
    
    virtual void ScanAround(vector<Element> &obstacles, vector<Movable> &movables, vector<Collectable> &collectables,vector<Trigger> &triggers, vector<MovableEnemy> &eggs, vector<Enemy> &enemies, const float deltaTime, Level & level);
    
    void CollisionEnemy(Enemy* other, Level & level);
    void CollisionObstacle(Element *other);
    void CollisionTrigger(Trigger* other, Level & level);
    void CollisionCollectable(Collectable *other);
    
    void CollisionMovable(Movable *movable, const float deltaTime);
    
    void UpdateIdleAnimation(int forwardAnimRow, int forwardAnimCol, int backwardAnimRow, int backwardAnimCol, int leftwardAnimRow, int leftwardAnimCol, int rightwardAnimRow, int rightwardAnimCol);
    
    void UpdateMoveAnimation(int forwardAnimRow, int forwardAnimCol, int backwardAnimRow, int backwardAnimCol, int leftwardAnimRow, int leftwardAnimCol, int rightwardAnimRow, int rightwardAnimCol);
    
    virtual void Move(const float deltaTime);
    virtual void Fire(Level& level, Projectile& projectile) = 0;
    
};


#endif /* Creature_hpp */
