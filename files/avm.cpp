# include "../header/AVM.hpp"

AVM::AVM() : _exit(false), _end_read(false), _line(0) { 
	this->_cmds[2] = &AVM::pop;
	this->_cmds[3] = &AVM::dump;
	this->_cmds[4] = &AVM::add;
	this->_cmds[5] = &AVM::sub;
	this->_cmds[6] = &AVM::mul;
	this->_cmds[7] = &AVM::div;
	this->_cmds[8] = &AVM::mod;
	this->_cmds[9] = &AVM::print;
	this->_cmds[10] = &AVM::exit;
}
AVM::~AVM() { ; }

void			AVM::stringHandling(std::string line, bool file) {
	int					cmd;
	Factory 			factory;

	this->_line++;
	try {
		this->_end_read = Parser::checkEndCmt(line, file, this->_line);
		if (this->_exit == false)
		{
			cmd = Parser::checkCmd(line, this->_line);
			if (cmd == 0)
				this->push(line);
			else if (cmd == 1)
				this->assert(line);
			else if (cmd > 1)
				(this->*_cmds[cmd])();
		}
	} catch (Exception &e) {
		this->_errors.insert(this->_errors.end(), std::string(e.what()));
	}
}

void			AVM::assert(std::string line) {
	std::string			f;
	std::string			s;
	eOperandType		type;
	Factory				factory;
	IOperand 	  const *second;

	type = static_cast<eOperandType>(Parser::getOperandType(line, this->_line));
	Parser::checkNumber(type, line, this->_line);
	Parser::checkOverflow(type, line, this->_line);
	second = factory.createOperand(static_cast<eOperandType>(type), line);
	s = second->toString();
	if (!this->_exit) {
		if (this->_values.size() < 1)
			throw Exception("Assert on Empty stack", this->_line);

		f = this->_values[0]->toString();
		if (second->getType() != (*this->_values[0]).getType() || s.compare(f))
			throw Exception("Assert Not equal", this->_line);
	}
}

void			AVM::push(std::string line) {
	eOperandType		type;
	Factory				factory;

	type = static_cast<eOperandType>(Parser::getOperandType(line, this->_line));
	Parser::checkNumber(type, line, this->_line);
	Parser::checkOverflow(type, line, this->_line);
	if (!this->_exit)
		this->_values.insert(this->_values.begin(), factory.createOperand(type, line));
}

void			AVM::add() {
	IOperand const *	result;
	IOperand const *	first;
	IOperand const *	second;
	std::stringstream	error;

	if (!this->_exit) {
		if (this->_values.size() < 2)
			throw Exception("Try use Add on 1 element or less", this->_line);
		first = this->_values[1];
		second = this->_values[0];
		this->_values.erase(_values.begin(), _values.begin() + 2);

		result = (*first) + (*second);
		this->_values.insert(this->_values.begin(), result);
	}
}

void			AVM::sub() {
	IOperand const *	result;
	IOperand const *	first;
	IOperand const *	second;

	if (!this->_exit) {
		if (this->_values.size() < 2)
			throw Exception("Try use Sub on 1 element or less", this->_line);
		first = this->_values[1];
		second = this->_values[0];
		this->_values.erase(_values.begin(), _values.begin() + 2);

		result = (*first) - (*second);
		this->_values.insert(this->_values.begin(), result);
	}
}

void			AVM::mul() {
	IOperand const *	result;
	IOperand const *	first;
	IOperand const *	second;

	if (!this->_exit) {
		if (this->_values.size() < 2)
			throw Exception("Try use Mul on 1 element or less", this->_line);
		first = this->_values[1];
		second = this->_values[0];
		this->_values.erase(_values.begin(), _values.begin() + 2);

		result = (*first) * (*second);
		this->_values.insert(this->_values.begin(), result);
	}
}

void			AVM::div() {
	IOperand const *	result;
	IOperand const *	first;
	IOperand const *	second;
	std::stringstream	error;

	if (!this->_exit) {
		if (this->_values.size() < 2)
			throw Exception("Try use Div on 1 element or less", this->_line);
		first = this->_values[1];
		second = this->_values[0];
		if (std::stod(second->toString()) == 0)
			throw Exception("Try Div on 0", this->_line);
		this->_values.erase(_values.begin(), _values.begin() + 2);

		result = (*first) / (*second);
		this->_values.insert(this->_values.begin(), result);
	}
}

void			AVM::mod() {
	IOperand const *	result;
	IOperand const *	first;
	IOperand const *	second;

	if (!this->_exit) {
		if (this->_values.size() < 2)
			throw Exception("Try use Mod on 1 element or less", this->_line);
		first = this->_values[1];
		second = this->_values[0];
		if (std::stod(second->toString()) == 0)
			throw Exception("Try Mod on 0", this->_line);
		this->_values.erase(_values.begin(), _values.begin() + 2);

		result = (*first) % (*second);
		this->_values.insert(this->_values.begin(), result);
	}
}

void			AVM::pop() {
	if (!this->_exit) {
		if (this->_values.size() < 1)
			throw Exception("Pop on Empty stack", this->_line);
		this->_values.erase(_values.begin());
	}
}

void			AVM::dump() {
	std::vector<IOperand const *>::iterator i = this->_values.begin();

	if (!this->_exit) {
		while (i != _values.end()) {
			this->_result.insert(this->_result.end(), (*(*i)).toString());
			i++;
		}
	}
}

void			AVM::print() {
	IOperand const *	first;
	char				c;
	std::string 		str;

	if (!this->_exit) {
		if (this->_values.size() < 1)
			throw Exception("Print on Empty stack", this->_line);
		first = this->_values[0];
		if (first->getType() != INT8)
			throw Exception("Print type must be 'int8'", this->_line);
		c = std::stoi(first->toString());

		this->_result.insert(this->_result.end(), str + c);
	}
}

void			AVM::exit() { this->_exit = 1; }
bool			AVM::getEndRead(void) const { return this->_end_read; }
bool			AVM::getExit(void) const { return this->_exit; }


void			AVM::displayResult(void) {
	std::vector<std::string>::iterator i = this->_result.begin();

	while (i != this->_result.end()) {
		std::cout << (*i) << std::endl;
		i++;
	}
}

void			AVM::displayErrors(void) {
	std::vector<std::string>::iterator i = this->_errors.begin();

	while (i != this->_errors.end()) {
		std::cout << (*i);
		i++;
	}
}
