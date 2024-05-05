#include <jinxy/ast/ASTIdentifier.h>

namespace jinxy::ast {
	ASTIdentifier::ASTIdentifier(const std::string& name)
		: m_name(name) {}

	const std::string& ASTIdentifier::getName() const {
		return m_name;
	}
}