# pragma once
# include "constant.hpp"
# include "map.hpp"


class Map; 

class Character{

    protected:
        sf::Texture *texture;
        sf::Sprite *sprite;
        sf::Vector2<float> position;
        bool isAlive;
        float speed;
        Map *map;

    public:
        Character(); // Default constructor
        Character(Map* _map, float startX, float startY); 
        virtual ~Character();
        //Character(float Px, float Py, float Pox, float Poy); // Constructor with position parameters

        // bool isBlocked();
        sf::Vector2<float> getPosition();
        void setPosition(sf::Vector2<float> pos);
        sf::Sprite *getSprite();

        bool canMoveUp();
        bool canMoveDown();
        bool canMoveLeft();
        bool canMoveRight();

        void moveUP();
        void moveDown();
        void moveLeft();
        void moveRight();

        
        // virtual void move() = 0;
        // //Animal(float swap, std::string direction, float count);
        // void setSwap(float swap);
        // float getSwap();
        // // Setter and getter for the movement direction
        // void setDirection(std::string direction);
        // std::string getDirection();
        // void setCount(float count);
        // float getCount();
        // // Setter and getter for the life status
        // void setLife(bool life);
        // bool getLife();
        // void update() override; // Override of the update method from Sprite class     

};

