#include "../include/map.hpp"
#include "../include/Oneal.hpp"
#include "../include/player.hpp"
#include <sstream>   
#include <fstream>   
#include <stdexcept> 
#include <iostream> 
using namespace std; 

Map::Map() : level(1), blocks(MAP_HEIGHT), mainPlayer(new Player(this, 32, 32)) {
  if (!texture.loadFromFile("/Users/trangnguyen/Desktop/bomberman/res/textures/classic.png")){
    throw std::runtime_error ("Failed to load file classic.png");
  }
  grid = vector<vector<int>>(MAP_HEIGHT, vector<int>(MAP_WIDTH));

  addMonster();
  matchTheBlock(this->level);
}

// Parameterized Constructor (takes an int _level)
Map::Map(int _level) : level(_level), blocks(MAP_HEIGHT), mainPlayer(new Player(this, 32, 32)) {
  if (!texture.loadFromFile("/Users/trangnguyen/Desktop/bomberman/res/textures/classic.png")){
    throw std::runtime_error ("Failed to load file classic.png");
  }
  grid = vector<vector<int>>(MAP_HEIGHT, vector<int>(MAP_WIDTH));
  addMonster();
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
              // Do I need to change it to float?
              sf::IntRect* blockWall = new sf::IntRect({32*j, 32*i}, {BLOCK_WIDTH, BLOCK_WIDTH});
              break;
            }
            case 3: {
              type = blockType::brick;
              sf::IntRect* blockWall = new sf::IntRect({32*j, 32*i}, {BLOCK_WIDTH, BLOCK_WIDTH});
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
          sprite->setScale({2, 2});
          this->blocks[i].push_back(sprite);
          grid[i][j] = b;
        }
      }
  } catch (const std::exception& e) {
      std::cerr << "An exception occurred: " << e.what() << std::endl;
  }
}

vector<vector<sf::Sprite*>> Map::getBlock(){
  return this->blocks;
};


vector<Character*> Map::getMonsters (){
  return this->monsters;
};

void Map::addMonster(){
  Character *character1 = new Oneal(this, 32., 32., OnealType::OnealHorizontal, 16);
  Character *character2 = new Oneal(this, 32., 64., OnealType::OnealVertical, 16);
  this->monsters.push_back(character1);
  this->monsters.push_back(character2);
}

Character* Map::getPlayer(){
  return this->mainPlayer;
};

bool Map::isValidPosition(int row, int col) const{  
  return row >= 0 && row < MAP_WIDTH && col >= 0 && col < MAP_HEIGHT;
}

bool Map::canMove(Character *Character, Direction direction) const {
  float currentX = Character->getPosition().x;
  float currentY = Character->getPosition().y;
  
  // Character dimensions (assuming the character has a hitbox)
  float charWidth = 16;
  float charHeight = 16;
  
  // Calculate new position based on direction and movement speed
  float speed = Character->getSpeed();
  float newX = currentX;
  float newY = currentY;
  
  switch (direction) {
    case Direction::UP:
      newY -= speed;
      break;
    case Direction::RIGHT:
      newX += speed;
      break;
    case Direction::DOWN:
      newY += speed;
      break;
    case Direction::LEFT:
      newX -= speed;
      break;
  }
  
  // Calculate character hitbox in the new position
  float leftX = newX;
  float rightX = newX + charWidth;
  float topY = newY;
  float bottomY = newY + charHeight;
  
  // Check collision with walls by examining all cells the character would overlap with
  int startCol = floor(leftX / 32);
  int endCol = floor(rightX / 32);
  int startRow = floor(topY / 32);
  int endRow = floor(bottomY / 32);
  
  // Check each potentially overlapping cell
  for (int row = startRow; row <= endRow; row++) {
    for (int col = startCol; col <= endCol; col++) {
      if (!isValidPosition(row, col) || grid[row][col] != 0) {
        // Wall collision detected
        return false;
      }
    }
  }
  
  // No collision detected
  return true;
}

Map::~Map(){}; 