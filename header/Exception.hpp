#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

# include <exception>
# include <string>
# include <sstream>

class					Exception: public std::exception
{
private:
	std::string		_error;
public:
					Exception(void);
					Exception(std::string const &error);
					Exception(std::string const &error, int line);
					~Exception(void) throw();
	char const		*what(void) const throw();
};

#endif 