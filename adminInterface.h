#include "enemy.h"
#include "entity.h"
#include "hero.h"
#include "func.cpp"

class AdminInterface {
private:
  // --- Variables --- 
  std::vector<Entity*> _entityList;
  std::unordered_map<u16, Entity*> _entityDict;

  u32 _id = 0;


  // -- Methods --- 
  Entity* createHero(u32 id, string name) {
    const int hp = 100;
    const int lvl = 1;
    const int atk = 10;
    const int def = 0;
    Entity * _player = new Hero(id, name, hp, lvl, atk, def);
    return _player;
  }

  Entity* createEnemy(u32 id, string name) {
    const int hp = 10;
    const int lvl = 0;
    const int atk = 2;
    const int def = 0;
    Enemy * _enemy = new Enemy(id, name, hp, lvl, atk, def);
    return _enemy;
  }

public:
  // --- Empty Constructor ---
  AdminInterface() {}

  /////////////////////
  ///    Methods    ///
  /////////////////////

  // hOe = Hero Or Enemy

  void createEntity(char hOe, string name) {
    try {
      Entity * entity;

      switch (hOe) {
        case 'h': entity = createHero(_id, name); break;
        case 'e': entity = createEnemy(_id, name); break;
        default: throw std::invalid_argument("Invalid entity type!");
      }
      _entityDict.insert({entity->getId(), entity});
      _id++;
      // _entityList.push_back(entity);

    } catch (const string msg) {
      std::cout << "Error : " + msg << std::endl;
    }
  }

  // erase entity from entity list method

  // --- Getters ---
  std::vector<Entity*> getEntityList() {
    return _entityList;
  }

  Entity* getEntity(string name) {
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
  
  // void showAllEntities() {
  //   std::cout << std::endl;
  //   std::cout << "#--- Entity List ---#" << std::endl;

  //   size_t listSize = _entityList.size();
  //   for (int i = 0; i < listSize; ++i) {
  //     if (i != listSize - 1) {
  //        std::cout << _entityList[i]->getInfo() << std::endl;
  //        std::cout << std::endl;
  //     } 
  //     else {
  //        std::cout << _entityList[i]->getInfo() << std::endl;
  //     }
  //   }

  //   std::cout << "#-------------------#" << std::endl;
  //   std::cout << std::endl;
  // }

  void showAllEntities_Dist() {
    std::cout << std::endl;
    std::cout << "#--- Entity List ---#" << std::endl;

    for (const auto [key , value] : _entityDict) {
      std::cout << value->getType() << "\t" << value->getName() << std::endl;
    }

    std::cout << "#-------------------#" << std::endl;
    std::cout << std::endl;
  }
};
