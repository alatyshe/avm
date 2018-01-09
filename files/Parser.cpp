#include "../header/Parser.hpp"
#include "../header/Exception.hpp"
#include "../header/AVM.hpp"

Parser::Parser() { ; }
Parser::~Parser() { ; }

void			Parser::checkNumber(eOperandType type, std::string &str, int line) {
	if((type != FLOAT && type != DOUBLE) && !std::regex_match(str, std::regex(INTEGER)))
		throw Exception("Line Error", line);
	else if ((type == FLOAT || type == DOUBLE) && !std::regex_match(str, std::regex(FLOAT_DOUBLE)))
		throw Exception("Line Error", line);
}

int				Parser::checkOverflow( eOperandType type, std::string &value, int line) {
	if (type == INT8 || type == INT16 || type == INT32) {
		int64_t			tmp;
		int				max;
		int				min;

		if (type == INT8) {
			max = std::numeric_limits<int8_t>::max();
			min = std::numeric_limits<int8_t>::min();
		} else if (type == INT16) {
			max = std::numeric_limits<int16_t>::max();
			min = std::numeric_limits<int16_t>::min();
		} else {
			max = std::numeric_limits<int32_t>::max();
			min = std::numeric_limits<int32_t>::min();
		}
		tmp = std::stold(value);
		if (tmp < min)
			throw Exception("Underflow", line);
		else if (tmp > max)
			throw Exception("Overflow", line);
	} else if (type == FLOAT || type == DOUBLE) {
		long double			tmp;
		long double			max;
		long double			min;

		if (type == FLOAT) {
			max = std::numeric_limits<float>::max();
			min = -std::numeric_limits<float>::max();
		} else {
			max = std::numeric_limits<double>::max();
			min = -std::numeric_limits<double>::max();
		}
		tmp = std::stold(value);
		if (tmp < min)
			throw Exception("Underflow", line);
		else if (tmp > max)
			throw Exception("Overflow", line);
	}
	return (1);
}
