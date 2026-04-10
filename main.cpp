#include"fmain.cpp"

int main() 
{
  string input = "";
  std::cout << "Type 'help' for show commands" << std::endl;
  std::cout << "To stop program: '#'" << std::endl;;

  // --- While loop ---
  while (input != "#") {
    
    input = finput();
    toLowerCase(input);

    if (input == "help") fhelp();
    if (input == "create") fcreate(input);
    if (input == "show") fshow();

    // --- Game ---
    if (input == "start") StartGame();
    
  }

  return 0;
}
