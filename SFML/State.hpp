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
protected:
    
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    
    bool quit;
    
    // resources
    std::vector<sf::Texture> textures;
    
    virtual void InitKeybinds() = 0;
    
public:
    State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    
    virtual ~State();
    
    
    const bool& GetQuit() const;
    virtual void CheckForQuit();
    virtual void EndState() = 0;
    
    virtual void UpdateInput(const float& dt) = 0;
    virtual void Update(const float& dt) = 0;
    virtual void Render(sf::RenderTarget* target = NULL) = 0;
};

class GameState : public State
{
private:
    Entity player;
    
    void InitKeybinds();
public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~GameState();
    
    void EndState();
    
    void UpdateInput(const float& dt);
    void Update(const float &dt);
    void Render(sf::RenderTarget* target);
};

#endif /* State_hpp */

