#pragma once
#include "map.hpp"

class Map;
class Character; 
class Oneal;

class Game {
    public:
        Game();
        Game(int _level);
        void run();
        Map *getMap();
    
    private:
        int level = 1;
        Map *map;   
        void processEvents();
        void update();
        void render();
    
        sf::RenderWindow window;

};