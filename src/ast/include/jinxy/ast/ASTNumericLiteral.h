#pragma once

#include <string>

#include <jinxy/ast/Expression.h>

namespace jinxy::ast {
	class ASTNumericLiteral: public Expression {
	public:
		ASTNumericLiteral(const std::string&);
		const std::string& getText() const;
	private:
		const std::string m_text;
	};
}