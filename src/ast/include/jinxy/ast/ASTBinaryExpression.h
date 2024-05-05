#pragma once

#include <memory>

#include <jinxy/ast/Expression.h>
#include <jinxy/ast/ASTOperator.h>

namespace jinxy::ast {

	class ASTBinaryExpression: public Expression {
	public:
		ASTBinaryExpression(std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs, ASTOperator op);
	private:
		std::shared_ptr<Expression> m_left;
		std::shared_ptr<Expression> m_right;
		ASTOperator m_op;
	};
}