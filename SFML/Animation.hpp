//
//  Animation.hpp
//  SFML
//
//  Created by ZEMIN on 11/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#ifndef Animation_hpp
#define Animation_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Animation{
private:
    sf::Vector2u imageCount;
    sf::Vector2u currImage;
    
    float totalTime;
    float switchTime;
public:
    
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation();
    
    void Update(int row, float deltaTime, bool faceRight);
    
    sf::IntRect uvRect;
};
#endif /* Animation_hpp */
