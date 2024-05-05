#include <iostream>
#include <iomanip>

#include <jinxy/lexer/Lexer.h>
#include <jinxy/parser/Parser.h>
#include <jinxy/ast/Expression.h>

std::string getStringFromTokenType(jinxy::lexer::TokenType type) {
	switch (type)
	{
	case jinxy::lexer::TokenType::Var_Keyword:
		return "Var_Keyword";
	case jinxy::lexer::TokenType::Identifier:
		return "Identifier";
	case jinxy::lexer::TokenType::Number:
		return "Number";
	case jinxy::lexer::TokenType::Plus:
		return "Plus";
	case jinxy::lexer::TokenType::Minus:
		return "Minus";
	case jinxy::lexer::TokenType::Multiply:
		return "Multiply";
	case jinxy::lexer::TokenType::Divide:
		return "Divide";
	case jinxy::lexer::TokenType::Equals:
		return "Equals";
	case jinxy::lexer::TokenType::Semicolon:
		return "Semicolon";
	default:
		break;
	}
}

int main() {
	try {
		jinxy::lexer::Lexer lexer("var a = 55+5 * 10 + 7 * 8");

		std::cout << lexer.getSourceCode() << std::endl << std::endl;

		std::vector<jinxy::lexer::Token> tokens = lexer.tokenize();

		for (const auto& token : tokens) {
			std::cout << "Type: " << std::left << std::setw(15) << std::setfill(' ') << getStringFromTokenType(token.getType());
			std::cout << std::left << std::setw(7) << std::setfill(' ') << "Value: " << token.getValue() << std::endl;
			std::cout << std::endl;
		}

		jinxy::parser::Parser parser(tokens);
		parser.parse();
	}

	catch(std::runtime_error err) {
		std::cerr << err.what() << std::endl;
	}

	return 0;
}