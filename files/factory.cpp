# include "../header/validate.hpp"
# include "../header/factory.hpp"
# include "../header/avm.hpp"
# include "../header/int8.hpp"

// # include "../includes/OperandFactory.hpp"
// # include "../includes/Exception.hpp"

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
	else// (type == DOUBLE)
		return (Factory::createDouble(value));
}

IOperand const * Factory::createInt8( std::string const & value ) const {
	return (new Int8(value));
}

IOperand const * Factory::createInt16( std::string const & value ) const {
	return (new Int8(value));
}

IOperand const * Factory::createInt32( std::string const & value ) const {
	return (new Int8(value));
}

IOperand const * Factory::createFloat( std::string const & value ) const {
	return (new Int8(value));
}

IOperand const * Factory::createDouble( std::string const & value ) const {
	return (new Int8(value));
}
