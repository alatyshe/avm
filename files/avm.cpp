# include "../header/validate.hpp"
# include "../header/avm.hpp"
# include "../header/Operand.hpp"
# include "../header/Exception.hpp"

AVM::AVM() { ; }
AVM::~AVM() { ; }

void		AVM::push(IOperand const * type) {
	this->_values.insert(this->_values.begin(), type);
}

void		AVM::assert(IOperand const * type) {
	std::string		first = this->_values[0]->toString();
	std::string		second = type->toString();
	if (second.compare(first))
	{
		std::cout << "ERROR" << std::endl;
		return ; // сюда добавить ошибку
	}
}

void		AVM::pop() {
	if (this->_values.size() < 1)	//
	{
		std::cout << "ERROR" << std::endl;
		return ; // сюда добавить ошибку
	}
	this->_values.erase(_values.begin());
}

void		AVM::dump() {
	std::vector<IOperand const *>::iterator i = this->_values.begin();

	while (i != _values.end()) {
		std::cout << (*(*i)).toString() << std::endl;
		i++;
	}
}

void		AVM::add() {
	IOperand const *	result;
	IOperand const *	first;
	IOperand const *	second;

	if (this->_values.size() < 2)
	{
		std::cout << "ERROR" << std::endl;
		return ; // сюда добавить ошибку
	}
	first = this->_values[0];
	second = this->_values[1];
	
	result = (*first) + (*second);

	this->_values.erase(_values.begin(), _values.begin() + 2);

	this->_values.insert(this->_values.begin(), result);
}

void		AVM::sub() {
	std::cout << "SUB" << std::endl;
}

void		AVM::mul() {
	IOperand const *	result;
	IOperand const *	first;
	IOperand const *	second;

	if (this->_values.size() < 2)
	{
		std::cout << "ERROR" << std::endl;
		return ; // сюда добавить ошибку
	}
	first = this->_values[0];
	second = this->_values[1];
	
	result = (*first) * (*second);

	this->_values.erase(_values.begin(), _values.begin() + 2);
	
	this->_values.insert(this->_values.begin(), result);
}

void		AVM::div() {
	std::cout << "DIV" << std::endl;
}

void		AVM::mod() {
	std::cout << "MOD" << std::endl;
}

void		AVM::print() {
	std::cout << "PRINT" << std::endl;
}

void		AVM::exit() {
	std::cout << "EXIT" << std::endl;
}