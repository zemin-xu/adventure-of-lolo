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

class GameController;

class GameMenu
{
private:
    // the number of options in menu
    static const int MAX_NUM_ITEMS_MENU = 3;
    // currently selected index
    int selectedItemIndex;
    // whether it is showing the option contents right now
    bool inOptionState;
    
    sf::Font font;
    sf::Text menu[MAX_NUM_ITEMS_MENU];
    sf::Texture textureIndication;
    sf::Texture bgTexture;
    sf::Sprite indication;
    sf::Sprite bg;

public:
    bool GetInOptionState() {return (inOptionState);};
    void SetInOptionState(bool b) {inOptionState = b;};
    
    GameMenu(int width, float height);
    
    void Render(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    // When 'enter' pressed, the item will be confirmed.
    int GetPressedItem();
};


#endif /* Menu_hpp */
