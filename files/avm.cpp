# include "../header/AVM.hpp"

AVM::AVM() : _stop(0), _line(1) { ; }
AVM::~AVM() { ; }

int			AVM::checkOverflow( eOperandType type, std::string const & value ) {
	try {
		if (type == INT8 || type == INT16 || type == INT32) {
			int64_t			tmp;
			int				max;
			int				min;

			if (type == INT8) {
				max = std::numeric_limits<int8_t>::max();
				min = std::numeric_limits<int8_t>::min();
			} else if (type == INT16) {
				max = std::numeric_limits<int16_t>::max();
				min = std::numeric_limits<int16_t>::min();
			} else if (type == INT32) {
				max = std::numeric_limits<int32_t>::max();
				min = std::numeric_limits<int32_t>::min();
			}
			tmp = std::stod(value);
			if (tmp < min)
				throw Exception("Error : Underflow");
			else if (tmp > max)
				throw Exception("Error : Overflow");
		} else if (type == FLOAT || type == DOUBLE) {
			double			tmp;
			double			max;
			double			min;

			if (type == FLOAT) {
				max = std::numeric_limits<float>::max();
				min = std::numeric_limits<float>::min();
				std::cout << min << std::endl;
				std::cout << max << std::endl;
			} else if (type == DOUBLE) {
				max = std::numeric_limits<double>::max();
				min = std::numeric_limits<double>::min();
			}
			tmp = std::stod(value);
			if (tmp < min)
				throw Exception("Error : Underflow");
			else if (tmp > max)
				throw Exception("Error : Overflow");
		}
		return (1);
	}
	catch (Exception &e) {
		std::cout << e.what() << std::endl;
		this->_errors.insert(this->_errors.end(), std::string(e.what()));
		return (0);
	}
}

void		AVM::assert(IOperand const * type) {
	std::string			first;
	std::string			second = type->toString();

	try {
		if (!this->_stop) {
			if (this->_values.size() < 1)
				throw Exception("ERROR : Assert on Empty stack", this->_line);
			first = this->_values[0]->toString();
			if (type->getType() != (*this->_values[0]).getType()
				|| second.compare(first))
				throw Exception("ERROR : Assert Not equal", this->_line);
		}
	}
	catch (Exception &e) {
		std::cout << e.what() << std::endl;
		this->_errors.insert(this->_errors.end(), std::string(e.what()));
	}
}

void		AVM::add() {
	IOperand const *	result;
	IOperand const *	first;
	IOperand const *	second;
	std::stringstream	error;

	try {
		if (!this->_stop) {
			if (this->_values.size() < 2)
				throw Exception("ERROR : Try use Add on 1 element or less", this->_line);
			first = this->_values[0];
			second = this->_values[1];
			
			result = (*first) + (*second);
			this->_values.erase(_values.begin(), _values.begin() + 2);
			this->_values.insert(this->_values.begin(), result);
		}
	}
	catch (Exception &e) {
		std::cout << e.what() << std::endl;
		this->_errors.insert(this->_errors.end(), std::string(e.what()));
	}
}

void		AVM::sub() {
	IOperand const *	result;
	IOperand const *	first;
	IOperand const *	second;

	try {
		if (!this->_stop) {
			if (this->_values.size() < 2)
				throw Exception("ERROR : Try use Sub on 1 element or less", this->_line);
			first = this->_values[0];
			second = this->_values[1];
			
			result = (*first) - (*second);
			this->_values.erase(_values.begin(), _values.begin() + 2);
			this->_values.insert(this->_values.begin(), result);
		}
	}
	catch (Exception &e) {
		std::cout << e.what() << std::endl;
		this->_errors.insert(this->_errors.end(), std::string(e.what()));
	}
}

void		AVM::mul() {
	IOperand const *	result;
	IOperand const *	first;
	IOperand const *	second;

	try {
		if (!this->_stop) {
			if (this->_values.size() < 2)
				throw Exception("ERROR : Try use Mul on 1 element or less", this->_line);
			first = this->_values[0];
			second = this->_values[1];
			
			result = (*first) * (*second);
			this->_values.erase(_values.begin(), _values.begin() + 2);
			this->_values.insert(this->_values.begin(), result);
		}
	}
	catch (Exception &e) {
		std::cout << e.what() << std::endl;
		this->_errors.insert(this->_errors.end(), std::string(e.what()));
	}
}

void		AVM::div() {
	IOperand const *	result;
	IOperand const *	first;
	IOperand const *	second;
	std::stringstream	error;

	try {
		if (!this->_stop) {
			if (this->_values.size() < 2)
				throw Exception("ERROR : Try use Div on 1 element or less", this->_line);
			first = this->_values[0];
			second = this->_values[1];
			if (std::stod(first->toString()) == 0)
				throw Exception("ERROR : Try Div on 0", this->_line);

			result = (*first) / (*second);
			this->_values.erase(_values.begin(), _values.begin() + 2);
			this->_values.insert(this->_values.begin(), result);
		}
	}
	catch (Exception &e) {
		std::cout << e.what() << std::endl;
		this->_errors.insert(this->_errors.end(), std::string(e.what()));
	}
}

void		AVM::mod() {
	IOperand const *	result;
	IOperand const *	first;
	IOperand const *	second;

	try {
		if (!this->_stop) {
			if (this->_values.size() < 2)
				throw Exception("ERROR : Try use Mod on 1 element or less", this->_line);
			first = this->_values[0];
			second = this->_values[1];
		
			result = (*first) % (*second);
			this->_values.erase(_values.begin(), _values.begin() + 2);
			this->_values.insert(this->_values.begin(), result);
		}
	}
	catch (Exception &e) {
		std::cout << e.what() << std::endl;
		this->_errors.insert(this->_errors.end(), std::string(e.what()));
	}
}

void		AVM::push(IOperand const * type) {
	if (!this->_stop)
		this->_values.insert(this->_values.begin(), type);
}

void		AVM::pop() {
	try {
		if (!this->_stop) {
			if (this->_values.size() < 1)
				throw Exception("ERROR : Pop on Empty stack", this->_line);
			this->_values.erase(_values.begin());
		}
	}
	catch (Exception &e) {
		std::cout << e.what() << std::endl;
		this->_errors.insert(this->_errors.end(), std::string(e.what()));
	}
}

void		AVM::dump() {
	std::vector<IOperand const *>::iterator i = this->_values.begin();

	if (!this->_stop) {
		while (i != _values.end()) {
			this->_result.insert(this->_result.end(), (*(*i)).toString());
			
			// std::cout << (*(*i)).toString() << std::endl;
			i++;
		}
	}
}

void		AVM::print() {
	IOperand const *	first;
	char				c;

	try {
		if (!this->_stop) {
			if (this->_values.size() < 1)
				throw Exception("ERROR : Print on Empty stack", this->_line);
			first = this->_values[0];
			if (first->getType() != INT8)
				throw Exception("ERROR : Print type must be 'int8'", this->_line);
			c = std::stoi(first->toString());
			this->_result.insert(this->_result.end(), std::string(&c));

			// std::cout << c << std::endl;
		}
	}
	catch (Exception &e) {
		std::cout << e.what() << std::endl;
		this->_errors.insert(this->_errors.end(), std::string(e.what()));
	}
}

void		AVM::exit() {
	this->_stop = 1;
}

void		AVM::plusLine() {
	this->_line++;
}
