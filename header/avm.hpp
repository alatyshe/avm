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
# define FLOAT_DOUBLE		"([-]?)([0-9]+)(.)([0-9]+)([)])([\\s]*)"


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
# include "factory.hpp"
# include "parser.hpp"

class AVM : public Factory, public Parser
{

protected:
	std::vector<IOperand const *>	_values;
	std::vector<std::string>		_errors;
	std::vector<std::string>		_result;
	int								_stop;
	int								_line;

public:
	AVM();
	~AVM();

	void				push(IOperand const * type);
	void				assert(IOperand const * type);
	void				pop(void);
	void				dump(void);
	void				add(void);
	void				sub(void);
	void				mul(void);
	void				div(void);
	void				mod(void);
	void				print(void);
	void 				exit(void);

	void				plusLine(void);
	int					checkOverflow( eOperandType type, std::string const & value );


private:
	AVM&				operator=(const AVM& src);
	AVM(const AVM&);

};

#endif
