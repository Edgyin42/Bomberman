# include "../include/Oneal.hpp"
# include "../include/map.hpp"

Oneal::Oneal(Map* map, float startX, float startY, enum OnealType _type, float _speed) : Character(map, startX, startY) {
    type = _type;
    speed = _speed;
    if(getSprite() != nullptr){ 
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*onealData.at(oneal::oneal1)[0], BLOCK_WIDTH*onealData.at(oneal::oneal1)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH}));
        sprite->setScale({2, 2});
	}
    else{
        std::cerr << "Error: Sprite is null in Oneal constructor." << std::endl;
    }

}

Oneal::~Oneal(){};


void Oneal::swapUp(){
    cout << "enter" << endl;
    switch (swapCount)
    {
    case 2:
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*onealData.at(oneal::oneal2)[0], BLOCK_WIDTH*onealData.at(oneal::oneal2)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH})); 
        swapCount++;
        break;
    
    case 3: 
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*onealData.at(oneal::oneal3)[0], BLOCK_WIDTH*onealData.at(oneal::oneal3)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH}));
        swapCount++;
        break;

    case 4: 
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*onealData.at(oneal::oneal4)[0], BLOCK_WIDTH*onealData.at(oneal::oneal4)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH}));
        swapCount++;
        break;

    case 5: 
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*onealData.at(oneal::oneal5)[0], BLOCK_WIDTH*onealData.at(oneal::oneal5)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH}));
        swapCount++;
        break;

    case 6: 
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*onealData.at(oneal::oneal6)[0], BLOCK_WIDTH*onealData.at(oneal::oneal6)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH}));
        swapCount = 1;
        break;
    default:
        sprite->setTextureRect(sf::IntRect({BLOCK_WIDTH*onealData.at(oneal::oneal1)[0], BLOCK_WIDTH*onealData.at(oneal::oneal1)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH}));
        swapCount++;
        break;
    }

}


void Oneal::move(){
    static Direction currentDirection = Direction::LEFT; // Add static variable to remember direction
    
    if (type == OnealType::OnealHorizontal){
        bool canMoveInCurrentDirection;
        
        // Check if we can move in current direction
        if (currentDirection == Direction::LEFT) {
            canMoveInCurrentDirection = map->canMove(this, Direction::LEFT);
            
            if (canMoveInCurrentDirection) {
                moveLeft();
            } else {
                // Change direction if we hit a wall
                currentDirection = Direction::RIGHT;
                moveRight();
            }
        } else { // currentDirection == Direction::RIGHT
            canMoveInCurrentDirection = map->canMove(this, Direction::RIGHT);
            
            if (canMoveInCurrentDirection) {
                moveRight();
            } else {
                // Change direction if we hit a wall
                currentDirection = Direction::LEFT;
                moveLeft();
            }
        }
    } else { // OnealVertical
        static Direction verticalDirection = Direction::UP; // Add static variable for vertical direction
        
        if (verticalDirection == Direction::UP) {
            if (map->canMove(this, Direction::UP)) {
                moveUp();
            } else {
                verticalDirection = Direction::DOWN;
                moveDown();
            }
        } else { // verticalDirection == Direction::DOWN
            if (map->canMove(this, Direction::DOWN)) {
                moveDown();
            } else {
                verticalDirection = Direction::UP;
                moveUp();
            }
        }
    }
}