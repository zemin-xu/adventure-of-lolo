//
//  Element.hpp
//  SFML
//
//  Created by ZEMIN on 14/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//
#include "LIB.hpp"

#ifndef Element_hpp
#define Element_hpp

class Element
{
private:
    int currentDir;
    
    
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
    
    static const int TRY_DISTANCE = 6;

    
    
    
public:
    float centerX;
    float centerY;
    
    int kind;
    bool isShowing;
    
    sf::RectangleShape shape;
    sf::RectangleShape real;
    
    Element();
    Element(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);

    int GetCurrentDir() {return (currentDir);};
    void SetCurrentDir(int _currentDir) {currentDir = _currentDir;};
    
    void UpdatePosition();
    virtual void Render(sf::RenderWindow &window);
    int GetObjectType();
    int DetectCollision(Element *other);
    
    void UpdateIdleAnimation(int forwardAnimRow, int forwardAnimCol, int backwardAnimRow, int backwardAnimCol, int leftwardAnimRow, int leftwardAnimCol, int rightwardAnimRow, int rightwardAnimCol);
    
};

#endif /* Element_hpp */
