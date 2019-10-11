//
//  Button.cpp
//  SFML
//
//  Created by ZEMIN on 11/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "Button.hpp"

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->buttonState = BTN_IDLE;
    
    this->shape.setPosition(sf::Vector2f(x,y));
    this->shape.setSize(sf::Vector2f(width,height));
    
    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(16);
    this->text.setPosition(this->shape.getPosition().x + this->shape.getGlobalBounds().width/2.0f - this->text.getGlobalBounds().width / 2.0f,
                           this->shape.getPosition().y + this->shape.getGlobalBounds().height/2.0f - this->text.getGlobalBounds().height / 2.0f);
    
    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;
    this->shape.setFillColor(this->idleColor);
}

const bool Button::isPressed() const
{
    if (this->buttonState == BTN_ACTIVE)
        return (true);
    return (false);
}

// update the boolean for hover and press actions
void Button::Update(const sf::Vector2f mousePos)
{
    this->buttonState = BTN_IDLE;
    
    // hover
    if(this->shape.getGlobalBounds().contains(mousePos))
    {
        this->buttonState = BTN_HOVER;
        
        // pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = BTN_ACTIVE;
        }
    }
    
    switch (this->buttonState) {
        case BTN_IDLE:
            this->shape.setFillColor(this->idleColor);
            break;
        case BTN_HOVER:
            this->shape.setFillColor(this->hoverColor);
            break;
        case BTN_ACTIVE:
            this->shape.setFillColor(this->activeColor);
            break;
            
            
        default:
            this->shape.setFillColor(sf::Color::Red);
            break;
    }
}

void Button::Render(sf::RenderTarget* target)
{
    target->draw(this->shape);
    target->draw(this->text);
}
