//
//  Menu.hpp
//  SFML
//
//  Created by ZEMIN on 26/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

#ifndef GameMenu_hpp
#define GameMenu_hpp

class GameMenu
{
private:
    static const int MAX_NUM_ITEMS_MENU = 3;
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUM_ITEMS_MENU];
    
    sf::Texture bgTexture;
    sf::Sprite bg;
    
    sf::Music music;
    
    
public:
    
    GameMenu(int width, float height);
    
    void Render(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem();
    
};


#endif /* Menu_hpp */
