# include "../header/validate.hpp"
# include "../header/factory.hpp"
# include "../header/IOperand.hpp"
# include "../header/avm.hpp"
# include "../header/int8.hpp"
# include "../header/int16.hpp"
# include "../header/int32.hpp"
# include "../header/float.hpp"

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
	return (new Int8(value));
}

IOperand const * Factory::createInt16( std::string const & value ) const {
	int				tmp;
	int				max = std::numeric_limits<int16_t>::max();
	int				min = std::numeric_limits<int16_t>::min();

	tmp = std::stoi(value);
	if (tmp < min)
		throw Exception("Error : Underflow");
	else if (tmp > max)
		throw Exception("Error : Overflow");
	return (new Int16(value));
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
	return (new Int32(value));
}

IOperand const * Factory::createFloat( std::string const & value ) const {
	float			tmp;
	float			max = std::numeric_limits<float>::max();
	float			min = std::numeric_limits<float>::min();

	tmp = ::atof(value.c_str());
	if (tmp < min)
		throw Exception("Error : Underflow");
	else if (tmp > max)
		throw Exception("Error : Overflow");
	return (new Float(value));
}

IOperand const * Factory::createDouble( std::string const & value ) const {
	return (new Int8(value));
}
