#include <stdexcept>

#include <jinxy/parser/Parser.h>
#include <jinxy/ast/ASTVariableDeclaration.h>
#include <jinxy/ast/ASTIdentifier.h>
#include <jinxy/ast/ASTNumericLiteral.h>
#include <jinxy/ast/ASTBinaryExpression.h>
#include <jinxy/ast/ASTOperator.h>

namespace jinxy::parser {
	Parser::Parser(const std::vector <lexer::Token> & tokens)
		: m_tokens(tokens)
		, m_index(0) {}

	lexer::Token Parser::getCurrentToken() {
		return m_tokens[m_index];
	}

	void Parser::consume() {
		m_index++;
	}
	
	bool Parser::expect(lexer::TokenType tokenType) {
		return m_index < m_tokens.size() && tokenType == getCurrentToken().getType();
	}

	void Parser::parse() {
		if (getCurrentToken().getType() == lexer::TokenType::Var_Keyword) {
			auto varDecl = parseVariableDeclaration();
			auto p = dynamic_cast<ast::ASTVariableDeclaration*>(varDecl.get());
		}
	}

	std::shared_ptr<ast::Node> Parser::parseVariableDeclaration() {
		if (expect(lexer::TokenType::Var_Keyword)) {
			consume();
			if (expect(lexer::TokenType::Identifier)) {
				auto identifier = getCurrentToken();
				consume();

				if (expect(lexer::TokenType::Equals)) {
					consume();
					auto expr = parseExpression();
					if (expect(lexer::TokenType::Semicolon)) {
						consume();
						return std::make_shared<ast::ASTVariableDeclaration>(ast::ASTIdentifier(identifier.getValue()), expr);
					}
					else {
						throw std::exception("Expected ;");
					}
				}
				if (expect(lexer::TokenType::Semicolon)) {
					consume();
					return std::make_shared<ast::ASTVariableDeclaration>(ast::ASTIdentifier(identifier.getValue()));
				}
			}
		}
	}

	std::shared_ptr<ast::Expression> Parser::parseExpression() {
		auto lhs = parseTerm();
		if (expect(lexer::TokenType::Plus) || expect(lexer::TokenType::Minus)) {
			auto op = getCurrentToken().getValue() == "+" ? ast::Op::PLUS : ast::Op::MINUS;
			consume();
			auto rhs = parseExpression();
			return std::make_shared<ast::ASTBinaryExpression>(lhs, rhs, ast::ASTOperator(op));
		}

		return lhs;
	}

	std::shared_ptr<ast::Expression> Parser::parseTerm() {
		auto lhs = parseFactor();
		if (expect(lexer::TokenType::Multiply) || expect(lexer::TokenType::Divide)) {
			auto op = getCurrentToken().getValue() == "*" ? ast::Op::MULTIPLY : ast::Op::DIVIDE;
			consume();
			auto rhs = parseTerm();
			return std::make_shared<ast::ASTBinaryExpression>(lhs, rhs, ast::ASTOperator(op));
		}
		return lhs;
	}

	std::shared_ptr<ast::Expression> Parser::parseFactor() {
		if (expect(lexer::TokenType::Number)) {
			auto lhs = getCurrentToken();
			consume();
			return std::make_shared<ast::ASTNumericLiteral>(lhs.getValue());
		}
		else if (expect(lexer::TokenType::Identifier)) {
			auto lhs = getCurrentToken();
			consume();
			return std::make_shared<ast::ASTIdentifier>(lhs.getValue());
		}
	}
}