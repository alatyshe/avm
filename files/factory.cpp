# include "../header/Factory.hpp"
# include "../header/Operand.hpp"

Factory::Factory()
{ ; }

Factory::~Factory()
{ ; }

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const {
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
	return (new Operand<int8_t>(INT8, value));
}

IOperand const * Factory::createInt16( std::string const & value ) const {
	return (new Operand<int16_t>(INT16, value));
}

IOperand const * Factory::createInt32( std::string const & value ) const {
	return (new Operand<int32_t>(INT32, value));
}

IOperand const * Factory::createFloat( std::string const & value ) const {
	return (new Operand<float>(FLOAT, value));
}

IOperand const * Factory::createDouble( std::string const & value ) const {
	return (new Operand<double>(DOUBLE, value));
}
