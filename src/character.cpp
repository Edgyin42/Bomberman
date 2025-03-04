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
    if (this->map->blockX.find(this->position.x + this->speed) == this->map->blockX.end()) return true; 
    return false;
};

bool Character::canMoveDown(){
    if (this->map->blockX.find(this->position.x - this->speed) == this->map->blockX.end()) return true; 
    return false;
};

bool Character::canMoveLeft(){
    if (this->map->blockY.find(this->position.y + this->speed) == this->map->blockY.end()) return true; 
    return false;
};

bool Character::canMoveRight(){
    if (this->map->blockY.find(this->position.y - this->speed) == this->map->blockY.end()) return true; 
    return false;
};


void Character::moveUP(){
    if (canMoveUp()) position.x + speed;
    sprite->setPosition(position);
}

void Character::moveDown(){
    if (canMoveDown()) position.x - speed;
    sprite->setPosition(position);
}

void Character::moveLeft(){
    if (canMoveLeft()) position.y + speed;
    sprite->setPosition(position);
}

void Character::moveRight(){
    if (canMoveRight()) position.y - speed;
    sprite->setPosition(position);
}
