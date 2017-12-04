# include "../../header/validate.hpp"
# include "../../header/avm.hpp"
# include "../../header/int16.hpp"
# include "../../header/Exception.hpp"


Int16::Int16(std::string const & value)
{ 
	this->_type = INT16;
	this->_value = std::stoi(value);
	this->_precision = 2;
	this->_str = std::to_string(this->_value);
}

Int16::Int16() { ; }
Int16::~Int16() { ; }

int 				Int16::getPrecision( void ) const { return (this->_precision); }
eOperandType 		Int16::getType( void ) const { return (this->_type); }
std::string const & Int16::toString( void ) const { return (this->_str); }

IOperand const * 	Int16::operator+( IOperand const & rhs ) const
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

IOperand const * 	Int16::operator*( IOperand const & rhs ) const
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

std::ostream&		operator<<(std::ostream& out, const Int16& rhs) {
	out << rhs.toString() << std::endl;
	return out;
}