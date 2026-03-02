#include <fstream>
#include <iostream>
#include <list>
#include <sysexits.h>
#include "include/Lox.h"
#include "include/Scanner.h"
#include "include/Token.h"

void lox::run(std::string code)
{
  std::cout << "run :: Code written. " << code << std::endl;
  Scanner* scanner = new Scanner(code);
  std::list<Token> tokens = scanner->scanTokens();

  //For now print the tokens.
  for(Token token: tokens) 
  {
      std::cout << "Token  " << token.convertToString() << std::endl;
  }
}

void lox::runFile(std::string fileName) 
{
  std::ifstream allBytes(fileName);
  if (allBytes.is_open()) 
  {
    std::string buff;
    allBytes >> buff;
    run(buff);
    if(hadError) return;
        // return EX_DATAERR;
    std::cout << "Now printing...." << std::endl;
  } 
  else 
  {
    std::cerr << "Error : Could Not Open file" << std::endl;
  }
  std::cout << "Called runFile.";
}

void lox::runPrompt() {
  std::string buffer;
  for (;;) {
    std::cout << "> " << std::endl;
    std::cin >> buffer;
    if (buffer.empty())
      break;
    run(buffer);
    lox::hadError=false;
  }
  std::cout << "Called runPrompt";
}

void lox::error(long unsigned int line, std::string message)
{
  report(line, "", message);
}

void lox::report(long unsigned int line, std::string where, std::string message)
{
  std::cerr << "[line " << line << " ] Error " << where << ": " << message << std::endl;
  lox::hadError=true;
}
