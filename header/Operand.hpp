#ifndef OPERAND_H
# define OPERAND_H

# include "AVM.hpp"
# include "IOperand.hpp"
# include "Factory.hpp"
# include "Exception.hpp"
# include "Parser.hpp"
# include "Lexer.hpp"

template<typename T>
class Operand : public IOperand, public Factory {

private:
	int 				_precision;
	eOperandType		_type;
	std::string			_str;
	T					_value;

	Operand<T>(const Operand&);
	const Operand<T>& operator=(const Operand<T> &src);
public:
	Operand<T>() { ; };
	Operand<T>(eOperandType type, std::string const & value);

	int 				getPrecision( void ) const; // Precision of the type of the instance
	eOperandType 		getType( void ) const; // Type of the instance
	IOperand const * 	operator+( IOperand const & rhs ) const; // Sum
	IOperand const * 	operator-( IOperand const & rhs ) const; // Difference
	IOperand const * 	operator*( IOperand const & rhs ) const; // Product
	IOperand const * 	operator/( IOperand const & rhs ) const; // Quotient
	IOperand const * 	operator%( IOperand const & rhs ) const; // Modulo
	std::string const & toString( void ) const; // String representation of the instance
	~Operand<T>() { ; };

};

/*
**	REALISATION 
*/

template<typename T>
Operand<T>::Operand(eOperandType type, std::string const & value) {
	std::regex			regular("([.])([0-9]+)");
	std::cmatch			result;
	int 				prec;
	std::stringstream	stream;

	if(std::regex_search(value.c_str(), result, regular))
		prec = std::string(result[2]).size();
	else
		prec = 0;
	this->_type = type;
	this->_value = std::stold(value);
	if (this->_type == INT8)
		stream << static_cast<int>(_value);
	else
		stream << std::fixed << std::setprecision(prec) << this->_value;
	this->_precision = prec;
	this->_str = stream.str();;
}

template<typename T>
int 				Operand<T>::getPrecision( void ) const { return (this->_precision); }
template<typename T>
eOperandType 		Operand<T>::getType( void ) const { return (this->_type); }
template<typename T>
std::string const & Operand<T>::toString( void ) const { return (this->_str); }

template<typename T>
IOperand const *	Operand<T>::operator+( IOperand const & rhs ) const {
	eOperandType		type;
	long double			res;

	res = (std::stold(this->toString())) + (std::stold(rhs.toString()));
	type = (this->_type > rhs.getType()) ? this->_type : type = rhs.getType();
	
	std::string   value = std::to_string(res);
	if (type < 3)
		Parser::checkOverflow(type, value, 0);

	return (Factory::createOperand(type, std::to_string(res)));
}

template<typename T>
IOperand const *	Operand<T>::operator-( IOperand const & rhs ) const {
	eOperandType		type;
	long double			res;
	
	res = (std::stold(this->toString())) - (std::stold(rhs.toString()));
	type = (this->_type > rhs.getType()) ? this->_type : type = rhs.getType();
	
	std::string   value = std::to_string(res);
	if (type < 3)
		Parser::checkOverflow(type, value, 0);

	return (Factory::createOperand(type, std::to_string(res)));
}

template<typename T>
IOperand const *	Operand<T>::operator*( IOperand const & rhs ) const {
	eOperandType		type;
	long double			res;
	
	res = (std::stold(this->toString())) * (std::stold(rhs.toString()));
	type = (this->_type > rhs.getType()) ? this->_type : type = rhs.getType();
	
	std::string   value = std::to_string(res);
	if (type < 3)
		Parser::checkOverflow(type, value, 0);

	return (Factory::createOperand(type, std::to_string(res)));
}

template<typename T>
IOperand const *	Operand<T>::operator/( IOperand const & rhs ) const {
	eOperandType		type;
	double				res;
	
	res = (std::stold(this->toString())) / (std::stold(rhs.toString()));
	type = (this->_type > rhs.getType()) ? this->_type : type = rhs.getType();

	return (Factory::createOperand(type, std::to_string(res)));
}

template<typename T>
IOperand const *	Operand<T>::operator%( IOperand const & rhs ) const {
	eOperandType		type;
	int					res;
	
	res = (std::stoi(this->toString())) % (std::stoi(rhs.toString()));
	type = (this->_type > rhs.getType()) ? this->_type : type = rhs.getType();

	return (Factory::createOperand(type, std::to_string(res)));
}

template<typename T>
std::ostream&		operator<<(std::ostream& out, const Operand<T>& rhs) {
	out << rhs.toString() << std::endl;
	return out;
}

#endif
