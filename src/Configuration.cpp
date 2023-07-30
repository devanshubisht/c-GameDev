#include "../include/Configuration.hpp"

namespace book {

  //why do i need to declare again the static variables?
ResourceManager<sf::Texture, int> Configuration::textures;
ActionMap<int> Configuration::playerInputs;

void Configuration::initialize() {
  initTextures();
  initPlayerInputs();
}

void Configuration::initTextures() {
  //Textures::Player is the identifier.
  textures.load(Textures::Player, "../media/Player/Ship.png");
}

void Configuration::initPlayerInputs() {
  playerInputs.map(PlayerInputs::Up, Action(sf::Keyboard::Up));
  playerInputs.map(PlayerInputs::Right, Action(sf::Keyboard::Right));
  playerInputs.map(PlayerInputs::Left, Action(sf::Keyboard::Left));
}
} // namespace book
