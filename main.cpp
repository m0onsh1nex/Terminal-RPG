#include<iostream>
#include<string>
#include"adminInterface.h"

void create(AdminInterface * interface, std::string hOe, std::string name) {
  interface->createEntity(hOe, name);
}
void show(AdminInterface * interface) {
  interface->showAllEntities();
}

int main() 
{
  AdminInterface * _interface = new AdminInterface();
  std::string input = "";
  std::cout << "Type 'help' for show commands" << std::endl;
  while (input != "#") {
    std::cin >> input;
    if (input == "help") {
      std::cout << "To stop program: '#'" << std::endl;;
      std::cout << "Create an entity: 'create'" << std::endl;;
      std::cout << "Show all entity: 'show'" << std::endl;;
    }
    if (input == "create") {
      std::cout << "Choose Hero or Enemy: ";
      std::cin >> input;
      if (input == "Hero") {
        std::string name;
        std::cout << "Type a name for Hero: ";
        std::cin >> name;
        std::cout << std::endl;
        create(_interface,"hero", name);
      }
      else {
        std::string name;
        std::cout << "Type a name for Enemy: ";
        std::cin >> name;
        create(_interface, "enemy", name);
      }
    }
    if (input == "show") {
      show(_interface);
    }
  }
    return 0;
}
