//
//  main.cpp
//  SFML
//
//  Created by ZEMIN on 10/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "GameController.hpp"


int main()
{
    GameController gameController;
    gameController.Run();
    
    return (0);
}

/*
using namespace std;
bool Collision(vector<sf::RectangleShape> obstacles, sf::RectangleShape player, float player_speed, int direction);

int main()
{
    
    const int LENGTH = 1024;
    const int HEIGHT = 768;
    const int LENGTH_UNIT = 64;
    const int HEIGHT_UNIT = 64;
    
    enum State{Forward,Backward,Leftward,Rightward, Forward_M, Backward_M,Leftward_M, Rightward_M};
    
    const int ANIM_PLAYER_NUM_HORIZONTAL = 10;
    const int ANIM_PLAYER_NUM_VERTICAL = 8;
    
    sf::RenderWindow window(sf::VideoMode(LENGTH,HEIGHT), "SFML window");
    
    sf::Texture texture_background;
    sf::Texture texture_obstacle;
    if (!texture_background.loadFromFile("Sources/sable.jpg"))
        return EXIT_FAILURE;
    if (!texture_obstacle.loadFromFile("Sources/obstacle.png"))
    return EXIT_FAILURE;

    sf::RectangleShape background(sf::Vector2f(LENGTH_UNIT,HEIGHT_UNIT));
    
    background.setTexture(&texture_background);
    
    // animation snippet
    sf::Clock clock;
    sf::Texture playerTexture;
    playerTexture.loadFromFile("Sources/player.png");
    sf::Vector2u textureSize = playerTexture.getSize();
    sf::RectangleShape player(sf::Vector2f(textureSize.x/ANIM_PLAYER_NUM_HORIZONTAL/2 - 2.0f, textureSize.y/ANIM_PLAYER_NUM_VERTICAL/2  - 2.0f));
    player.setOutlineThickness(2.0f);
    player.setOutlineColor(sf::Color::Black);
    
    sf::IntRect player_rect(0, 0, textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL, textureSize.y / ANIM_PLAYER_NUM_VERTICAL);
    player.setTexture(&playerTexture);
    
    player.setPosition(330.f, 400.f);
    State state = Forward;
    
    while(window.isOpen())
    {
        //process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        //window.clear();
        
        // obstacle
        vector<sf::RectangleShape> obstacles;
        for (int i = 0 ; i < LENGTH / LENGTH_UNIT; i++)
        {
            for (int j = 0 ; j < HEIGHT/HEIGHT_UNIT; j++) {
                background.setPosition(i * LENGTH_UNIT, j * HEIGHT_UNIT);
                window.draw(background);
                if((i == 0 || i == 3 || i == LENGTH / LENGTH_UNIT - 1 || j == 0 || j == 3 || j == HEIGHT/HEIGHT_UNIT - 1) && (i%2))
                {
                    sf::RectangleShape obstacle(sf::Vector2f(LENGTH_UNIT, HEIGHT_UNIT));
                    obstacle.setTexture(&texture_obstacle);
                    obstacle.setPosition(i*LENGTH_UNIT, j*HEIGHT_UNIT);
                    obstacle.setOutlineThickness(2.0f);
                    obstacle.setOutlineColor(sf::Color::White);
                    
                    window.draw(obstacle);
                    obstacles.push_back(obstacle);
                }
            }
        }
        
        
        // detect collision
        bool canMove = true;
        // move
        float player_speed = 0.3f;
        float dir_horizontal = 0.0f;
        float dir_vertical = 0.0f;
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            dir_horizontal = -1.0f;
            dir_vertical = 0.0f;
            state = Leftward_M;
            canMove = Collision(obstacles, player, player_speed, 1);
        }
    
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            dir_horizontal = 1.0f;
            dir_vertical = 0.0f;
            state = Rightward_M;
            canMove = Collision(obstacles, player, player_speed, 2);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            dir_horizontal = 0.0f;
            dir_vertical = -1.0f;
            state = Backward_M;
            canMove = Collision(obstacles, player, player_speed, 3);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            dir_horizontal = 0.0f;
            dir_vertical = 1.0f;
            state = Forward_M;
            canMove = Collision(obstacles, player, player_speed, 4);
        }
        if (canMove)
            player.move(player_speed * dir_horizontal, player_speed * dir_vertical);
        
        
        // animation
        if (clock.getElapsedTime().asSeconds() >= 0.12f)
        {
            clock.restart();
            
            switch (state) {
                case Forward:
                {
                    player_rect.top = (textureSize.y / ANIM_PLAYER_NUM_VERTICAL) * 0;
                    if (player_rect.left < (textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL) * 2)
                        player_rect.left += textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL;
                    else
                        player_rect.left = 0;
                }
                break;
                case Leftward:
                    {
                        player_rect.top = (textureSize.y / ANIM_PLAYER_NUM_VERTICAL) * 1;
                        if (player_rect.left < (textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL) * 2)
                            player_rect.left += textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL;
                        else
                            player_rect.left = 0;
                    }
                break;
                case Rightward:
                {
                    player_rect.top = (textureSize.y / ANIM_PLAYER_NUM_VERTICAL) * 3;
                    if (player_rect.left < (textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL) * 2)
                        player_rect.left += textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL;
                    else
                        player_rect.left = 0;
                }
                break;
                case Backward:
                {
                    player_rect.top = (textureSize.y / ANIM_PLAYER_NUM_VERTICAL) * 2;
                    player_rect.left = 0;
                }
                break;
                    
                    
                case Forward_M:
                {
                    player_rect.top = (textureSize.y / ANIM_PLAYER_NUM_VERTICAL) * 4;
                    if (player_rect.left < (textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL) * 9)
                        player_rect.left += textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL;
                    else
                        player_rect.left = 0;
                    state = Forward;
                }
                break;
                case Backward_M:
                {
                    player_rect.top = (textureSize.y / ANIM_PLAYER_NUM_VERTICAL) * 6;
                    if (player_rect.left < (textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL) * 9)
                        player_rect.left += textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL;
                    else
                        player_rect.left = 0;
                    state = Backward;
                }
                break;
                case Leftward_M:
                {
                    player_rect.top = (textureSize.y / ANIM_PLAYER_NUM_VERTICAL) * 5;
                    if (player_rect.left < (textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL) * 9)
                        player_rect.left += textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL;
                    else
                        player_rect.left = 0;
                    state = Leftward;
                }
                break;
                case Rightward_M:
                {
                    player_rect.top = (textureSize.y / ANIM_PLAYER_NUM_VERTICAL) * 7;
                    if (player_rect.left < (textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL) * 9)
                        player_rect.left += textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL;
                    else
                        player_rect.left = 0;
                    state = Rightward;
                }
                break;
                default:
                    break;
            }
            player.setTextureRect(player_rect);
        }
        
        window.draw(player);
        window.display();
    }
    
    return EXIT_SUCCESS;
}



bool Collision(vector<sf::RectangleShape> obstacles, sf::RectangleShape player, float player_speed, int direction)
{
    
    for (int i = 0; i < obstacles.size(); i++)
    {
        switch (direction)
        {
            case 1:
            {
                // the obstacles on left side of player
                  if ((obstacles[i].getPosition().x < player.getPosition().x - player_speed) &&
                      (obstacles[i].getPosition().x + obstacles[i].getSize().x > player.getPosition().x - player_speed))
                  {
                      if ((obstacles[i].getPosition().y + obstacles[i].getSize().y < player.getPosition().y) || (obstacles[i].getPosition().y > player.getPosition().y + player.getSize().y))
                          continue;
                      else
                          return (false);
                  }
                
            }
            break;
                case 2:
                {
                    // the obstacles on right side of player
                      if ((obstacles[i].getPosition().x > player.getPosition().x + player_speed) &&
                          (obstacles[i].getPosition().x - obstacles[i].getSize().x < player.getPosition().x + player_speed))
                      {
                          if ((obstacles[i].getPosition().y + obstacles[i].getSize().y < player.getPosition().y) || (obstacles[i].getPosition().y > player.getPosition().y + player.getSize().y))
                              continue;
                          else
                              return (false);
                      }
                    
                }
                break;
                case 3:
                {
                    // the obstacles on up side of player
                      if ((obstacles[i].getPosition().y < player.getPosition().y - player_speed) &&
                          (obstacles[i].getPosition().y + obstacles[i].getSize().y > player.getPosition().y - player_speed))
                      {
                          if ((obstacles[i].getPosition().x + obstacles[i].getSize().x < player.getPosition().x) || (obstacles[i].getPosition().x > player.getPosition().x + player.getSize().x))
                              continue;
                          else
                              return (false);
                      }
                    
                }
                break;
                case 4:
                {
                    // the obstacles on down side of player
                      if ((obstacles[i].getPosition().y > player.getPosition().y + player_speed) &&
                          (obstacles[i].getPosition().y - obstacles[i].getSize().y < player.getPosition().y + player_speed))
                      {
                          if ((obstacles[i].getPosition().x + obstacles[i].getSize().x <= player.getPosition().x) || (obstacles[i].getPosition().x >= player.getPosition().x + player.getSize().x))
                              continue;
                          else
                              return (false);
                      }
                    
                }
                break;
        }
        
    }
    return (true);
}
*/
