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
    if (type == OnealType::OnealHorizontal){
        bool moveLeftCheck = map->canMove(this, Direction::LEFT);
        bool moveRightCheck = map->canMove(this, Direction::RIGHT);
        // cout << position.x << " " << position.y << endl;
        // cout << moveLeftCheck << " " << moveRightCheck << endl;
        // if (moveLeftCheck && !moveRightCheck || moveLeftCheck && moveRightCheck ){
        if (moveLeftCheck){
            moveLeft();
            // cout << "enter1" << endl;
        } else {
            moveRight();
            // cout << "enter2" << endl;
        }
    } else {
        bool moveUpCheck = map->canMove(this, Direction::UP);
        bool moveDownCheck = map->canMove(this, Direction::DOWN);
        // cout << position.x << " " << position.y << endl;
        // cout << moveLeftCheck << " " << moveRightCheck << endl;
        // if (moveLeftCheck && !moveRightCheck || moveLeftCheck && moveRightCheck ){
        if (moveUpCheck){
            moveUp();
            // cout << "enter1" << endl;
        } else {
            moveDown();
            // cout << "enter2" << endl;
        }
    }
}