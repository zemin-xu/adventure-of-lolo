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

#endif /* Element_hpp */
