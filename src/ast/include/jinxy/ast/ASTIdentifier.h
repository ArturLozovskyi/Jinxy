#pragma once

#include <string>

#include <jinxy/ast/Expression.h>

namespace jinxy::ast {
	class ASTIdentifier: public Expression {
	public:
		ASTIdentifier(const std::string&);
		const std::string& getName() const;
	private:
		std::string m_name;
	};
}