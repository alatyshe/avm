#ifndef FLOAT_H
# define FLOAT_H

# include "avm.hpp"
# include "IOperand.hpp"
# include "factory.hpp"

class Float : public IOperand {
private:
	int 				_precision;
	eOperandType		_type;
	std::string			_str;
	float				_value;

public:
	Float();
	Float(std::string const & value);
	int 				getPrecision( void ) const; // Precision of the type of the instance
	eOperandType 		getType( void ) const; // Type of the instance
	IOperand const * 	operator+( IOperand const & rhs ) const; // Sum
	// IOperand const * 	operator-( IOperand const & rhs ) const; // Difference
	IOperand const * 	operator*( IOperand const & rhs ) const; // Product
	// IOperand const * 	operator/( IOperand const & rhs ) const; // Quotient
	// IOperand const * 	operator%( IOperand const & rhs ) const; // Modulo
	std::string const & toString( void ) const; // String representation of the instance
	~Float( void );
};

std::ostream&		operator<<(std::ostream& out, const Float& rhs);

#endif
