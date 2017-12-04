# include "../../header/validate.hpp"
# include "../../header/avm.hpp"
# include "../../header/float.hpp"
# include "../../header/Exception.hpp"


Float::Float(std::string const & value)
{ 
	this->_type = FLOAT;
	this->_value = ::atof(value.c_str());;
	this->_precision = 3;
	this->_str = std::to_string(this->_value);
}

Float::Float() { ; }
Float::~Float() { ; }

int 				Float::getPrecision( void ) const { return (this->_precision); }
eOperandType 		Float::getType( void ) const { return (this->_type); }
std::string const & Float::toString( void ) const { return (this->_str); }

IOperand const * 	Float::operator+( IOperand const & rhs ) const
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

IOperand const * 	Float::operator*( IOperand const & rhs ) const
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


std::ostream&		operator<<(std::ostream& out, const Float& rhs) {
	out << rhs.toString() << std::endl;
	return out;
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