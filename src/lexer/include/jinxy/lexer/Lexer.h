#pragma once

#include <string>
#include <vector>

#include <jinxy/lexer/Token.h>


namespace jinxy::lexer {

	class Lexer {
	public:
		/**
		 * @brief This is a Lexer class.
		 */
		Lexer(const std::string&);
		const std::vector<Token>& tokenize();
		const std::string& getSourceCode() { return m_sourceCode; };

	private:
		std::string m_sourceCode;
		std::string m_buffer;
		size_t m_index;
		std::vector<Token> m_tokens;
		char getCurrentChar() const;
		bool hasNextChar() const;
		void parseNumber();
		void parseIdentifier();
		void skip();
		bool isOneOf(char currentChar, std::vector<char> vars);
	};
}
