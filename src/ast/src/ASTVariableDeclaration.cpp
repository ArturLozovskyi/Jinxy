#include <jinxy/ast/ASTVariableDeclaration.h>

namespace jinxy::ast {
	ASTVariableDeclaration::ASTVariableDeclaration(ASTIdentifier identifier)
		: m_identifier(identifier) {}

	ASTVariableDeclaration::ASTVariableDeclaration(ASTIdentifier identifier, std::shared_ptr<Expression> expr)
		: m_identifier(identifier)
		, m_initializer(expr) {}

}