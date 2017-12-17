#include "../header/Factory.hpp"
#include "../header/AVM.hpp"
#include "../header/Operand.hpp"
#include "../header/Exception.hpp"

int				main(int argc, char **argv)
{
	int					count_players;
	AVM					machine;
	std::string 		line;

	count_players = 0;
	if (argc == 2) {					//	read from file
		std::ifstream 		input(argv[1]);
		if (input)
			while ( machine.getEndRead() == false && std::getline (input, line))
				machine.stringHandling(line, true);
	} else {							//	read from input
		while ( machine.getEndRead() == false && std::getline (std::cin, line))
			machine.stringHandling(line, true);
	}

	if (machine.getExit() == true)
	{
		machine.displayErrors();
		machine.displayResult();
	}
	else
	{
		machine.displayErrors();
		std::cout << "\033[1;31mERROR \033[0;0m: EXIT cmd missing" << std::endl;
	}
	return (0);
}
