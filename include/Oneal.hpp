
# pragma once
# include "character.hpp"

class Map;

enum OnealType{
    OnealHorizontal, 
    OnealVertical
};

class Oneal: public Character{
    private:
        Direction currentHorizontalDirection = Direction::LEFT;
        Direction currentVerticalDirection = Direction::UP;
    public:
        Oneal(Map* map, float startX, float startY, enum OnealType _type, float _speed); // Default constructor
        // Oneal(int Px, int Py, int Pox, int Poy); // Constructor with position parameters
        // void update() override; // Override of the update method from Sprite class
        ~Oneal() override;
        enum OnealType type = OnealHorizontal;
        int swapCount = 1;

        void swapUp() override; 

        void move() override;
};