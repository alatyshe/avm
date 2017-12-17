#ifndef PARSER_H
# define PARSER_H

# include "IOperand.hpp"

class Parser
{

public:
	Parser();
	~Parser();

	void	static checkNumber(eOperandType type, std::string &str, int line);
	int		static checkOverflow( eOperandType type, std::string &value, int line );
	int		static checkCmd(std::string &str, int line);
	bool	static checkEndCmt(std::string &str, bool end_read, int line);
	int		static getOperandType(std::string &str, int line);
};

#endif
