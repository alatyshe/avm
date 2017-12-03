#ifndef INT8_H
# define INT8_H

# include "avm.hpp"
# include "validate.hpp"
# include "IOperand.hpp"

// enum eOperandType
// {
// 	INT8,
// 	INT16,
// 	INT32,
// 	FLOAT,
// 	DOUBLE
// };

class Int8 : public IOperand {
private:
	eOperandType		type;
	std::string			in;

public:
	Int8();
	Int8(std::string const & value);
	int 				getPrecision( void ) const; // Precision of the type of the instance
	eOperandType 		getType( void ) const; // Type of the instance
	// IOperand const * 	operator+( IOperand const & rhs ) const; // Sum
	// IOperand const * 	operator-( IOperand const & rhs ) const; // Difference
	// IOperand const * 	operator*( IOperand const & rhs ) const; // Product
	// IOperand const * 	operator/( IOperand const & rhs ) const; // Quotient
	// IOperand const * 	operator%( IOperand const & rhs ) const; // Modulo
	std::string const & toString( void ) const; // String representation of the instance
	~Int8( void );
};

#endif
