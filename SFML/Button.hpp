//
//  Button.hpp
//  SFML
//
//  Created by ZEMIN on 11/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <sstream>


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button{
private:
    unsigned short buttonState;
    
    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;
    
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;
public:
    Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    ~Button();
    
    // accessors
    const bool isPressed() const;
    
    void Update(const sf::Vector2f mousePos);
    void Render(sf::RenderTarget* target);
};
#endif /* Button_hpp */
