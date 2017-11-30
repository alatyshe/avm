#include "../header/validate.hpp"
#include "../header/avm.hpp"

void			read_file(std::string str)
{
	std::string 		line;	
	std::ifstream 		file(str);

	std::cout << line << std::endl;
	while (std::getline (file, line))
	{
		std::cout << line << std::endl;
		VALIDATE::checkLine(&line, false);
	}
}

void			read_input()
{
	std::string 		line;
	bool				checkEnd;

	checkEnd = true;
	while (checkEnd)
	{
		std::getline (std::cin, line);
		checkEnd = VALIDATE::checkLine(&line, true);
	}
}

int				main(int argc, char **argv)
{
	int			count_players;
	AVM			machine;
	VALIDATE	valid;

	count_players = 0;
	if (argc == 2)	//	read file
		read_file(argv[1]);
	else			//	read input
		read_input();
	return (0);
}
