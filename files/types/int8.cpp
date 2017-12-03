# include "../../header/validate.hpp"
# include "../../header/avm.hpp"
# include "../../header/Int8.hpp"


Int8::Int8(std::string const & value) : in(value)
{ ; }

Int8::Int8()
{ ; }

Int8::~Int8()
{ ; }

int 				Int8::getPrecision( void ) const {
	return 1;
}

eOperandType 		Int8::getType( void ) const {
	return (this->type);
}

std::string const & Int8::toString( void ) const {
	return (this->in);
}

// IOperand const * 	operator+( IOperand const & rhs ) const
// {
// 	return (this);
// }

// IOperand const * 	operator-( IOperand const & rhs ) const
// {
// 	return (this);
// }

// IOperand const * 	operator*( IOperand const & rhs ) const
// {
// 	return (this);
// }

// IOperand const * 	operator/( IOperand const & rhs ) const
// {
// 	return (this);
// }

// IOperand const * 	operator%( IOperand const & rhs ) const
// {
// 	return (this);
// }

// std::string const & toString( void ) const = 0
// {
// 	return (this);
// }