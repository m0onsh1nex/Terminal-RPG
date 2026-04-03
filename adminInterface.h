#include"entity.h"
#include"enemy.h"
#include"hero.h"
#include<vector>
#include<string>


class AdminInterface {
private:
  std::vector<Entity*> _entityList;
public:
  // --- Empty Constructor ---
  AdminInterface() {}

  //////////////////////
  ///   Functions   ///
  /////////////////////

  void createHero(std::string name) {
    const int hp = 100;
    const int lvl = 1;
    const int atk = 10;
    const int def = 0;
    Entity * _player = new Hero(name, hp, lvl, atk, def);
    _entityList.push_back(_player);
  }

  void createGoblin() {
    const std::string name = "GOBLIN";
    const int hp = 10;
    const int lvl = 0;
    const int atk = 2;
    const int def = 0;
    Enemy * _goblin = new Enemy(name, hp, lvl, atk, def);
    _entityList.push_back(_goblin);
  }

  void deleteEntity(Entity * entity) {
    for(int i = 0; i < _entityList.size(); ++i) {
      if (_entityList[i] == entity) {
        _entityList.erase(_entityList.begin() + i);
      }
    }
  }

  void showAllEntities() {
    for(Entity*& entity : _entityList) {
      std::cout << entity->getInfo() << std::endl;
    }
  }
};
