#ifndef ACTIONMAP_TPL
#define ACTIONMAP_TPL

// The actual template function definitions go here
template <typename T>
void ActionMap<T>::map(const T &key, const Action &action) {
  _map.emplace(key, action);
}

template <typename T> const Action &ActionMap<T>::get(const T &key) const {
  return _map.at(key);
}

#endif // ACTIONMAP_TPL