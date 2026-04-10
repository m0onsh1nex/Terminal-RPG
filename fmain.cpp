#include"config.h"
#include "adminInterface.h"

AdminInterface * INTERFACE = new AdminInterface();

void create(char hOe, string name) {
  INTERFACE->createEntity(hOe, name);
}

void fshow() {
  AdminInterface * interface = INTERFACE;
  // interface->showAllEntities();
  interface->showAllEntities_Dist();
}

string finput() {
  string input;
  std::cout << PATH;
  std::cin >> input;
  return input;
}

void fhelp() {
  std::cout << "To stop program: '#'" << std::endl;
  std::cout << "Create an entity: 'create'" << std::endl;
  std::cout << "Show all entity: 'show'" << std::endl;
}

void fcreate(string &input) {
  try {
    std::cout << "Choose 'Hero' or 'Enemy': ";
    std::cin >> input;
    toLowerCase(input);
    string name;
      if (input == "hero") {
        std::cout << "Type hero name: ";
        std::cin >> name;
        create('h', name);
      }

      else if (input == "enemy") {
        std::cout << "Type an enemy name: ";
        std::cin >> name;
        create('e', name);
      }

      else {
        throw std::invalid_argument("Undefined input");
      }
    } catch(const string msg) {
      std::cout << "Error: " << msg << std::endl;
    }
}

void StartGame() {
  // if hero exists
  for (Entity* entity : INTERFACE->getEntityList()) {
    
  }
}

