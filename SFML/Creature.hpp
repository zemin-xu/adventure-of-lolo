//
//  Creature.hpp
//  SFML
//
//  Created by ZEMIN on 17/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#ifndef Creature_hpp
#define Creature_hpp

#include "Element.hpp"


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
    Creature(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, bool _isRigidbody);
    
    int GetLifePoint() {return (lifePoint); }
    
    virtual void Move(const float deltaTime) = 0;
    virtual void DetectObsCollision(Map map);
    
    void UpdateIdleAnimation(int forwardAnimRow, int forwardAnimCol, int backwardAnimRow, int backwardAnimCol, int leftwardAnimRow, int leftwardAnimCol, int rightwardAnimRow, int rightwardAnimCol);
    
    void UpdateMoveAnimation(int forwardAnimRow, int forwardAnimCol, int backwardAnimRow, int backwardAnimCol, int leftwardAnimRow, int leftwardAnimCol, int rightwardAnimRow, int rightwardAnimCol);
    
    void Damage(Creature &other, int damage);
    void UpdateVariable();
    
};


#endif /* Creature_hpp */
