#ifndef GAME_H
#define GAME_H

#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Game {
public:
  Game(const Game &) = delete;
  Game &operator=(const Game &) = delete;
  Game();
  void run(int frame_per_seconds);

private:
  void processEvents();
  void update(sf::Time deltaTime);
  void render();
  sf::RenderWindow _window;
  Player _player;
};

#endif