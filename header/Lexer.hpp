#ifndef LEXER_H
# define LEXER_H

# include <string>

class Lexer {

public:
	Lexer();
	~Lexer();

	int		static checkCmd(std::string &str, int line);
	bool	static checkEndCmt(std::string &str, bool end_read, int line);
	int		static getOperandType(std::string &str, int line);

private:
	Lexer	&operator=(const Lexer& src);
	Lexer(const Lexer &src);
};

#endif
