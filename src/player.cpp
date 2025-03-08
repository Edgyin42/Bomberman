# include "../include/player.hpp"

Player::Player(Map* map, float startX, float startY): Character(map, startX, startY){
    if(getSprite() != nullptr){ 
        // getSprite()->setPosition(sf::Vector2f(0, 0));
	}
    else{
        std::cerr << "Error: Sprite is null in Oneal constructor." << std::endl;
    }
    sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*bombermanData.at(bomberman::walkingDown1)[0], BLOCK_WIDTH*bombermanData.at(bomberman::walkingDown1)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH}));
    sprite->setScale({2, 2});
}

Player::~Player(){};


void Player::swapUp(){
    switch (swapUpCount)
    {
    case 2:
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*bombermanData.at(bomberman::walkingUp2)[0], BLOCK_WIDTH*bombermanData.at(bomberman::walkingUp2)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH})); 
        swapUpCount++;
        break;
    
    case 3: 
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*bombermanData.at(bomberman::walkingUp3)[0], BLOCK_WIDTH*bombermanData.at(bomberman::walkingUp3)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH}));
        swapUpCount = 1;
        break;
    default:
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*bombermanData.at(bomberman::walkingUp1)[0], BLOCK_WIDTH*bombermanData.at(bomberman::walkingUp1)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH})
    );
        swapUpCount++;
        break;
    }
}; 

void Player::swapDown(){
    switch (swapDownCount)
    {
    case 2:
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*bombermanData.at(bomberman::walkingDown2)[0], BLOCK_WIDTH*bombermanData.at(bomberman::walkingDown2)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH})); 
        swapDownCount++;
        break;
    
    case 3: 
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*bombermanData.at(bomberman::walkingDown3)[0], BLOCK_WIDTH*bombermanData.at(bomberman::walkingDown3)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH}));
        swapDownCount = 1;
        break;
    default:
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*bombermanData.at(bomberman::walkingDown1)[0], BLOCK_WIDTH*bombermanData.at(bomberman::walkingDown1)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH})
    );
        swapDownCount++;
        break;
    }
}; 

void Player::swapLeft(){
    switch (swapLeftCount)
    {
    case 2:
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*bombermanData.at(bomberman::walkingLeft2)[0], BLOCK_WIDTH*bombermanData.at(bomberman::walkingLeft2)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH})); 
        swapLeftCount++;
        break;
    
    case 3: 
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*bombermanData.at(bomberman::walkingLeft3)[0], BLOCK_WIDTH*bombermanData.at(bomberman::walkingLeft3)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH}));
        swapLeftCount = 1;
        break;
    default:
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*bombermanData.at(bomberman::walkingLeft1)[0], BLOCK_WIDTH*bombermanData.at(bomberman::walkingLeft1)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH})
    );
        swapLeftCount++;
        break;
    }
}; 

void Player::swapRight(){
    switch (swapRightCount)
    {
    case 2:
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*bombermanData.at(bomberman::walkingRight2)[0], BLOCK_WIDTH*bombermanData.at(bomberman::walkingRight2)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH})); 
        swapRightCount++;
        break;
    
    case 3: 
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*bombermanData.at(bomberman::walkingRight3)[0], BLOCK_WIDTH*bombermanData.at(bomberman::walkingRight3)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH}));
        swapRightCount = 1;
        break;
    default:
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*bombermanData.at(bomberman::walkingRight1)[0], BLOCK_WIDTH*bombermanData.at(bomberman::walkingRight1)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH})
    );
        swapRightCount++;
        break;
    }
};