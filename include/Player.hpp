#ifndef BOOK_PLAYER_HPP
#define BOOK_PLAYER_HPP

#include <SFML/Graphics.hpp>

#include "ActionTarget.hpp" //ActionTarget

namespace book {
class Player : public sf::Drawable, public ActionTarget<int> {
public:
  Player(const Player &) = delete;
  Player &operator=(const Player &) = delete;

  Player();

  template <typename... Args> void setPosition(Args &&...args);

  void processEvents();

  void update(sf::Time deltaTime);

  const sf::Vector2f& getPosition() const;

private:
  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const override;

  sf::Sprite _ship;
  sf::Vector2f _velocity;

  bool _is_moving;
  int _rotation;
};
} // namespace book
#include "Player.tpl"
#endif
