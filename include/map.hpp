
# pragma once 

# include <SFML/Graphics.hpp>
#include "constant.hpp"
#include "Oneal.hpp"
# include <unordered_set>
# include <string>
using namespace std;

class Character;


class Map{
    private: 
    sf::Texture texture;
    int level;
    vector<vector<sf::Sprite *> > blocks;
    vector<Character*> monsters;
    
    
    public: 
    Map(); 
    Map(int _level);
    void matchTheBlock(int level); 
    vector<vector<sf::Sprite*>> getBlock();
    vector<Character*> getMonsters();


    unordered_set<int> blockX; // All the X position of walls
    unordered_set<int> blockY; // All the Y position of walls
    void addMonster();
    ~Map(); 
};
