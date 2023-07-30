#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Player::Player()
    : ActionTarget(_playerInputs), _shape(sf::Vector2f(32, 32)),
      _is_moving(false), _rotation(0) {
  _shape.setFillColor(sf::Color::Blue);
  _shape.setOrigin(16, 16);
  bind(PlayerInputs::Up, [this](const sf::Event &) { _is_moving = true; });
  bind(PlayerInputs::Left, [this](const sf::Event &) { _rotation -= 1; });
  bind(PlayerInputs::Right, [this](const sf::Event &) { _rotation += 1; });
}

void Player::update(sf::Time deltaTime) {
  float seconds = deltaTime.asSeconds();
  if (_rotation != 0) {
    float angle = (_rotation > 0 ? 1 : -1) * 180 * seconds;
    _shape.rotate(angle);
  }
  if (_is_moving) {
    float angle = _shape.getRotation() / 180 * M_PI - M_PI / 2;
    _velocity +=
        sf::Vector2f(std::cos(angle), std::sin(angle)) * 60.f * seconds;
  }
  _shape.move(seconds * _velocity);
}

void Player::processEvents() {
  _is_moving = false;
  _rotation = 0;
  ActionTarget::processEvents();
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(_shape, states);
}

void Player::setDefaultsInputs() {
  _playerInputs.map(PlayerInputs::Up, Action(sf::Keyboard::Up));
  _playerInputs.map(PlayerInputs::Right, Action(sf::Keyboard::Right));
  _playerInputs.map(PlayerInputs::Left, Action(sf::Keyboard::Left));
}
ActionMap<int> Player::_playerInputs;
