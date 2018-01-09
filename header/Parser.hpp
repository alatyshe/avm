#ifndef PARSER_H
# define PARSER_H

# include "IOperand.hpp"

class Parser {

public:
	Parser();
	~Parser();

	void	static checkNumber(eOperandType type, std::string &str, int line);
	int		static checkOverflow( eOperandType type, std::string &value, int line );

private:
	Parser	&operator=(const Parser& src);
	Parser(const Parser &src);
};

#endif
