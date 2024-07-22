#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cctype> // per isprint
#include <cstdlib> // per std::strtof, std::strtod
#include <sstream> // per std::stringstream

class ScalarConverter {
private:
    ScalarConverter(void);
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter& operator=(const ScalarConverter &sc);
	~ScalarConverter(void);

public:
    static void convert(const std::string &literal);
};