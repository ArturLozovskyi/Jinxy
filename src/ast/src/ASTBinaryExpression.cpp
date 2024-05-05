#include <jinxy/ast/ASTBinaryExpression.h>

namespace jinxy::ast {
	ASTBinaryExpression::ASTBinaryExpression(std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs, ASTOperator op)
		: m_left(lhs)
		, m_right(rhs)
		, m_op(op) {}
}