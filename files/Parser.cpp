# include "../header/Parser.hpp"
# include "../header/AVM.hpp"
# include "../header/Exception.hpp"


Parser::Parser() { ; }
Parser::~Parser() { ; }

void			Parser::checkNumber(eOperandType type, std::string &str, int line) {
	if((type != FLOAT && type != DOUBLE) && !std::regex_match(str, std::regex(INTEGER)))
		throw Exception("Line Error", line);
	else if ((type == FLOAT || type == DOUBLE) && !std::regex_match(str, std::regex(FLOAT_DOUBLE)))
		throw Exception("Line Error", line);
}

int				Parser::checkOverflow( eOperandType type, std::string &value, int line) {
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
		} else {
			max = std::numeric_limits<int32_t>::max();
			min = std::numeric_limits<int32_t>::min();
		}
		tmp = std::stod(value);
		if (tmp < min)
			throw Exception("Underflow", line);
		else if (tmp > max)
			throw Exception("Overflow", line);
	} else if (type == FLOAT || type == DOUBLE) {
		long double			tmp;
		double				max;
		double				min;

		if (type == FLOAT) {
			max = std::numeric_limits<float>::max();
			min = std::numeric_limits<float>::min();
		} else {
			max = std::numeric_limits<double>::max();
			min = std::numeric_limits<double>::min();
		}
		tmp = std::stod(value);
		if (tmp < min)
			throw Exception("Underflow", line);
		else if (tmp > max)
			throw Exception("Overflow", line);
	}
	return (1);
}


int				Parser::checkCmd(std::string &str, int line)	// check on valid command
{
	std::string	cmds[11] = {
		"push ","assert ","pop",
		"dump","add","sub",
		"mul","div","mod",
		"print", "exit"};

	if (str.size() == 0)
		return (-1);
	for (int i = 0; i < 11; i++)
	{
		if (str.compare(0, cmds[i].size(), cmds[i]) == 0)
		{
			str.erase(0, cmds[i].size());
			if (i != 0 && i != 1)
			{
				str.erase(std::remove(str.begin(),str.end(),' '), str.end());
				if (str.size() != 0)
					throw Exception("Syntax Error", line);
			}
			return i;
		}
	}
	throw Exception("Invalid Command", line);
}

bool			Parser::checkEndCmt(std::string &str, bool end_read, int line) // checking on  " ;; "
{
	int			pos;
	bool		res;

	res = false;
	if (end_read)
	{
		pos = str.find(ENDREAD);
		if (pos != -1) {
			if (pos != 0)
				throw Exception("Syntax Error ;;", line);
			pos = str.find_first_not_of(" \n", pos + 2);
			if (pos != -1 && pos != static_cast<int>(str.size())) // проверка на разную хуйню в после окончания ввода
				throw Exception("Syntax Error after ;;", line);
			res = true;
		}
	}
	pos = str.find(COMMENT);
	if (pos != -1)
		str.erase(pos, str.size());
	return (res);
}

int 			Parser::getOperandType(std::string &str, int line)
{
	std::string		types[5] = {
		"int8(","int16(","int32(",
		"float(","double("
	};

	for (int i = 0; i < 5; i++)
	{
		if (str.compare(0, types[i].size(), types[i]) == 0)
		{
			str.erase(0, types[i].size());
			return i;
		}
	}
	throw Exception("Syntax Error at TYPES", line);
}



