#ifndef TOKEN_H
#define TOKEN_H

#include "TokenType.h"
#include <any>

class Token
{
	private:
		TokenType type;
        std::string lexeme;
		std::any literal;
		long unsigned int line;

	public:
		Token(TokenType type, std::string lexeme, std::any literal, long unsigned int line)
		: type(type), lexeme(lexeme), literal(literal), line(line)
		{}

		std::string convertToString()
		{ 
			std::string literalStr;
			if (!literal.has_value()) {
				literalStr = "nil";
			} else {
				try {
					literalStr = std::any_cast<std::string>(literal);
				} catch (const std::bad_any_cast&) {
					literalStr = "<non-string literal>";
				}
			}
			return std::to_string(type) + " " + lexeme + " " + literalStr;
		}
};

#endif //TOKEN_H
