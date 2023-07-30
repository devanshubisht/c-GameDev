#include "Game.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  Player::setDefaultsInputs();
  Game game;
  game.run(30);
  return 0;
}
