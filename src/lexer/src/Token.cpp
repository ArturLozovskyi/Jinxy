#include <jinxy/lexer/Token.h>

namespace jinxy::lexer {
	Token::Token(TokenType type, std::string value)
		: m_type(type)
		, m_value(value) {}

	TokenType Token::getType() const {
		return m_type;
	}

	const std::string& Token::getValue() const {
		return m_value;
	}
}