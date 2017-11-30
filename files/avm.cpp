# include "../header/validate.hpp"
# include "../header/avm.hpp"

// # include "../includes/OperandFactory.hpp"
// # include "../includes/Exception.hpp"

AVM::AVM()
{
	this->_arrayCommands[1] = &AVM::pop;
	this->_arrayCommands[3] = &AVM::dump;
	this->_arrayCommands[4] = &AVM::add;
	this->_arrayCommands[5] = &AVM::sub;
	this->_arrayCommands[6] = &AVM::mul;
	this->_arrayCommands[7] = &AVM::div;
	this->_arrayCommands[8] = &AVM::mod;
	this->_arrayCommands[9] = &AVM::print;
}

AVM::~AVM()
{

}

void		AVM::push(/*IOperand const * value*/)
{

}

void		AVM::assert(/*IOperand const * value*/)
{

}

void		AVM::pop()
{

}

void		AVM::dump()
{

}

void		AVM::add()
{

}

void		AVM::sub()
{

}

void		AVM::mul()
{

}

void		AVM::div()
{

}

void		AVM::mod()
{

}

void		AVM::print()
{

}