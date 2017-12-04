#ifndef VALIDATE_H
# define VALIDATE_H

# include "IOperand.hpp"
# include "avm.hpp"

class Validate
{

public:
	Validate();
	~Validate();

	bool			static checkEndRead(std::string &str);
	bool			static checkComment(std::string &str);
	int				static checkCmd(std::string &str);
	int				static checkLine(std::string &str, bool inputType);
	eOperandType 	static getOperandType(std::string &str);
};

#endif
