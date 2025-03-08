# pragma once
# include "character.hpp"

class Player: public Character{
    private:
    public:
        Player(Map* map, float startX, float startY); // Default constructor
        ~Player() override;
        int swapUpCount = 1; 
        int swapDownCount = 1; 
        int swapLeftCount = 1; 
        int swapRightCount = 1; 
        void swapUp() override; 
        void swapDown() override; 
        void swapLeft() override;  
        void swapRight() override; 
};