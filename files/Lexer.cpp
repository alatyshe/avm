#include "../header/Lexer.hpp"
#include "../header/Exception.hpp"
#include "../header/AVM.hpp"

Lexer::Lexer() { ; }
Lexer::~Lexer() { ; }

int				Lexer::checkCmd(std::string &str, int line) {
	std::string	cmds[11] = {
		"push ","assert ","pop",
		"dump","add","sub",
		"mul","div","mod",
		"print", "exit" };

	if (str.size() == 0)
		return (-1);
	for (int i = 0; i < 11; i++) {
		if (str.compare(0, cmds[i].size(), cmds[i]) == 0) {
			str.erase(0, cmds[i].size());
			if (i != 0 && i != 1) {
				str.erase(std::remove(str.begin(),str.end(),' '), str.end());
				if (str.size() != 0)
					throw Exception("Syntax Error", line);
			}
			return i;
		}
	}
	throw Exception("Invalid Command", line);
}

bool			Lexer::checkEndCmt(std::string &str, bool end_read, int line) {
	int			pos;
	bool		res;

	res = false;
	pos = str.find(COMMENT);
	if (pos != -1 && static_cast<int>(str.size()) > (pos + 1) && str[pos + 1] != ';')
		str.erase(pos, str.size());
	if (end_read) {
		pos = str.find(ENDREAD);
		if (pos != -1) {
			if (pos != 0)
				throw Exception("Syntax Error ;;", line);
			pos = str.find_first_not_of(" \n", pos + 2);
			if (pos != -1 && pos != static_cast<int>(str.size()))
				throw Exception("Syntax Error after ;;", line);
			res = true;
		}
	}
	return (res);
}

int 			Lexer::getOperandType(std::string &str, int line) {
	std::string		types[5] = {
		"int8(","int16(","int32(",
		"float(","double(" };

	for (int i = 0; i < 5; i++) {
		if (str.compare(0, types[i].size(), types[i]) == 0) {
			str.erase(0, types[i].size());
			return i;
		}
	}
	throw Exception("Syntax Error at TYPES", line);
}
