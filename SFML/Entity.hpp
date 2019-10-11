//
//  Entity.hpp
//  SFML
//
//  Created by ZEMIN on 10/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <string>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class Entity
{
private:
protected:
    sf::RectangleShape shape;
    float speed;
    
public:
    Entity();
    virtual ~Entity();
    
    virtual void Move(const float& dt, const float dir_x, const float dir_y);
    
    virtual void Update(const float& dt);
    virtual void Render(sf::RenderTarget* target);
};

#endif /* Entity_hpp */
