#pragma once

#include <string>
#include <vector>
#include <memory>

#include <jinxy/lexer/Token.h>
#include <jinxy/ast/Node.h>
#include <jinxy/ast/Expression.h>

namespace jinxy::parser {

	class Parser {
	public:
		/**
		 * @brief This is a Parser class.
		 */
		Parser(const std::vector<lexer::Token>&);
		void parse();


	private:
		std::vector <lexer::Token> m_tokens;
		size_t m_index;
		lexer::Token getCurrentToken();
		void consume();
		bool expect(lexer::TokenType);
		std::shared_ptr<ast::Node> parseVariableDeclaration();
		std::shared_ptr<ast::Expression> parseExpression();
		std::shared_ptr<ast::Expression> parseTerm();
		std::shared_ptr<ast::Expression> parseFactor();
	};
}
