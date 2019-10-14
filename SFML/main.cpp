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
    
    const int LENGTH = 1024;
    const int HEIGHT = 768;
    const int LENGTH_UNIT = 64;
    const int HEIGHT_UNIT = 64;
    
    enum State{Forward,Backward,Leftward,Rightward, Forward_M, Backward_M,Leftward_M, Rightward_M};
    
    const int ANIM_PLAYER_NUM_HORIZONTAL = 10;
    const int ANIM_PLAYER_NUM_VERTICAL = 8;
    
    sf::RenderWindow window(sf::VideoMode(LENGTH,HEIGHT), "SFML window");
    
    sf::Texture texture;
    if (!texture.loadFromFile("Sources/sable.jpg"))
        return EXIT_FAILURE;
    //sf::Sprite sprite(texture);
    sf::RectangleShape shape1(sf::Vector2f(LENGTH_UNIT,HEIGHT_UNIT));
    sf::RectangleShape wall(sf::Vector2f(LENGTH_UNIT, HEIGHT_UNIT));
    
    shape1.setTexture(&texture);
    //shape2.setTexture(&texture);
    
    //shape2.setFillColor(sf::Color::Black);
    wall.setFillColor(sf::Color::Black);
    wall.setOutlineThickness(2.0f);
    wall.setOutlineColor(sf::Color::White);
    
    
    // animation snippet
    
    sf::Clock clock;
    sf::Texture playerTexture;
    playerTexture.loadFromFile("Sources/player.png");
    sf::Vector2u textureSize = playerTexture.getSize();
    sf::RectangleShape player(sf::Vector2f(textureSize.x/ANIM_PLAYER_NUM_HORIZONTAL/2, textureSize.y/ANIM_PLAYER_NUM_VERTICAL/2));
    player.setOutlineThickness(2.0f);
    player.setOutlineColor(sf::Color::Black);
    
    
    
    sf::IntRect player_rect(0, 0, textureSize.x / ANIM_PLAYER_NUM_HORIZONTAL, textureSize.y / ANIM_PLAYER_NUM_VERTICAL);
    player.setTexture(&playerTexture);
    
    player.setPosition(330.f, 400.f);
    State state = Forward;
    //float player_speed = 150.0f;
    
    while(window.isOpen())
    {
        //process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        
        // background
        for (int i = 0 ; i < LENGTH / LENGTH_UNIT; i++)
        {
            for (int j = 0 ; j < HEIGHT/HEIGHT_UNIT; j++) {
                shape1.setPosition(i * LENGTH_UNIT, j*HEIGHT_UNIT);
                window.draw(shape1);
                if(i == 0 || i == LENGTH / LENGTH_UNIT - 1 || j == 0 || j == HEIGHT/HEIGHT_UNIT - 1)
                {
                    wall.setPosition(i*LENGTH_UNIT, j*HEIGHT_UNIT);
                    window.draw(wall);
                }
            }
        }
        
        
        // move
        float player_speed = 0.3f;
        float dir_horizontal = 0.0f;
        float dir_vertical = 0.0f;
        bool is_moving = false;
        
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            dir_horizontal = -1.0f;
            dir_vertical = 0.0f;
            state = Leftward_M;
            is_moving = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            dir_horizontal = 1.0f;
            dir_vertical = 0.0f;
            state = Rightward_M;
            is_moving = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            dir_horizontal = 0.0f;
            dir_vertical = -1.0f;
            state = Backward_M;
            is_moving = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            dir_horizontal = 0.0f;
            dir_vertical = 1.0f;
            state = Forward_M;
            is_moving = true;
        }
        player.move(player_speed * dir_horizontal, player_speed * dir_vertical);
        
        
        // end of movement
        /*
        if (state == Forward_M)
            state = Forward;
        else if (state == Backward_M)
            state = Backward;
        else if (state == Leftward_M)
            state = Leftward;
        else if (state == Rightward_M)
            state = Rightward;
         */
        
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
                    if (!is_moving)
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
                    if (!is_moving)
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


























// the main function of Justine
using namespace std;
int justine_main()
{
    sf::RenderWindow window(sf::VideoMode(800, 900), "SFML works!");
    //sf::Music music;

    sf::RectangleShape mur(sf::Vector2f(100.0f, 100.0f));
    sf::RectangleShape mur2(sf::Vector2f(100.0f, 100.0f));
    sf::RectangleShape player_trump(sf::Vector2f(100.0f, 100.0f));
    sf::RectangleShape sol(sf::Vector2f(800.0f, 900.0f));

    sf::Texture playerTexture;
    sf::Texture solTexture;
    sf::Texture murTexture;
    sf::Texture murTexture2;

    solTexture.loadFromFile("Sources/sable.jpg");
    playerTexture.loadFromFile("Sources/trump_run.png");
    murTexture.loadFromFile("Sources/mexican.png");
    //murTexture2.loadFromFile("Sources/mexican.png");
    //if (!music.openFromFile("Jarabes.ogg"))
    {
        //    cout << "ERROR\n";
    }
    //mur2.setTexture(&murTexture2);
    mur.setTexture(&murTexture);
    player_trump.setTexture(&playerTexture);
    sol.setTexture(&solTexture);

    //mur2.setPosition(10, 100);
    mur.setPosition(10, 10);
    player_trump.setPosition(330.f, 400.f);
    float player_speed = 150.0f;


    sf::Vector2u taille = playerTexture.getSize();
    sf::IntRect a(0, 0, taille.x / 6.0f, taille.y / 4.0f);
    sf::Sprite player(playerTexture, a);
    player.setTextureRect(a);
    
    

    //sf::Vector2f position = player_trump.getPosition();
    //sf::Vector2u textureSize = playerTexture.getSize();

    sf::Clock clock;
    sf::Clock clock2;

    vector<string> frontiere = {
        "ffffffff",
        "f______f",
        "f______f",
        "f______f",
        "f______f",
        "f______f",
        "f______f",
        "f______f",
        "ffffffff",
    };

    for (size_t i = 0; i < frontiere.size(); i++)
    {
        string slt = frontiere[i];
        for (size_t t = 0; t < frontiere[0].size(); t++)
        {
            cout << slt[t];
        }
        cout << endl;
    }

    while (window.isOpen())
    {
#pragma region SFLM
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();

                break;
            }

        }
        window.clear();
#pragma endregion


        float deltaTime = clock2.restart().asSeconds();

        player_trump.setTextureRect(a);
        player_trump.setOrigin(50, 50);


        int horizontal = 0;
        int vertical = 0;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (clock.getElapsedTime().asSeconds() >= 0.1)
            {
                clock.restart();
                a.left = (a.left + (taille.x / 6)) % taille.x;
                a.top = 3 * (taille.y / 4);
                player_trump.setTextureRect(a);
            }
            if (player_trump.getPosition().x > 0)
                horizontal = -1;
            //player_trump.move(-player_speed * deltaTime, 0.f);

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (clock.getElapsedTime().asSeconds() >= 0.1)
            {
                clock.restart();
                a.left = (a.left + (taille.x / 6)) % taille.x;
                a.top = 1 * (taille.y / 4);
                player_trump.setTextureRect(a);
            }
            if (player_trump.getPosition().x < 800)
                horizontal = 1;
            //player_trump.move(player_speed * deltaTime, 0.f);

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (clock.getElapsedTime().asSeconds() >= 0.1)
            {
                clock.restart();
                a.left = (a.left + (taille.x / 6)) % taille.x;
                a.top = 2 * (taille.y / 4);
                player_trump.setTextureRect(a);
            }
            if(player_trump.getPosition().y > 0)
                vertical = -1;

            //player_trump.move(0.f, -player_speed * deltaTime);

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (clock.getElapsedTime().asSeconds() >= 0.1)
            {
                clock.restart();
                a.left = (a.left + (taille.x / 6)) % taille.x;
                a.top = 0 * (taille.y / 4);
                player_trump.setTextureRect(a);
            }
            if (player_trump.getPosition().y < 900)
                vertical = 1;
            //player_trump.move(0.f, player_speed * deltaTime);

        }

        player_trump.move(player_speed * deltaTime * horizontal, player_speed * deltaTime * vertical);




        window.draw(sol);
        for (size_t i = 0; i < frontiere.size(); i++)
        {
            string slt = frontiere[i];
            for (size_t t = 0; t < frontiere[0].size(); t++)
            {
                if (slt[t] == 'f') {
                    mur.setPosition(t * 100, i * 100);
                    window.draw(mur);
                }
            }
            cout << endl;
        }
        window.draw(player_trump);

        window.display();

    }

    return EXIT_FAILURE;
}












// second version
int origin_main()
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
    return 0;
}


/*
#include "Game.hpp"
 int     main()
{
    Game game;
    game.Run();
}
*/


// first version
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

