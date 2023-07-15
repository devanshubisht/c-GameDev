#include "game.hpp"

Game::Game() : _window(sf::VideoMode(800, 600), "02_Game_Archi"), _player()
{
   //_player.setFillColor(sf::Color::Blue);
    _player.setPosition(50, 50);
}

void Game::run(int frame_per_seconds)
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f / frame_per_seconds);
    while (_window.isOpen())
    {
        processEvents();

        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            update(TimePerFrame);
        }

        update(timeSinceLastUpdate);
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
        {
            _window.close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
                _window.close();
            else if (event.key.code == sf::Keyboard::Up)
                _player.isMoving = true;
            else if (event.key.code == sf::Keyboard::Left)
                _player.rotation = -1;
            else if (event.key.code == sf::Keyboard::Right)
                _player.rotation = 1;
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Up)
                _player.isMoving = false;
            else if (event.key.code == sf::Keyboard::Left)
                _player.rotation = 0;
            else if (event.key.code == sf::Keyboard::Right)
                _player.rotation = 0;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    // Update game logic here
}

void Game::render()
{
    _window.clear();
    _window.draw(_player);
    _window.display();
}