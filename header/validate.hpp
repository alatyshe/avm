#ifndef VALIDATE_H
# define VALIDATE_H

# include "IOperand.hpp"
# include "avm.hpp"

class VALIDATE
{

public:
	VALIDATE();
	~VALIDATE();


	bool		static checkEndRead(std::string *str);
	bool		static checkComment(std::string *str);
	void		static checkCmd(std::string *str);
	bool		static checkLine(std::string *str, bool inputType);
	
};

#endif
