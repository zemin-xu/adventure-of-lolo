//
//  main.cpp
//  SFML
//
//  Created by ZEMIN on 10/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include <iostream>
#include <stdio.h>


int main()
{
    sf::RenderWindow window(sf::VideoMode(512,512), "SFML GAME", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape background(sf::Vector2f(window.getSize().x,window.getSize().y));
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    sf::Texture playerTexture;
    
    background.setFillColor(sf::Color::Black);
    playerTexture.loadFromFile("Sources/player.png");
    
  
    player.setTexture(&playerTexture);
    
    Animation animation(&playerTexture, sf::Vector2u(3,9), 0.3f);
    
    float deltaTime = 0.0f;
    sf::Clock clock;
    
    sf::Vector2u textureSize = playerTexture.getSize();
    textureSize.x /= 3;
    textureSize.y /= 4;
    player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 1, textureSize.x, textureSize.y));
    
    while(window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    std::cout << event.size.width << " " <<  event.size.height << std::endl;
                    break;
                case sf::Event::TextEntered:
                    if(event.text.unicode < 128)
                        printf("%c", event.text.unicode);
                    break;
                default:
                    break;
            }
        }
        
        animation.Update(0, deltaTime,false);
        player.setTextureRect((animation.uvRect));
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            player.move(-0.1f, 0.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            player.move(0.1f, 0.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            player.move(0.0f, -0.1f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            player.move(0.0f, 0.1f);
        
        window.clear(sf::Color(150,150,150));
        window.draw(player);
        window.display();
    }
}


/*
#include "Game.hpp"
 int     main()
{
    Game game;
    game.Run();
}
*/



int not_main(void)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "prototype");
    // Load a sprite to display
    sf::Texture texture;
    
    /*
    if (!texture.loadFromFile("Sources/sky.png", sf::IntRect(100,100,400,400)))
        return EXIT_FAILURE;
     */
    
    if (!texture.create(200, 200))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    // Create a graphical text to display
    
    sf::Font font;
    if (!font.loadFromFile("Sources/arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);
    
    // Load a music to play
    /*
    sf::Music music;
    if (!music.openFromFile("nice_music.ogg"))
        return EXIT_FAILURE;
    // Play the music
    music.play();
     */
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}

