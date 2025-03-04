# pragma once
# include <map>
# include <iostream>
# include <vector>
# include <SFML/Graphics.hpp>

using namespace std;

const int MAP_WIDTH = 25; 
const int MAP_HEIGHT = 15; 
const int BLOCK_WIDTH = 16; // On the spritesheet

enum blockType{
    portal,
    brick,  
    wall,
    grass, 
}; 

enum bomberman {
    walkingUp1, 
    walkingUp2, 
    walkingUp3, 
    walkingDown1, 
    walkingDown2,
    walkingDown3, 
    walkingLeft1,
    walkingLeft2,
    walkingLeft3, 
    walkingRight1,
    walkingRight2,
    walkingRight3,
    dying1,
    dying2,
    dying3
};

enum oneal { // The one moving left and right or up and down consistently
    oneal1,
    oneal2,
    oneal3,
    oneal4,
    oneal5,
    oneal6,
    onealDying
};

const std::map<blockType, std::vector<int>> blockTypeData = {
    {blockType::portal, {4, 0}},
    {blockType::wall,   {5, 0}},
    {blockType::grass,  {6, 0}},
    {blockType::brick,  {7, 0}}, 
};

//Bomberman data
const std::map<bomberman, std::vector<int>> bombermanData = {
    {bomberman::walkingUp1,   {0, 0}}, 
    {bomberman::walkingUp2,   {0, 1}}, 
    {bomberman::walkingUp3,   {0, 2}}, 
    {bomberman::walkingDown1,   {2, 0}}, 
    {bomberman::walkingDown2,   {2, 1}}, 
    {bomberman::walkingDown3,   {2, 2}}, 
    {bomberman::walkingLeft1,  {1, 0}},
    {bomberman::walkingLeft2,  {1, 1}},
    {bomberman::walkingLeft3,  {1, 2}},
    {bomberman::walkingRight1, {3, 0}},
    {bomberman::walkingRight2, {3, 1}},
    {bomberman::walkingRight3, {3, 2}},
    {bomberman::dying1,     {4, 2}},
    {bomberman::dying2,     {5, 2}},
    {bomberman::dying3,     {6, 2}}
};

const std::map<oneal, std::vector<int> >onealData = {
    {oneal::oneal1,  {11, 0}}, 
    {oneal::oneal2,  {11, 1}}, 
    {oneal::oneal3,  {11, 2}}, 
    {oneal::oneal4,  {12, 0}}, 
    {oneal::oneal5,  {12, 1}}, 
    {oneal::oneal6,  {12, 2}}, 
    {oneal::onealDying,  {11, 3}}, 
};

// const std::map<Valcom, std::array<int, 2>> bombData = {
//     {bombState::unexploded, {0, 5}}, // Example.  You'll likely have multiple frames for ticking.
// };

// const std::map<Minvo, std::array<int, 2>> bombData = {
//     {bombState::unexploded, {0, 5}}, // Example.  You'll likely have multiple frames for ticking.
// };

// const std::map<Doria, std::array<int, 2>> bombData = {
//     {bombState::unexploded, {0, 5}}, // Example.  You'll likely have multiple frames for ticking.
// };

// const std::map<Dahl, std::array<int, 2>> bombData = {
//     {bombState::unexploded, {0, 5}}, // Example.  You'll likely have multiple frames for ticking.
// };

// const std::map<flameState, std::array<int, 2>> flameData = {
//     {flameState::center, {0, 6}},      //Center
//     {flameState::horizontal, {1, 6}}, //horizontal
//     {flameState::vertical, {0, 7}}, //Vertical
//     {flameState::upEnd, {0,8}},          //Up
//     {flameState::downEnd, {0,8}},        //Down
//     {flameState::leftEnd, {1,8}},        //Left
//     {flameState::rightEnd, {1,8}},       //Right
// };

// const std::map<powerUpType, std::array<int, 2>> powerUpData = {
//     {powerUpType::bombUp,      {0, 11}}, // Example
//     {powerUpType::flameUp,     {1, 11}},
//     {powerUpType::speedUp,     {2, 11}},
//     {powerUpType::detonator, {3, 11}},
//      //{powerUpType::pierceBomb, {4, 11}},
//      //{powerUpType::kick,      {5, 11}},
//      //{powerUpType::punch,     {6, 11}},
//     // ... Add more power-ups ...
// };


// void setSpriteTextureRect(sf::Sprite *sprite, blockType type, int i, int j){ 
    
//     try {
//         sf::Texture texture;
//         // Check if the file is loaded successfully
//         if (!texture.loadFromFile("./res/textures/classic.png")){
//             throw std::runtime_error ("Failed to load file classic.png");
//         }
//         if (blockTypeData.count(type) == 0) { // Check if the blockType exists in the map
//             throw std::runtime_error ("Invalid blockType provided");
//         }
//         sprite->setTextureRect(sf::IntRect({blockTypeData[type][0], blockTypeData[type][1]}, {BLOCK_WIDTH, BLOCK_WIDTH}));
//         sprite->setPosition(sf::Vector2f(32.f*i, 32.f*j));
//         sprite->setTexture(texture);
//     } catch (const std::exception& e){
//         std::cerr << "An exception occurred: " << e.what() << std::endl;
//     }
    
// }