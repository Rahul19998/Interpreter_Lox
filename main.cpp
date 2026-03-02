#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <sysexits.h>
#include "include/Lox.h"


int main(int argc, char *argv[]) {
  lox cpplox;
  if (argc > 2) {
    std::cout << "Usage: cpplox [script]" << std::endl;
    return EX_USAGE;
  } else if (argc == 2) {
    std::string firstArgument = argv[1];
    cpplox.runFile(firstArgument);
  } else {
    cpplox.runPrompt();
  }

  return 0;
}
