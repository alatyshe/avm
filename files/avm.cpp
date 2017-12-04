# include "../header/validate.hpp"
# include "../header/avm.hpp"
# include "../header/Exception.hpp"

AVM::AVM() { ; }
AVM::~AVM() { ; }

void		AVM::push(IOperand const * type) {
	this->_values.insert(this->_values.begin(), type);
}

void		AVM::assert(IOperand const * type) {
	;
}

void		AVM::pop() {
	std::cout << "POP" << std::endl;
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
	IOperand const *	first = this->_values[0];
	IOperand const *	second = this->_values[1];

	result = (*first) + (*second);
	this->_values.insert(this->_values.begin(), result);
}

void		AVM::sub() {
	std::cout << "SUB" << std::endl;
}

void		AVM::mul() {
	IOperand const *	result;
	IOperand const *	first = this->_values[0];
	IOperand const *	second = this->_values[1];

	result = (*first) * (*second);
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