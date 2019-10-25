//
//  Trigger.hpp
//  SFML
//
//  Created by ZEMIN on 25/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

#ifndef Trigger_hpp
#define Trigger_hpp

class Trigger : public Element
{
private:
    // is this trigger can be touched by player
    bool isTriggerActive;
    
    // whether this open trigger has been touched
    bool trigger;
    
public:
    
    Trigger();
    Trigger(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);
    
    void SetIsTriggerActive(bool b){isTriggerActive = b;};
    bool GetIsTriggerActive(){return (isTriggerActive);};
    void SetTrigger(bool b){trigger = b ;};
    bool GetTrigger() { return (trigger); };
    
    
};


#endif /* Trigger_hpp */
