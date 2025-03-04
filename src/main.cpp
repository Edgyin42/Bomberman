#include "../include/game.hpp"

using namespace std;
int main(){
    
   Game a;
   a.run();
}


// // int main() {
// //   sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Sprites");

//   // 1. Load a texture
//   sf::Texture texture;
//   if (!texture.loadFromFile("/Users/trangnguyen/Desktop/bomberman/res/textures/classic.png")) {
//     return -1; // Handle error
//   }

//   // 2. Create a sprite
//   sf::Sprite sprite(texture);
//   sprite.setTextureRect(sf::IntRect({BLOCK_WIDTH*blockTypeData.at(blockType::portal)[0], BLOCK_WIDTH*blockTypeData.at(blockType::portal)[1]}, {BLOCK_WIDTH, BLOCK_WIDTH}));

//   // 3. Set sprite position (optional)
//   sprite.setPosition({0, 0}); 
//   sprite.setScale({2.5, 2.5});
// //   // 4. Drawing loop
// //   while (window.isOpen()) {
// //       while (const std::optional event = window.pollEvent()) {
// //          if (event->is<sf::Event::Closed>())
// //                window.close();
// //          }

// //     window.clear(); // Clear the window
// //     window.draw(sprite); // Draw the sprite
// //     window.display(); // Update the display
// //   }

// //   return 0;
// // }