#include <iostream>
#include <string>

void runFile(std::string fileName) { std::cout << "Called runFile."; }

void runPrompt() { std::cout << "Called runPrompt"; }

int main(int argc, char *argv[]) {
  // int number;
  std::cout << "argc value: " << argc << std::endl;
  std::cout << "arg value" << argv[0] << std::endl;
  if (argc == 1) {
    std::cout << "Usage: clox [script]" << std::endl;
    return 0;
  } else if (argc == 2) {
    std::string firstArgument = argv[0];
    runFile(firstArgument);
  } else {
    runPrompt();
  }

  return 0;
}
