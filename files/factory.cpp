# include "../header/validate.hpp"
# include "../header/factory.hpp"
# include "../header/IOperand.hpp"
# include "../header/Operand.hpp"
# include "../header/avm.hpp"

# include "../header/Exception.hpp"

Factory::Factory()
{ ; }

Factory::~Factory()
{ ; }

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const
{
	if (type == INT8)
		return (Factory::createInt8(value));
	else if (type == INT16)
		return (Factory::createInt16(value));
	else if (type == INT32)
		return (Factory::createInt32(value));
	else if (type == FLOAT)
		return (Factory::createFloat(value));
	else
		return (Factory::createDouble(value));
}

IOperand const * Factory::createInt8( std::string const & value ) const {
	int				tmp;
	int				max = std::numeric_limits<int8_t>::max();
	int				min = std::numeric_limits<int8_t>::min();

	tmp = std::stoi(value);
	if (tmp < min)
		throw Exception("Error : Underflow");
	else if (tmp > max)
		throw Exception("Error : Overflow");
	return (new Operand<int8_t>(INT8, value));
}

IOperand const * Factory::createInt16( std::string const & value ) const {
	int				tmp;
	short			max = std::numeric_limits<int16_t>::max();
	short			min = std::numeric_limits<int16_t>::min();

	tmp = std::stoi(value);
	if (tmp < min)
		throw Exception("Error : Underflow");
	else if (tmp > max)
		throw Exception("Error : Overflow");
	return (new Operand<int16_t>(INT16, value));
}

IOperand const * Factory::createInt32( std::string const & value ) const {
	int				tmp;
	int				max = std::numeric_limits<int32_t>::max();
	int				min = std::numeric_limits<int32_t>::min();

	tmp = std::stoi(value);
	if (tmp < min)
		throw Exception("Error : Underflow");
	else if (tmp > max)
		throw Exception("Error : Overflow");
	return (new Operand<int32_t>(INT32, value));
}

IOperand const * Factory::createFloat( std::string const & value ) const {
	float			tmp;
	float			max = std::numeric_limits<float>::max();
	float			min = std::numeric_limits<float>::min();

	tmp = std::stod(value);
	if (tmp < min)
		throw Exception("Error : Underflow");
	else if (tmp > max)
		throw Exception("Error : Overflow");
	return (new Operand<float>(FLOAT, value));
}

IOperand const * Factory::createDouble( std::string const & value ) const {
	double			tmp;
	double			max = std::numeric_limits<double>::max();
	double			min = std::numeric_limits<double>::min();

	tmp = std::stof(value);
	if (tmp < min)
		throw Exception("Error : Underflow");
	else if (tmp > max)
		throw Exception("Error : Overflow");
	return (new Operand<double>(DOUBLE, value));
}
