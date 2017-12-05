#ifndef FLOAT_H
# define FLOAT_H

# include "avm.hpp"
# include "IOperand.hpp"
# include "factory.hpp"

template<typename T>
class Operand : public IOperand {
private:
	int 				_precision;
	eOperandType		_type;
	std::string			_str;
	T					_value;

public:
	Operand<T>();
	Operand<T>(std::string const & value);
	Operand<T>(eOperandType type, std::string const & value);

	int 				getPrecision( void ) const; // Precision of the type of the instance
	eOperandType 		getType( void ) const; // Type of the instance
	IOperand const * 	operator+( IOperand const & rhs ) const; // Sum
	IOperand const * 	operator-( IOperand const & rhs ) const; // Difference
	IOperand const * 	operator*( IOperand const & rhs ) const; // Product
	IOperand const * 	operator/( IOperand const & rhs ) const; // Quotient
	IOperand const * 	operator%( IOperand const & rhs ) const; // Modulo
	std::string const & toString( void ) const; // String representation of the instance
	~Operand<T>( void );


};

template<typename T>
std::ostream&		operator<<(std::ostream& out, const Operand<T>& rhs);

/*
**	REALISATION REALISATION REALISATION REALISATION
**	REALISATION REALISATION REALISATION REALISATION
**	REALISATION REALISATION REALISATION REALISATION
*/

template<typename T>
Operand<T>::Operand(eOperandType type, std::string const & value)
{
	std::regex			regular("([.])([0-9]+)");
	std::cmatch			result;
	int 				prec;
	std::stringstream	stream;

	if(std::regex_search(value.c_str(), result, regular))
		prec = std::string(result[2]).size();
	else
		prec = 0;

	this->_type = type;
	this->_value = std::stod(value.c_str());

	stream << std::fixed << std::setprecision(prec) << _value;

	this->_precision = prec;
	this->_str = stream.str();;
}

template<typename T>
Operand<T>::Operand(std::string const & value)
{
	std::regex			regular("([.])([0-9]+)");
	std::cmatch			result;
	int 				prec;
	std::stringstream	stream;

	if(std::regex_search(value.c_str(), result, regular))
		prec = std::string(result[2]).size();
	else
		prec = 0;

	// this->_type = ;
	this->_value = std::stod(value.c_str());

	stream << std::fixed << std::setprecision(prec) << _value;

	this->_precision = prec;
	this->_str = stream.str();;
}

template<typename T>
Operand<T>::Operand() { ; }
template<typename T>
Operand<T>::~Operand() { ; }

template<typename T>
int 				Operand<T>::getPrecision( void ) const { return (this->_precision); }
template<typename T>
eOperandType 		Operand<T>::getType( void ) const { return (this->_type); }
template<typename T>
std::string const & Operand<T>::toString( void ) const { return (this->_str); }

template<typename T>
IOperand const * 	Operand<T>::operator+( IOperand const & rhs ) const
{
	Factory				factory;
	eOperandType		type;
	int 				prec;
	double				res;

	res = (std::stod(this->toString())) + (std::stod(rhs.toString()));
	//	Установка точности для float double
	if (this->_precision > rhs.getPrecision())
		prec = this->_precision;
	else
		prec = rhs.getPrecision();
	//	Установка типа
	if (this->_type > rhs.getType())
		type = this->_type;
	else
		type = rhs.getType();
	//	Создание екземпляра
	return (factory.createOperand(type, std::to_string(res)));
}

template<typename T>
IOperand const * 	Operand<T>::operator-( IOperand const & rhs ) const
{
	Factory				factory;
	eOperandType		type;
	int 				prec;
	double				res;
	
	res = (std::stod(this->toString())) - (std::stod(rhs.toString()));
	//	Установка точности для float double
	if (this->_precision > rhs.getPrecision())
		prec = this->_precision;
	else
		prec = rhs.getPrecision();
	//	Установка типа
	if (this->_type > rhs.getType())
		type = this->_type;
	else
		type = rhs.getType();
	//	Создание екземпляра
	return (factory.createOperand(type, std::to_string(res)));
}

template<typename T>
IOperand const * 	Operand<T>::operator*( IOperand const & rhs ) const
{
	Factory				factory;
	eOperandType		type;
	int 				prec;
	double				res;
	
	res = (std::stod(this->toString())) * (std::stod(rhs.toString()));
	//	Установка точности для float double
	if (this->_precision > rhs.getPrecision())
		prec = this->_precision;
	else
		prec = rhs.getPrecision();
	//	Установка типа
	if (this->_type > rhs.getType())
		type = this->_type;
	else
		type = rhs.getType();
	//	Создание екземпляра
	return (factory.createOperand(type, std::to_string(res)));
}

template<typename T>
IOperand const * 	Operand<T>::operator/( IOperand const & rhs ) const
{
	Factory				factory;
	eOperandType		type;
	int 				prec;
	double				res;
	
	res = (std::stod(this->toString())) / (std::stod(rhs.toString()));
	//	Установка точности для float double
	if (this->_precision > rhs.getPrecision())
		prec = this->_precision;
	else
		prec = rhs.getPrecision();
	//	Установка типа
	if (this->_type > rhs.getType())
		type = this->_type;
	else
		type = rhs.getType();
	//	Создание екземпляра
	return (factory.createOperand(type, std::to_string(res)));
}

template<typename T>
IOperand const * 	Operand<T>::operator%( IOperand const & rhs ) const
{
	Factory				factory;
	eOperandType		type;
	int 				prec;
	int					res;
	
	res = (std::stoi(this->toString())) % (std::stoi(rhs.toString()));
	//	Установка точности для float double
	if (this->_precision > rhs.getPrecision())
		prec = this->_precision;
	else
		prec = rhs.getPrecision();
	//	Установка типа
	if (this->_type > rhs.getType())
		type = this->_type;
	else
		type = rhs.getType();
	//	Создание екземпляра
	return (factory.createOperand(type, std::to_string(res)));
}

template<typename T>
std::ostream&		operator<<(std::ostream& out, const Operand<T>& rhs) {
	out << rhs.toString() << std::endl;
	return out;
}


#endif
