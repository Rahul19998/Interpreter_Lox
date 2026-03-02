#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include "Token.h"
#include "TokenType.h"

class Scanner
{
    private:
        long unsigned int start = 0;
        long unsigned int current = 0;
        long unsigned int line = 1;
        std::string source;
        std::list<Token> tokens;
        static const std::unordered_map<std::string, TokenType> keywords;
        bool isAtEnd();
        void scanToken();
        void addToken(TokenType type);
        void addToken(TokenType type, std::any literal);
        char advance();
        bool match(char expected);
        char peek();
        void string();
        bool isDigit(char c);
        void number();
        char peekNext();
        void identifier();
        bool isAlpha(char c);
        bool isAlphaNumeric(char c);

    public:
        Scanner(std::string source);

        std::list<Token> scanTokens();
};
#endif // SCANNER_H