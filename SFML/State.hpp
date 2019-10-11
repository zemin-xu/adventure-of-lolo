//
//  State.hpp
//  SFML
//
//  Created by ZEMIN on 10/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include "Entity.hpp"

class State
{
private:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
    bool quit;
    
public:
    State(sf::RenderWindow* window);
    virtual ~State();
    
    const bool& GetQuit() const;
    virtual void CheckForQuit();
    virtual void EndState() = 0;
    
    virtual void UpdateKeyBinds(const float& dt) = 0;
    virtual void Update(const float& dt) = 0;
    virtual void Render(sf::RenderTarget* target = NULL) = 0;
};

class GameState : public State
{
private:
    Entity player;
public:
    GameState(sf::RenderWindow* window);
    virtual ~GameState();
    
    void EndState();
    
    void UpdateKeyBinds(const float& dt);
    void Update(const float &dt);
    void Render(sf::RenderTarget* target);
};

#endif /* State_hpp */
