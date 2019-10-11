//
//  main.cpp
//  SFML
//
//  Created by ZEMIN on 10/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "Game.hpp"

int     main()
{
    Game game;
    game.Run();
}


























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

