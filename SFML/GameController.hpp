//
//  GameController.hpp
//  SFML
//
//  Created by ZEMIN on 14/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#ifndef GameController_hpp
#define GameController_hpp

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
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

#include "Element.hpp"
#include "GraphicController.hpp"

using namespace std;

class GameController{
private:
    
    
    sf::RenderWindow window;
    sf::Clock deltaTimeClock;
    sf::Event event;
    float deltaTime;
    
    GraphicController graphicController;
    InputController inputController;
    
    
public:
    

    static const int LENGTH = 1024;
    static const int HEIGHT = 768;
    
    
    GameController();
    
    void EndApplication();
    
    void UpdateDeltaTime();
    void UpdateSFMLEvents();
    void Update();
    void Render();
    void Run();
    
    
};

#endif /* GameController_hpp */