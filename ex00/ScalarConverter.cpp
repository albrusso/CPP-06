/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:12:50 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/23 19:03:30 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string.h>

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverte default costructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
	std::cout << "ScalarConverter copy costructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& )
{
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

void printChar(double d)
{
	char c = static_cast<char> (d);
	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void printInt(double d)
{
	int n = static_cast<int> (d);
	if (n < INT_MIN || n > INT_MAX)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << n << std::endl;
}

void printFloat(double d, std::string s)
{
	std::string subs = s.substr(s.find('.') + 1);
	int	size = subs.size();
	float f = static_cast<float> (d);
	if (subs.empty())
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
	{
		if (subs.find('f') && size > 1)
			size--;
		std::cout << "float: " << std::fixed << std::setprecision(size) << f << "f" << std::endl;
	}
}

void printDouble(double d, std::string s)
{
	std::string subs = s.substr(s.find('.') + 1);
	int	size = subs.size();

	if (subs.empty())
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	else
	{
		if (subs.find('f'))
			size--;
		std::cout << "float: " << std::fixed << std::setprecision(size) << d << std::endl;
	}
}

void ScalarConverter::convert(const std::string &s)
{
    if (s.length() == 1 && (s[0] > 32 && s[0] < 126) && !std::isdigit(s[0])) {
        char c = s[0];
        std::cout << "char: '" << s[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    // Gestione delle conversioni
    char* end;
    errno = 0;  // Reset errno before conversion
    double d;

    if (strcmp(s.c_str(), "-inff") == 0 || strcmp(s.c_str(), "+inff") == 0 || strcmp(s.c_str(), "nanf") == 0) {
        d = static_cast<double>(strtof(s.c_str(), &end));
    } else if (strcmp(s.c_str(), "-inf") == 0 || strcmp(s.c_str(), "+inf") == 0 || strcmp(s.c_str(), "nan") == 0) {
        d = strtod(s.c_str(), &end);
    } else {
        d = strtod(s.c_str(), &end);
    }

    // Verifica errori di conversione
    if (errno == ERANGE || (*end != '\0' && *end != 'f')) {
        std::cout << "Invalid literal argument" << std::endl;
        return;
    }

    printChar(d);
    printInt(d);
    printFloat(d, s);
    printDouble(d, s);
}
