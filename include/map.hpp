
# pragma once 

# include <SFML/Graphics.hpp>
#include "constant.hpp"
#include "character.hpp"
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
    Character *mainPlayer;
    bool isValidPosition(int row, int col) const; 


    // bool canMoveTo(int row, int col) const; 

    
    
    public: 
    bool canMove(Character *Character, Direction direction) const; 
    Map(); 
    Map(int _level);
    void matchTheBlock(int level); 
    vector<vector<sf::Sprite*>> getBlock();
    vector<Character*> getMonsters();
    vector<vector<int> > grid;
    Character *getPlayer();
    void addMonster();
    ~Map(); 
};
