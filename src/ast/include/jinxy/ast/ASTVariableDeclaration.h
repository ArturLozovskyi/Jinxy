#pragma once

#include <memory>

#include <jinxy/ast/Node.h>
#include <jinxy/ast/ASTIdentifier.h>
#include <jinxy/ast/Expression.h>

namespace jinxy::ast {
	class ASTVariableDeclaration: public Node {
	public:
		ASTVariableDeclaration(ASTIdentifier);
		ASTVariableDeclaration(ASTIdentifier, std::shared_ptr<Expression>);
	private:
		ASTIdentifier m_identifier;
		std::shared_ptr<Expression> m_initializer;
	};
}