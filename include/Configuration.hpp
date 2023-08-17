#ifndef BOOK_CONFIGURATION_HPP
#define BOOK_CONFIGURATION_HPP

#include <SFML/Audio.hpp>    //Sound
#include <SFML/Graphics.hpp> //Texture

#include "ActionMap.hpp"       //ActionMap
#include "ResourceManager.hpp" //ResourceManager

namespace book {
class Player;
// forward declaration This is useful when you have situations where classes
// reference each other. By forward declaring a class, you're telling the
// compiler that the class exists, even though its complete details are not yet
// known.

class Configuration {
public:
  Configuration() = delete;
  Configuration(const Configuration &) = delete;
  Configuration &operator=(const Configuration &) = delete;

  enum Textures : int {
    Player,
    PlayerLife,
    BigSaucer,
    SmallSaucer,
    BigMeteor1,
    BigMeteor2,
    BigMeteor3,
    BigMeteor4,
    MediumMeteor1,
    MediumMeteor2,
    SmallMeteor1,
    SmallMeteor2,
    SmallMeteor3,
    SmallMeteor4,
    ShootPlayer,
    ShootSaucer,
  };
  static ResourceManager<sf::Texture, int> textures;

  enum Fonts : int { Gui };
  static ResourceManager<sf::Font, int> fonts;

  enum PlayerInputs : int { Up, Left, Right, Shoot, Hyperspace };

  enum Sounds : int {
    LaserPlayer,
    LaserEnemy,
    SaucerSpawn1,
    SaucerSpawn2,
    Boom,
    Boom2,
    Explosion1,
    Explosion2,
    Explosion3,
    Jump,
  };
  static ResourceManager<sf::SoundBuffer, int> sounds;

  enum Musics : int { Theme };
  static ResourceManager<sf::Music, int> musics;

  static ActionMap<int> playerInputs;

  static void initialize();
  static void reset();

  static bool isGameOver();

  static void addScore(int s);
  static int getScore();

  static book::Player *player;
  static int level;
  static int lives;

  static void draw(sf::RenderTarget &target);

private:
  static int _score;
  static sf::Text _txt_score;
  static sf::Sprite _spr_life;

  static void initTextures();
  static void initFonts();
  static void initSounds();
  static void initMusics();

  static void initPlayerInputs();
};
} // namespace book
#endif
