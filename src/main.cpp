#include "../include/ActionMap.hpp"
#include "../include/Game.hpp"

#include "../include/Configuration.hpp"

int main(int argc, char *argv[]) {
  book::Configuration::initialize();

  book::Game game;
  game.run();

  return 0;
}
