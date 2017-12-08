#ifndef PARSER_H
# define PARSER_H

# include "IOperand.hpp"

class Parser
{

public:
	Parser();
	~Parser();

	bool			static checkEndRead(std::string &str);
	bool			static checkComment(std::string &str);
	int				static checkCmd(std::string &str);
	int				static checkLine(std::string &str, bool inputType);
	eOperandType 	static getOperandType(std::string &str);

};

#endif
