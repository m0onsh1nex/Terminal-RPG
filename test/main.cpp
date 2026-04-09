#include <cctype>
#include<iostream>
#include<iterator>
#include<vector>
#include<string>
#include<algorithm>

class Entity {
private:
  std::string _name;
  uint _id;
public:
  Entity(std::string name) : _name(name) {}

  void die(std::vector<Entity*> &subs) {
    // Finding a position in vector
    auto el = std::find(subs.begin(), subs.end(), this);
    // Finding index of element
    int index = std::distance(subs.begin(), el);
    // Unsubscribe element
    subs.erase(subs.begin()+index);
  }
  std::string getName() {
  return _name;
  }

};


class Interface {
private:
  std::vector<Entity*> _subscribers;

public:
  Interface() {}

  void createEntity(std::string name) {
    std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c){return std::tolower(c);});
    Entity * entity = new Entity(name);
    _subscribers.push_back(entity);
  }

  std::vector<Entity*> getSubscribers() {
    return _subscribers;
  }
  
  Entity* getEntity(std::string name) {
    std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c){return std::tolower(c);});
    for (Entity* entity : _subscribers) {
        if (entity->getName() == name) {
          return entity;
      }
    }
    std::cout << "Entity with name  '" + name + "' does not found" << std:: endl;
    return nullptr;
  }
};

int main() {

  std::vector<Entity*> _subscribers;

  Interface * _interface = new Interface();

  _interface->createEntity("Hero");
  _interface->createEntity("Orc");
  _interface->createEntity("Goblin");

  for (Entity* e : _interface->getSubscribers()) {
    std::cout << e->getName() << std::endl;
  }
  std::cout << std::endl;

  std::string searchEntity;
  std::cin >> searchEntity;
  if (_interface->getEntity(searchEntity) != nullptr) {
    std::cout << _interface->getEntity(searchEntity)->getName() << std::endl;  
  }

  return 0;
}
