#include <jinxy/lexer/Lexer.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

namespace jinxy::lexer {

	Lexer::Lexer(const std::string& sourceCode)
		: m_sourceCode(sourceCode)
		, m_index(0) {}

	char Lexer::getCurrentChar() const {
		return m_sourceCode[m_index];
	}

	bool Lexer::hasNextChar() const {
		return m_index < m_sourceCode.size();
	}

	void Lexer::skip() {
		while (getCurrentChar() == ' ') {
			m_index++;
		}
		m_index--;
	}

	void Lexer::parseNumber() {
		while (hasNextChar() && std::isdigit(getCurrentChar()))
		{
			m_buffer += getCurrentChar();
			m_index++;
		}
		m_index--;
	}

	void Lexer::parseIdentifier() {
		while (hasNextChar() && (std::isalnum(getCurrentChar()) || getCurrentChar() == '_'))
		{
			m_buffer += getCurrentChar();
			m_index++;
		}
		m_index--;
	}

	bool Lexer::isOneOf(char currentChar, std::vector<char> vars) {
		return std::any_of(vars.cbegin(), vars.cend(), [&](char c) { return currentChar == c; });
	}

	const std::vector<Token>& Lexer::tokenize() {
		while (m_index < m_sourceCode.size()) {
			if (getCurrentChar() == ' ') {
				skip();
			}
			else if (std::isdigit(getCurrentChar())) {
				parseNumber();
				m_tokens.push_back(Token(TokenType::Number, m_buffer));
			}
			else if (std::isalpha(getCurrentChar()) || getCurrentChar() == '_') {
				parseIdentifier();
				if (m_buffer == "var") {
					m_tokens.push_back(Token(TokenType::Var_Keyword, m_buffer));
				} else {
					m_tokens.push_back(Token(TokenType::Identifier, m_buffer));
				}
			}
			else if (getCurrentChar() == '+') {
				m_tokens.push_back(Token(TokenType::Plus, "+"));
			}
			else if (getCurrentChar() == '-') {
				m_tokens.push_back(Token(TokenType::Minus, "-"));
			}
			else if (getCurrentChar() == '*') {
				m_tokens.push_back(Token(TokenType::Multiply, "*"));
			}
			else if (getCurrentChar() == '/') {
				m_tokens.push_back(Token(TokenType::Plus, "/"));
			}
			else if (getCurrentChar() == ';') {
				m_tokens.push_back(Token(TokenType::Semicolon, ";"));
			}
			else if (getCurrentChar() == '=') {
				m_tokens.push_back(Token(TokenType::Equals, "="));
			}
			else {
				throw std::runtime_error("Unexpected char");
			}

			m_buffer = "";
			m_index++;
		}

		return m_tokens;
	}
}