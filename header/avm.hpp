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
# define INTEGER			"([-]?)([0-9]+)([)])([\\s]*)"
# define FLOAT_DOUBLE		"([-]?)([0-9]+)([.]*)([0-9]*)([)])([\\s]*)"


# include <iostream>
# include <iomanip>
# include <fstream>
# include <vector>
# include <limits>
# include <regex>
# include <string>
# include <sstream>

# include "IOperand.hpp"
# include "Exception.hpp"
# include "Parser.hpp"
# include "Factory.hpp"

class AVM : public Factory
{

	typedef void	(AVM::*Commands)();

protected:
	std::vector<IOperand const *>	_values;
	std::vector<std::string>		_errors;
	std::vector<std::string>		_result;
	bool							_exit;
	bool							_end_read;
	int								_line;
	Commands 						_cmds[11];

public:
	AVM();
	~AVM();

	void				stringHandling(std::string line, bool file);

	void				push(std::string line);
	void				assert(std::string line);
	void				pop(void);
	void				dump(void);
	void				add(void);
	void				sub(void);
	void				mul(void);
	void				div(void);
	void				mod(void);
	void				print(void);
	void 				exit(void);

	bool				getEndRead(void) const;
	bool				getExit(void) const;

	void				displayResult(void);
	void				displayErrors(void);


private:
	AVM&				operator=(const AVM& src);
	AVM(const AVM&);

};

#endif
