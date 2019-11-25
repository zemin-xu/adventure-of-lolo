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

/* The base class of all existing sprite, such as obstacles, enemies and player. */

class Element
{
private:
    // The direction that this element looks or moves towards.
    // 0 : cannot move / stable
    // 1 : moving down
    // 2 : moving up
    // 3 : moving left
    // 4 : moving down
    int currentDir;
    
protected:
    
    sf::IntRect spritePos;
    bool isRigidbody;
    
    // the number of sprite in a texture
    int animNumHorizontal;
    int animNumVertical;
    
    float animUnitLength;
    float animUnitHeight;
    
    // the length and height of each sprite
    static const int LENGTH_UNIT = 48;
    static const int HEIGHT_UNIT = 48;
    
    // the real part of an element is 0.8f of the visible one
    constexpr static const float FACTOR = 0.8f;
    
    static const int TRY_DISTANCE = 6;

    
    
    
public:
    // The coord of the center point of an element.
    float centerX;
    float centerY;
    
    // The variable 'kind' here is important, which is the same as that in clas s Level.
    // It is useful because there maybe diffrent kinds of objects in a same list.
    // We can use it to do downcasting if needed.
    int kind;
    
    // a boolean telling whether this element is visible
    bool isShowing;
    
    // The concept of shape and real is important to do the collision detection in game. Each element will have two rectangle shape representing the real part(invisible, a bit smaller) and the visible part.
    /*
            -----------------
            -      shape    -
            -               -
            -    ********   -
            -    * real *   -
            -    *      *   -
            -    ********   -
            -----------------

     */
    
    sf::RectangleShape shape;
    sf::RectangleShape real;
    
    Element();
    
    // The standard constructor that will include the position and the dimension of
    // sprite, as well as how many sprites there are on the texture image.
    Element(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind);

    int GetCurrentDir() {return (currentDir);};
    void SetCurrentDir(int _currentDir) {currentDir = _currentDir;};
    
    void UpdatePosition();
    
    // the functions in render will be update each frame of about 0.1s
    virtual void Render(sf::RenderWindow &window);
    
    // To know whether two elements intersect.
    // It returns the 'kind' variable of 'other' if they intersect.
    // It is different from other function of collision. The main function of it is to detect whether the shape of two elements intersects.
    int DetectCollision(Element *other);
    
    // If the element has animation, this function will update it according to the number of sprite for each animation in a texture file.
    void UpdateIdleAnimation(int forwardAnimRow, int forwardAnimCol, int backwardAnimRow, int backwardAnimCol, int leftwardAnimRow, int leftwardAnimCol, int rightwardAnimRow, int rightwardAnimCol);
    
};

#endif /* Element_hpp */

