//
//  Game.hpp
//  SFML
//
//  Created by ZEMIN on 10/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "State.hpp"

class Game{
private:
    sf::RenderWindow *window;
    sf::Event sfEvent;
    
    sf::Clock deltaTimeClock;
    float deltaTime;
    
    std::stack<State*> states;
    
    void InitWindow();
    void InitStates();
    
public:
    Game();
    virtual ~Game();
    
    void EndApplication();
    
    void UpdateDeltaTime();
    void UpdateSFMLEvents();
    void Update();
    void Render();
    void Run();
};
#endif /* Game_hpp */
