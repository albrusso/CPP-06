/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:35:15 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/22 18:07:37 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void)
{
	std::cout << "Base destructor called" << std::endl;
}

Base * generate(void)
{
	std::srand(static_cast <unsigned int> (std::time(nullptr)));
	int n = std::rand() % 3;
	switch (n)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return nullptr;
	}
}

void identify(Base* p)
{
	if (dynamic_cast <A*> (p))
		std::cout << "p point at type A" << std::endl;
	else if (dynamic_cast <B*> (p))
		std::cout << "p point at type B" << std::endl;
	else if (dynamic_cast <C*> (p))
		std::cout << "p point at type C" << std::endl;
}

void identify(Base& p)
{
	try
	{
        A &a = dynamic_cast <A&> (p);
        std::cout << "p is a reference at type A" << std::endl;
		(void)a;
    } catch (std::bad_cast &bc)
	{
	}
    try
	{
        B &b = dynamic_cast <B&> (p);
        std::cout << "p is a reference at type B" << std::endl;
		(void)b;
    } catch (std::bad_cast& bc)
	{
	}
    try
	{
        C &c = dynamic_cast <C&> (p);
        std::cout << "p is a reference at type C" << std::endl;
		(void)c;
    } catch (std::bad_cast &bc)
	{
	}
}