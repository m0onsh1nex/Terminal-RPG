#include"entity.h"
#include"enemy.h"
#include"hero.h"
#include<vector>
#include<string>


class AdminInterface {
private:
  std::vector<Entity*> _entityList;

  Entity* createHero(std::string name) {
    const int hp = 100;
    const int lvl = 1;
    const int atk = 10;
    const int def = 0;
    Entity * _player = new Hero(name, hp, lvl, atk, def);
    return _player;
  }

  Entity* createEnemy(std::string name) {
    const int hp = 10;
    const int lvl = 0;
    const int atk = 2;
    const int def = 0;
    Enemy * _enemy = new Enemy(name, hp, lvl, atk, def);
    return _enemy;
  }

public:
  // --- Empty Constructor ---
  AdminInterface() {}

  //////////////////////
  ///   Functions   ///
  /////////////////////

  // hOe = Hero Or Enemy

  void createEntity(std::string hOe, std::string name) {
    try {
      std::transform(hOe.begin(), hOe.end(), hOe.begin(), [](unsigned char c){return std::tolower(c);});
      std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c){return std::tolower(c);});

      Entity * entity;

      if (hOe == "hero") {
        entity = createHero(name);
      } else {
        entity = createEnemy(name);
      }

      _entityList.push_back(entity);
    } catch (const std::string msg) {
      std::cout << "Error : " + msg << std::endl;
    }
  }

  // erase entity from entity list method

  // --- Getters ---
  std::vector<Entity*> getEntityList() {
    return _entityList;
  }

  Entity* getEntity(std::string name) {
      std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c){return std::tolower(c);});
      for (Entity* entity : _entityList) {
        if (entity->getName() == name) {
          return entity;
        }
      }
    std::cout << "Entity with name  '" + name + "' does not found" << std:: endl;
    return nullptr;
  }

  // -- Show entities ---
  void showAllEntities() {
    for(Entity*& entity : _entityList) {
      std::cout << entity->getInfo() << std::endl;
    }
  }
};
