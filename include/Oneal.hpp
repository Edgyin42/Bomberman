
# pragma once
# include "character.hpp"

class Map;

class Oneal: public Character{
    private:
    public:
        Oneal(Map* map, float startX, float startY); // Default constructor
        // Oneal(int Px, int Py, int Pox, int Poy); // Constructor with position parameters
        // void update() override; // Override of the update method from Sprite class
        ~Oneal() override;
};