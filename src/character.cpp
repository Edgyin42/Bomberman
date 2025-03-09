# include "../include/character.hpp"
// Fix the default constructor later
Character::Character() :sprite(nullptr), texture(nullptr), map(nullptr), isAlive(true){
    texture = new sf::Texture();

    if (!this->texture->loadFromFile("../res/textures/classic.png")){
        delete texture;
        texture = nullptr;
        throw std::runtime_error ("Failed to load file classic.png");
    }
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(sf::Vector2f(32, 32));
}

Character::Character(Map* _map, float startX, float startY): sprite(nullptr), texture(nullptr), speed(16), isAlive(true){
    this->position.x = startX;
    this->position.y = startY;
    this->map = _map;

    texture = new sf::Texture();

    if (!this->texture->loadFromFile("../res/textures/classic.png")){
        delete texture;
        texture = nullptr;
        throw std::runtime_error ("Failed to load file classic.png");
    }
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(this->position);
}

sf::Sprite*  Character::getSprite(){
    return this->sprite;
}

Character::~Character(){
    if (sprite) {
        delete sprite;
        sprite = nullptr;
    }
    if (texture) {
        delete texture; 
        texture = nullptr;
    }
}

sf::Vector2<float> Character::getPosition(){
    return this->position;
};


void Character::setPosition(sf::Vector2<float> pos){
    this->position = pos;
}



bool Character::canMoveUp(){

    // for (const auto& dir : DIRECTIONS) {
    //     castRay(bombRow, bombCol, dir.first, dir.second, explosionRange);
    // }
    int block_x = floor(position.x / 32);
    int block_y = ceil(position.y / 32) - 1;
    cout << "block " << block_y << " " << block_x << endl; 
    if (this->map->grid[block_y][block_x] == 0) return true; 
    return false;
};

bool Character::canMoveDown(){
    
    int block_x = floor(position.x / 32);
    int block_y = floor(position.y/ 32) + 1;;
    cout << "block " << block_y << " " << block_x << endl; 
    if (this->map->grid[block_y][block_x] == 0) return true; 
    return false;
};

bool Character::canMoveLeft(){
    cout << "position " << position.y << " " << position.x << endl; 
    int block_x = ceil(position.x / 32) - 1;
    int block_y = floor(position.y / 32);
    cout << "block " << block_y << " " << block_x << endl; 
    if (this->map->grid[block_y][block_x] == 0) return true; 
    return false;
};

bool Character::canMoveRight(){
    int block_x = floor(position.x / 32) + 1;
    int block_y = floor(position.y / 32);
    cout << "block " << block_y << " " << block_x << endl; 
    if (this->map->grid[block_y][block_x] == 0) return true; 
    return false;
};

// bool Character::canMoveUp(){
//     // Check if character can move up by checking the grid cell above
//     int block_x = floor(position.x / 32);
//     int block_y = ceil(position.y / 32) - 1);
    
//     return this->map->grid[block_y][block_x] == 0;
// }

// bool Character::canMoveDown(){
//     // Check if character can move down by checking the grid cell below
//     int block_x = floor(position.x / 32);
//     int block_y = floor(position.y / 32 + 1);
    
//     return this->map->grid[block_y][block_x] == 0;
// }

// bool Character::canMoveLeft(){
//     // Check if character can move left by checking the grid cell to the left
//     int block_x = floor(position.x / 32 - 1);
//     int block_y = floor(position.y / 32);
    
//     return this->map->grid[block_y][block_x] == 0;
// }

// bool Character::canMoveRight(){
//     // Check if character can move right by checking the grid cell to the right
//     int block_x = floor(position.x / 32  + 1);
//     int block_y = floor(position.y / 32);
    
//     return this->map->grid[block_y][block_x] == 0;
// }


void Character::moveUp(){
    position.y -= speed;
    swapUp();
    sprite->setPosition(position);
}

void Character::moveDown(){
    position.y += speed;
    swapDown();
    sprite->setPosition(position);
}

void Character::moveLeft(){
    position.x -= speed;
    swapLeft();
    sprite->setPosition(position);
}

void Character::moveRight(){
    position.x += speed;
    swapRight();
    sprite->setPosition(position);
}



float Character::getSpeed(){
    return speed;
}