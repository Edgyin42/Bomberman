#include "../include/map.hpp"
#include <sstream>   
#include <fstream>   
#include <stdexcept> 
#include <iostream> 
using namespace std; 

Map::Map() : level(1), blocks(MAP_HEIGHT) {
  if (!texture.loadFromFile("/Users/trangnguyen/Desktop/bomberman/res/textures/classic.png")){
    throw std::runtime_error ("Failed to load file classic.png");
  }
  matchTheBlock(this->level);
}

// Parameterized Constructor (takes an int _level)
Map::Map(int _level) : level(_level), blocks(MAP_HEIGHT) {
  if (!texture.loadFromFile("/Users/trangnguyen/Desktop/bomberman/res/textures/classic.png")){
    throw std::runtime_error ("Failed to load file classic.png");
  }
  matchTheBlock(this->level);
}

void Map::matchTheBlock(int levelNumber){
  try {
      std::stringstream filenameStream;
      
      filenameStream << "../res/Map/Level" << levelNumber << ".txt";
      // filenameStream << "./Level1.txt";
      std::string filename = filenameStream.str();

      std::ifstream file(filename);

      if (!file.is_open()) {
          std::stringstream errorStream;
          errorStream << "Failed to open " << filename;
          throw std::runtime_error(errorStream.str());
      }
      std::string line;
      std::getline(file, line);
      std::string token;
      std::istringstream iss(line);


      for (int i = 0; i < MAP_HEIGHT; i++) {
        std::getline(file, line);
        std::istringstream stream(line);
        for (int j = 0; j < MAP_WIDTH; j++) {
          std::string a;
          stream >> a;
          int b = std::stoi(a);
          blockType type;
          switch (b) {
            case 1: {
              type = blockType::portal;
              break;
            }
            case 2: {
              type = blockType::wall;
              break;
            }
            case 3: {
              type = blockType::brick;
              break;
            }
            default: {
              type = blockType::grass;
              break;
            }
          } 
          sf::Sprite *sprite = new sf::Sprite(this->texture);
          sf::IntRect rect({BLOCK_WIDTH*blockTypeData.at(type)[0], BLOCK_WIDTH*blockTypeData.at(type)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH}); 
          //cout << rect[0][0] << " " << rect[0][1] << " " << rect[1][0] << " " << rect[1][1];
          sprite->setTextureRect(rect);
          sprite->setPosition(sf::Vector2f(32*j, 32*i));
          sprite->setScale({2.5, 2.5});
          this->blocks[i].push_back(sprite);
          //cout << *sprite << " "; 
        }
      }
  } catch (const std::exception& e) {
      std::cerr << "An exception occurred: " << e.what() << std::endl;
  }
}

vector<vector<sf::Sprite*>> Map::getBlock(){
  return this->blocks;
};