#include <stdexcept> //runtime_error
#include <utility>   //forward

namespace book {
template <typename RESOURCE, typename IDENTIFIER>
template <typename... Args>
void ResourceManager<RESOURCE, IDENTIFIER>::load(const IDENTIFIER &id,
                                                 Args &&...args) {
  std::unique_ptr<RESOURCE> ptr(new RESOURCE);
  // Because all the SFML resource classes don't have the exact same parameters
  // for the loadFromFile() function (sf::Shader), I decided to use a template
  // that will forward the arguments exactly as Player::setPosition().
  if (not ptr->loadFromFile(std::forward<Args>(args)...))
    throw std::runtime_error("Impossible to load file");
  _map.emplace(id, std::move(ptr));
  // A feature from the C++11 is std::move and it allows us to use the move
  // constructor instead of the copy constructor. The std::unique_ptr template
  // class supports the type of constructor, so using it seems to be a good
  // idea. The idea under the move semantic is to dump a temporary object by
  // taking its content instead of copying it. The result is a gain in
  // performance.
}

template <typename RESOURCE, typename IDENTIFIER>
RESOURCE &
ResourceManager<RESOURCE, IDENTIFIER>::get(const IDENTIFIER &id) const {
  return *_map.at(id);
}

// sf::Music special case
template <typename IDENTIFIER>
template <typename... Args>
void ResourceManager<sf::Music, IDENTIFIER>::load(const IDENTIFIER &id,
                                                  Args &&...args) {
  std::unique_ptr<sf::Music> ptr(new sf::Music);

  if (not ptr->openFromFile(std::forward<Args>(args)...))
    throw std::runtime_error("Impossible to load file");
  _map.emplace(id, std::move(ptr));
};

template <typename IDENTIFIER>
sf::Music &
ResourceManager<sf::Music, IDENTIFIER>::get(const IDENTIFIER &id) const {
  return *_map.at(id);
}
} // namespace book
