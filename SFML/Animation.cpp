//
//  Animation.cpp
//  SFML
//
//  Created by ZEMIN on 11/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "Animation.hpp"
Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currImage.x = 0;
    
    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{
    
}

void Animation::Update(int row, float deltaTime, bool faceRight)
{
    currImage.y = row;
    totalTime += deltaTime;
    
    if (totalTime >= switchTime)
    {
        totalTime-= switchTime;
        currImage.x++;
    }
    
    uvRect.top = currImage.y * uvRect.height;
    if(faceRight)
    {
        uvRect.left = currImage.x * uvRect.width;
    }
    else
    {
        uvRect.left = ( currImage.x + 1) * uvRect.width;
    }
}
