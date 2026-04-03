#include<iostream>
#include<string>
// #include<sstream>
#include"adminInterface.h"

int main() 
{

  /*
  Entity * _goblin = new Enemy("GOBLIN", 10, 0, 2, 0);
  Entity * _player = new Hero("M0onSh1neX", 100, 1, 10, 0);
  std::string playerInfo = _player->getInfo();
  std::string goblinInfo = _goblin->getInfo();
  std::ostringstream ssPlayer, ssGoblin, ssOutput;
  ssPlayer << playerInfo;
  ssGoblin << goblinInfo;
  std::string out = ssPlayer.str() + '\n' + ssGoblin.str();
  std::cout << out << std::endl;
  */

  AdminInterface * panel = new AdminInterface();
  panel->createHero("M0onSh1neX");
  panel->createGoblin();

  panel->showAllEntities();
  return 0;
}
