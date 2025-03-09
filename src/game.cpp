#include "../include/game.hpp"
Game::Game() :  window(sf::VideoMode({800, 480}), "Bomberman clone") {
    this->map = new Map(this->level);
    // Initialize game objects
}

Game::Game(int _level) :  window(sf::VideoMode({800, 480}), "Bomberman clone") {
    this->level = _level;
    this->map = new Map(this->level);
    // Initialize game objects
}

void Game::run() {
    sf::Time timePerFrame = sf::seconds(1.f / 13.f);
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (window.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
            render();
            update();
            processEvents();
        }
    }
}

void Game::processEvents() {

    while (const std::optional event = window.pollEvent()) {
        if (event) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
    }
    //The events in the while loop above, are checked for every loop.
    //Key presses, on the contrary, can be checked at any moment, regadless of the window state.
    //  THIS DOESN"T WORK 
    
}

void Game::update() {
    // Update game objects (Player, Bombs, Enemies, etc.)
    for (auto monster: map->getMonsters()){
        monster->move();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    { 
        if (map->canMove(map->getPlayer(), Direction::UP)) map->getPlayer()->moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        if (map->canMove(map->getPlayer(), Direction::DOWN)) map->getPlayer()->moveDown();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        if (map->canMove(map->getPlayer(), Direction::LEFT)) map->getPlayer()->moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        if (map->canMove(map->getPlayer(), Direction::RIGHT)) map->getPlayer()->moveRight();
    }
    
}

void Game::render() {
    window.clear();
    for (auto rows: map->getBlock()) {
        for (sf::Sprite *sp: rows){
            window.draw(*sp);
        }
    }

    for (auto monster: map->getMonsters()){
        window.draw(*monster->getSprite());
    }

    window.draw(*map->getPlayer()->getSprite());
    window.display();
}

Map* Game::getMap(){
    return map;
}