#pragma once
#include "map.hpp"


class Game {
    public:
        Game();
        Game(int _level);
        void run();
    
    private:
        int level = 1;
        Map *map;   
        void processEvents();
        void update(sf::Time deltaTime);
        void render();
    
        sf::RenderWindow window;

};