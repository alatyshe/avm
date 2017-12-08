#include "../header/Parser.hpp"
#include "../header/Factory.hpp"
#include "../header/AVM.hpp"
#include "../header/Operand.hpp"
#include "../header/Exception.hpp"

void			read_input(AVM &machine)
{
	std::string 		line;
	int					cmd;
	Factory				factory;
	eOperandType		type;

	while (std::getline (std::cin, line)) {
		cmd = Parser::checkLine(line, false);
		// std::cout << line << std::endl;
		// std::cout << cmd << std::endl;
		if (cmd == 0)
		{
			type = Parser::getOperandType(line);
			if (machine.checkOverflow(type, line))
				machine.push(factory.createOperand(type, line));
		}
		else if (cmd == 1)
		{
			type = Parser::getOperandType(line);
			if (machine.checkOverflow(type, line))
				machine.assert(factory.createOperand(type, line));
		}
		else if (cmd == 2)
			machine.pop();
		else if (cmd == 3)
			machine.dump();
		else if (cmd == 4)
			machine.add();
		else if (cmd == 5)
			machine.sub();
		else if (cmd == 6)
			machine.mul();
		else if (cmd == 7)
			machine.div();
		else if (cmd == 8)
			machine.mod();
		else if (cmd == 9)
			machine.print();
		else if (cmd == 10)
			machine.exit();
		machine.plusLine();
	}
}

int				main(int argc, char **argv)
{
	int			count_players;
	AVM			machine;
	Parser	valid;

	count_players = 0;
	if (argc == 2)	//	read from file
		read_input(machine);
	else			//	read from input
		read_input(machine);

	return (0);
}


// void			read_file(std::string str, AVM &machine)
// {
// 	std::string 		line;	
// 	std::ifstream 		input(str);
// 	int					cmd;
// 	Factory				factory;
// 	eOperandType		type;

// 	while (std::getline (input, line)) {
// 		cmd = Parser::checkLine(line, false);
// 		if (cmd == 0)
// 		{
// 			type = Parser::getOperandType(line);
// 			machine.push(factory.createOperand(type, line));
// 		}
// 		else if (cmd == 1)
// 		{
// 			Parser::getOperandType(line);
// 			// machine.assert()
// 		}
// 		else if (cmd == 2)
// 			machine.pop();
// 		else if (cmd == 3)
// 			machine.dump();
// 		else if (cmd == 4)
// 			machine.add();
// 		else if (cmd == 5)
// 			machine.sub();
// 		else if (cmd == 6)
// 			machine.mul();
// 		else if (cmd == 7)
// 			machine.div();
// 		else if (cmd == 8)
// 			machine.mod();
// 		else if (cmd == 9)
// 			machine.print();
// 		else if (cmd == 10)
// 			machine.exit();
// 	}
// }