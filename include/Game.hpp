#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Player.hpp"
#include "World.hpp"

/**
 * \brief namespace for the book
 */

namespace book
{
    /**
     * \brief A class to manage the game
     */
    class Game
    {
        public:
            //non copyable class
            Game(const Game&) = delete;
            Game& operator=(const Game&) = delete;

            Game(int X=1600, int Y=900); //< constructor

            void run(int minimum_frame_per_seconds=30);

            void initLevel();


        private:

            void processEvents();//< Process events
            void update(sf::Time deltaTime); //< do some updates
            void render();//< draw all the stuff

            void reset();

            sf::RenderWindow _window; //< the window use to display the game
            World _world;

            sf::Time   _nextSaucer;
            sf::Text   _txt;
    };
}
#endif
// namespace book {
// /**
//  * \brief A class to manage the game
//  */
// class Game {
// public:
//   // non copyable class
//   Game(const Game &) = delete;
//   Game &operator=(const Game &) = delete;

//   Game(int X=1600, int Y=900); //< constructor

//   void runWithFixedTimeSteps(int frame_per_seconds = 60);
//   void runWithVariableTimeSteps();
//   void runWithMinimumTimeSteps(int minimum_frame_per_seconds = 30);

// private:
//   void processEvents();            //< Process events
//   void update(sf::Time deltaTime); //< do some updates
//   void render();                   //< draw all the stuff

//   sf::RenderWindow _window; //< the window use to display the game
//   book::Player _player;
//   int X; 
//   int Y;
// };
// } // namespace book
// #endif
