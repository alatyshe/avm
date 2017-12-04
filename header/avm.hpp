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

# include <fstream>
# include <iostream>
# include <vector>
# include <limits>
# include <regex>


# include "IOperand.hpp"
# include "validate.hpp"

class IOperand;

class AVM
{
protected:
	std::vector<IOperand const *>	_values;

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

private:
	AVM&				operator=(const AVM& src);
	AVM(const AVM&);
};

#endif
