# pragma once
# include "character.hpp"

class Player: public Character{
    private:
    public:
        Player(Map* map, float startX, float startY); // Default constructor
        // Oneal(int Px, int Py, int Pox, int Poy); // Constructor with position parameters
        // void update() override; // Override of the update method from Sprite class
        ~Player() override;
};