#ifndef BOOK_RESOURCEMANAGER_HPP
#define BOOK_RESOURCEMANAGER_HPP

#include <memory>        //unique_ptr
#include <string>        //string
#include <unordered_map> //unordered_map

#include <SFML/Audio.hpp> //sf::Music

namespace book {
template <typename RESOURCE, typename IDENTIFIER = int> class ResourceManager {
public:
  ResourceManager(const ResourceManager &) = delete;
  ResourceManager &operator=(const ResourceManager &) = delete;

  ResourceManager() = default;

  template <typename... Args> void load(const IDENTIFIER &id, Args &&...args);

  RESOURCE &get(const IDENTIFIER &id) const;

private:
  std::unordered_map<IDENTIFIER, std::unique_ptr<RESOURCE>> _map;
  // some items cannot be copied so we need to use a pointer to store them in a
  // container.
};

// Because our actual ResourceManager class uses loadFromFile() in the load()
// method, we have a problem with the sf::Music class. LoadFromFile(), which
// doesn't exist in the sf::Music class and is replaced with openFromFile(). So
// we need to fix that.
// To do this, we will use the partial specialization.The partial specialization
// is a technical used in template programming to make some special case,exactly
// like this one .We need to specialize the load() method when RESOURCE is set to
// sf::Music. The problem is that we can't do it directly because the ResourceManager
// class has two template
// parameters, and the other one doesn' t need to be fixed.So instead, we
// have to specialize the entire class by creating a new one :

template <typename IDENTIFIER> class ResourceManager<sf::Music, IDENTIFIER> {
public:
  ResourceManager(const ResourceManager &) = delete;
  ResourceManager &operator=(const ResourceManager &) = delete;

  ResourceManager() = default;

  template <typename... Args> void load(const IDENTIFIER &id, Args &&...args);

  sf::Music &get(const IDENTIFIER &id) const;

private:
  std::unordered_map<IDENTIFIER, std::unique_ptr<sf::Music>> _map;
};

} // namespace book
#include "ResourceManager.tpl"

#endif
