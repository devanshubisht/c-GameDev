#ifndef BOOK_CONFIGURATION_HPP
#define BOOK_CONFIGURATION_HPP

#include <SFML/Graphics.hpp> //Texture

#include "ActionMap.hpp"       //ActionMap
#include "ResourceManager.hpp" //ResourceManager

namespace book {
class Configuration {
public:
  Configuration() = delete;
  Configuration(const Configuration &) = delete;
  Configuration &operator=(const Configuration &) = delete;

  enum Textures : int { Player };
  static ResourceManager<sf::Texture, int> textures;

  enum PlayerInputs : int { Up, Left, Right };
  static ActionMap<int> playerInputs;

  static void initialize();

private:
  static void initTextures();

  static void initPlayerInputs();
};
} // namespace book
#endif
