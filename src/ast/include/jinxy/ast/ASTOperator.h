#pragma once

#include <jinxy/ast/Node.h>

namespace jinxy::ast {
	
	enum class Op {
		PLUS,
		MINUS,
		MULTIPLY,
		DIVIDE
	};

	class ASTOperator: public Node {
	public:
		ASTOperator(const Op);
	private:
		const Op m_op;
	};
}
