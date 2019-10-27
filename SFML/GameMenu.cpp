//
//  Menu.cpp
//  SFML
//
//  Created by ZEMIN on 26/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

GameMenu::GameMenu(int width, float height)
{
    
    if (!bgTexture.loadFromFile("Sources/start.jpg"))
        return ;
    if (!font.loadFromFile("Sources/karma_future.ttf"))
        return ;
    if (!music.openFromFile("Sources/Sounds/menu.ogg"))
        return ;
    

     bg.setTexture(bgTexture);
    
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Start");
    menu[0].setPosition(width * 2 / 3, height / 2 + height / 3 / (MAX_NUM_ITEMS_MENU) * 1);
    
    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Option");
    menu[1].setPosition(width * 2 / 3, height / 2 + height / 3 / (MAX_NUM_ITEMS_MENU) * 2);
    
    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(width *2 / 3, height / 2 + height / 3 / (MAX_NUM_ITEMS_MENU) * 3);
    
    selectedItemIndex = 0;
    
   
    
    
    //music.play();
}

void GameMenu::Render(sf::RenderWindow &window)
{
    window.draw(bg);
    for (int i = 0; i < MAX_NUM_ITEMS_MENU; i++) {
        window.draw(menu[i]);
    }
    
}

void GameMenu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void GameMenu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUM_ITEMS_MENU)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

int GameMenu::GetPressedItem()
{
    for (int i = 0; i < MAX_NUM_ITEMS_MENU; i++) {
        if (menu[i].getFillColor() == sf::Color::Red)
            return (i);
    }
    return (0);
}
