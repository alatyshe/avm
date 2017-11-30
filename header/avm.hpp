#ifndef AVM_H
# define AVM_H

# define RED				"\x1b[31m"
# define GREEN				"\x1b[32m"
# define YELLOW				"\x1b[33m"
# define BLUE				"\x1b[34m"
# define MAGENTA			"\x1b[35m"
# define CYAN				"\x1b[36m"
# define BLACK				"\x1b[37m"
# define RESET				"\x1b[0m"

# define COMMENT			";"
# define ENDREAD			";;"
// # include <iomanip>

# include <fstream>
# include <iostream>
# include <regex>


# include "IOperand.hpp"
# include "validate.hpp"

class AVM
{
	typedef void	(AVM::*voidOperations)();
protected:
	voidOperations	_arrayCommands[10];


public:
	AVM();
	~AVM();


	//	Commands;
	void		push(/*IOperand const * value*/);
	void		assert(/*IOperand const * value*/);
	void		pop();
	void		dump();
	void		add();
	void		sub();
	void		mul();
	void		div();
	void		mod();
	void		print();
	void 		exit(){};


};

#endif
