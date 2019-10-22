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
    
    constexpr static const float FACTOR = 0.8f;
    
    static const int TRY_DISTANCE = 2;
    
    
    
public:
    float centerX;
    float centerY;
    
    int kind;
    
    sf::RectangleShape shape;
    sf::RectangleShape real;
    
    Element();
    Element(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);

    void UpdatePosition();
    virtual void Render(sf::RenderWindow &window);
    int GetObjectType();
    
};

#endif /* Element_hpp */
