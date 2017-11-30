# include "../header/validate.hpp"
# include "../header/avm.hpp"

// # include "../includes/OperandFactory.hpp"
// # include "../includes/Exception.hpp"

VALIDATE::VALIDATE()
{

}

VALIDATE::~VALIDATE()
{

}

bool			VALIDATE::checkEndRead(std::string *str)
{
	int			pos;

	pos = str->find(ENDREAD);
	if (pos != -1)
	{
		pos = str->find_first_not_of(" \n", pos + 2);
		if (pos != -1 && pos != str->size())	// проверка на разную хуйню в после окончания ввода
		{
			std::cout << "WHAT FUCK IS THAT" << std::endl;
		}
		return (true);
	}
	return (false);
}

bool			VALIDATE::checkComment(std::string *str)
{
	int			pos;

	pos = str->find(COMMENT);
	if (pos != -1)
		str->erase(pos, str->size());
	return true;
}

void			VALIDATE::checkCmd(std::string *str)
{
	int			i = 0;
	std::string	cmds[11] = {
		"push ","assert ","pop",
		"dump","add","sub",
		"mul","div","mod",
		"print", "exit"};

	while (i < 11)
	{

		if (str->compare(0, cmds[i].size(), cmds[i]) == 0)
		{
			std::cout << GREEN <<  "I FIND CMD!" << RESET << std::endl;
			return ;
		}
		i++;
	}
	std::cout << RED << "FUCK, I DONT FIND CMD!" << RESET << std::endl;
}

bool			VALIDATE::checkLine(std::string *str, bool inputType)
{
	bool		checkEnd;

	if (inputType == true)
		checkEnd = checkEndRead(str);
	else
		checkEnd = false;
	if (!checkEnd)
	{
		checkComment(str);
		checkCmd(str);
	}
	else
		return false;
	return true;
}