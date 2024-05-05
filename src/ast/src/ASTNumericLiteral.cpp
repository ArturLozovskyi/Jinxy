#include <jinxy/ast/ASTNumericLiteral.h>

namespace jinxy::ast {
	ASTNumericLiteral::ASTNumericLiteral(const std::string& text)
		: m_text(text) {}

	const std::string& ASTNumericLiteral::getText() const {
		return m_text;
	}
}