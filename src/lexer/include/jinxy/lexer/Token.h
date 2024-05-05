#pragma once

#include <string>

namespace jinxy::lexer {
	
	enum class TokenType {
		Var_Keyword,
		Identifier,
		Number,
		Plus,
		Minus,
		Multiply,
		Divide,
		Equals,
		Semicolon,
	};

	class Token {
	public:
		Token(TokenType type, std::string value);
		TokenType getType() const;
		const std::string& getValue() const;

	private:
		TokenType m_type;
		std::string m_value;
	};
}