# include "../header/validate.hpp"
# include "../header/avm.hpp"
# include "../header/Exception.hpp"

Validate::Validate() { ; }
Validate::~Validate() { ; }

	// if((type != FLOAT && type != DOUBLE) && !std::regex_match(value, std::regex(INTEGER)))
	// 	throw Exception("Error : Syntax error");
	// else if ((type == FLOAT || type == DOUBLE) && !std::regex_match(value, std::regex(FLOAT_DOUBLE)))
	// 	throw Exception("Error : Syntax error");

bool			Validate::checkEndRead(std::string &str) // checking on  " ;; "
{
	int			pos;

	pos = str.find(ENDREAD);
	if (pos != -1) {
		pos = str.find_first_not_of(" \n", pos + 2);
		if (pos != -1 && pos != str.size()) {	// проверка на разную хуйню в после окончания ввода
			std::cout << "WHAT FUCK IS THAT" << std::endl;
		}
		return (true);
	}
	return (false);
}

bool			Validate::checkComment(std::string &str)// check and delete comments
{
	int			pos;

	pos = str.find(COMMENT);
	if (pos != -1)
		str.erase(pos, str.size());
	return true;
}

int				Validate::checkCmd(std::string &str)	// check on valid command
{
	int			i = 0;
	std::string	cmds[11] = {
		"push ","assert ","pop",
		"dump","add","sub",
		"mul","div","mod",
		"print", "exit"};

	while (i < 11) {
		if (str.compare(0, cmds[i].size(), cmds[i]) == 0) {
			str.erase(0, cmds[i].size());
			std::cout << GREEN <<  "I FIND CMD!" << RESET << std::endl;
			return i;
		}
		i++;
	}
	std::cout << RED << "FUCK, I DONT FIND CMD!" << RESET << std::endl;
	return (-1);
}

int				Validate::checkLine(std::string &str, bool inputType)
{
	bool		checkEnd;
	int			i;

	if (inputType == true)
		checkEnd = checkEndRead(str);
	else
		checkEnd = false;

	if (!checkEnd) {
		checkComment(str);
		i = checkCmd(str);
	}
	return i;
}


eOperandType 	Validate::getOperandType(std::string &str)
{
	int				i;
	eOperandType	type;
	std::string		types[5] = {
		"int8(","int16(","int32(",
		"float(","double("
	};

	i = 0;
	while (i < 5) {
		if (str.compare(0, types[i].size(), types[i]) == 0)
		{
			str.erase(0, types[i].size());
			if (i == 0)
				type = INT8;
			else if (i == 1)
				type = INT16;
			else if (i == 2)
				type = INT32;
			else if (i == 3)
				type = FLOAT;
			else if (i == 4)
				type = DOUBLE;
			return type;
		}
		i++;
	}
	return type;
}