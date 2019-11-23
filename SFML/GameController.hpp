//
//  GameController.hpp
//  SFML
//
//  Created by ZEMIN on 14/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

#ifndef GameController_hpp
#define GameController_hpp

class GameController{
private:
    sf::RenderWindow window;
    sf::Clock deltaTimeClock;
    sf::Clock renderClock;
    sf::Event event;
    
    float deltaTime;
    float renderTime;
    
    GameMenu menu;
    MusicController music;
    Level level;
    InputController inputController;
        
public:
    
    static const int LENGTH = 768;
    static const int HEIGHT = 576;
    
    enum State {Menu, Option, InGame, GameOver} state;
    
    GameController();
    
    void EndApplication();
    
    void UpdateTime();
    void UpdateSFMLEvents();
    void Update();
    void Render();
    void Run();
    
    
};

#endif /* GameController_hpp */
