# include "../include/Oneal.hpp"

Oneal::Oneal(Map* map, float startX, float startY) : Character(map, startX, startY) {
    if(getSprite() != nullptr){ 
        //getSprite()->setPosition(sf::Vector2f(0, 0));
	}
    else{
        std::cerr << "Error: Sprite is null in Oneal constructor." << std::endl;
    }

}


Oneal::~Oneal(){};