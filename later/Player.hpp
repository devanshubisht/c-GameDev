#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "ActionTarget.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Player : public sf::Drawable,
               public ActionTarget<int>

{
public:
  Player(const Player &) = delete;
  Player &operator=(const Player &) = delete;
  Player();
  //  the right value reference or, in this context, the forwarding/universal
  //  reference.
  // This allows us to catch any kind of type by simply adding &&. The final
  // signature of the function now is as follows:
  template <typename... Args> void setPosition(Args &&...args) {
    _shape.setPosition(std::forward<Args>(args)...);
  }
  void update(sf::Time deltaTime);

  void processEvents();

  enum PlayerInputs { Up, Left, Right };
  static void setDefaultsInputs();
  bool _is_moving;
  int _rotation;

private:
  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const override;
  sf::RectangleShape _shape;
  sf::Vector2f _velocity;

  static ActionMap<int> _playerInputs;
};

#endif