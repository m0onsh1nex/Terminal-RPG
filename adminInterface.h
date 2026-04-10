#include"entity.h"
#include"enemy.h"
#include"hero.h"
#include<vector>
#include<string>
#include"func.cpp"

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

  void createEntity(char hOe, std::string name) {
    try {
      Entity * entity;

      switch (hOe) {
      case 'h': entity = createHero(name); break;
      case 'e': entity = createEnemy(name); break;
      _entityList.push_back(entity);
      }

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
    toLowerCase(name);
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
    std::cout << std::endl;
    std::cout << "#--- Entity List ---#" << std::endl;

    size_t listSize = _entityList.size();
    for (int i = 0; i < listSize; ++i) {
      if (i != listSize - 1) {
         std::cout << _entityList[i]->getInfo() << std::endl;
         std::cout << std::endl;
      } 
      else {
         std::cout << _entityList[i]->getInfo() << std::endl;
      }
    }

    std::cout << "#-------------------#" << std::endl;
    std::cout << std::endl;
  }
};
