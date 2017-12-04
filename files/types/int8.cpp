# include "../../header/validate.hpp"
# include "../../header/avm.hpp"
# include "../../header/Int8.hpp"
# include "../../header/Exception.hpp"


Int8::Int8(std::string const & value)
{ 
	this->_type = INT8;
	this->_value = std::stoi(value);
	this->_precision = 1;
	this->_str = std::to_string(this->_value);
}

Int8::Int8() { ; }
Int8::~Int8() { ; }

int 				Int8::getPrecision( void ) const { return (this->_precision); }
eOperandType 		Int8::getType( void ) const { return (this->_type); }
std::string const & Int8::toString( void ) const { return (this->_str); }

IOperand const * 	Int8::operator+( IOperand const & rhs ) const
{
	Factory				factory;
	eOperandType		type;
	int 				prec;
	double				res;
	

	res = (std::stod(this->toString())) + (std::stod(rhs.toString()));
	if (this->_precision > rhs.getPrecision())
		prec = this->_precision;
	else
		prec = rhs.getPrecision();

	if (prec == 1)
		type = INT8;
	else if (prec == 2)
		type = INT16;
	else if (prec == 3)
		type = INT32;
	else if (prec == 4)
		type = FLOAT;
	else if (prec == 5)
		type = DOUBLE;

	return (factory.createOperand(type, std::to_string(res)));
}

// IOperand const * 	operator-( IOperand const & rhs ) const
// {
// 	return (this);
// }

IOperand const * 	Int8::operator*( IOperand const & rhs ) const
{
	Factory				factory;
	eOperandType		type;
	int 				prec;
	double				res;
	

	res = (std::stod(this->toString())) * (std::stod(rhs.toString()));
	if (this->_precision > rhs.getPrecision())
		prec = this->_precision;
	else
		prec = rhs.getPrecision();

	if (prec == 1)
		type = INT8;
	else if (prec == 2)
		type = INT16;
	else if (prec == 3)
		type = INT32;
	else if (prec == 4)
		type = FLOAT;
	else if (prec == 5)
		type = DOUBLE;

	return (factory.createOperand(type, std::to_string(res)));
}

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


std::ostream&		operator<<(std::ostream& out, const Int8& rhs) {
	out << rhs.toString() << std::endl;
	return out;
}