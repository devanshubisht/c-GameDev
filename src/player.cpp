#include "../include/Player.hpp"
#include <cmath> //sin, cos

#include "../include/Configuration.hpp" //Configuration
#include "../include/Collision.hpp" //Collision
#include "../include/World.hpp" //World
#include "../include/Shoot.hpp" //ShootPlayer
#include "../include/random.hpp" //random

namespace book
{
    Player::Player(World& world) : Entity(Configuration::Textures::Player,world)
                       ,ActionTarget(Configuration::playerInputs)
                       ,_isMoving(false)
                       ,_rotation(0)
    {
        bind(Configuration::PlayerInputs::Up,[this](const sf::Event&){
             _isMoving = true;
        });

        bind(Configuration::PlayerInputs::Left,[this](const sf::Event&){
             _rotation-= 1;
         });

        bind(Configuration::PlayerInputs::Right,[this](const sf::Event&){
             _rotation+= 1;
         });

        bind(Configuration::PlayerInputs::Shoot,[this](const sf::Event&){
             shoot();
         });

        bind(Configuration::PlayerInputs::Hyperspace,[this](const sf::Event&){
             goToHyperspace();
         });
    }

    bool Player::isCollide(const Entity& other)const
    {
        if(dynamic_cast<const ShootPlayer*>(&other) == nullptr)
        {
            return Collision::circleTest(_sprite,other._sprite);
        }
        return false;
    }

    void Player::shoot()
    {
        if(_timeSinceLastShoot > sf::seconds(0.3))
        {
            _world.add(new ShootPlayer(*this));
            _timeSinceLastShoot = sf::Time::Zero;
        }
    }

    void Player::goToHyperspace()
    {
        _impulse = sf::Vector2f(0,0);
        setPosition(random(0,_world.getX()),random(0,_world.getY()));
        _world.add(Configuration::Sounds::Jump);

    }

    void Player::onDestroy()
    {
        Entity::onDestroy();
        Configuration::player = nullptr;
        Configuration::lives--;
        _world.add(Configuration::Sounds::Boom);
    }

    void Player::processEvents()
    {
        _isMoving = false;
        _rotation = 0;
        ActionTarget::processEvents();
    }

    void Player::update(sf::Time deltaTime)
    {
        float seconds = deltaTime.asSeconds();

        _timeSinceLastShoot += deltaTime;

        if(_rotation != 0)
        {
            float angle = _rotation*250*seconds;
            _sprite.rotate(angle);
        }
        
        if(_isMoving)
        { 
            float angle = _sprite.getRotation() / 180 * M_PI - M_PI / 2;
            _impulse += sf::Vector2f(std::cos(angle),std::sin(angle)) * 300.f * seconds;
        }

        _sprite.move(seconds * _impulse);
    }
}


// #include "../include/Player.hpp"
// #include <cmath> //sin, cos

// #include "../include/Configuration.hpp" //Configuratio

// namespace book {
// Player::Player()
//     : ActionTarget(Configuration::playerInputs), _is_moving(false),
//       _rotation(0) {
//   _ship.setTexture(
//       Configuration::textures.get(Configuration::Textures::Player));
//   _ship.setOrigin(49.5, 37.5);

//   bind(Configuration::PlayerInputs::Up,
//        [this](const sf::Event &) { _is_moving = true; });

//   bind(Configuration::PlayerInputs::Left,
//        [this](const sf::Event &) { _rotation -= 1; });

//   bind(Configuration::PlayerInputs::Right,
//        [this](const sf::Event &) { _rotation += 1; });
// }

// void Player::processEvents() {
//   _is_moving = false;
//   _rotation = 0;
//   ActionTarget::processEvents();
// }

// void Player::update(sf::Time deltaTime) {
//   float seconds = deltaTime.asSeconds();

//   if (_rotation != 0) {
//     float angle = _rotation * 180 * seconds;
//     _ship.rotate(angle);
//   }

//   if (_is_moving) {
//     float angle = _ship.getRotation() / 180 * M_PI - M_PI / 2;
//     _velocity +=
//         sf::Vector2f(std::cos(angle), std::sin(angle)) * 60.f * seconds;
//   }

//   _ship.move(seconds * _velocity);
// }

// const sf::Vector2f &Player::getPosition() const { return _ship.getPosition(); }

// void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//   target.draw(_ship, states);
// }

// } // namespace book