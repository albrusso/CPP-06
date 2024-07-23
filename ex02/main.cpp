/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:59:39 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/23 19:06:56 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <unistd.h>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void)
{
	Base *p;
	for (int i = 0; i < 6; i++)
	{
		p = generate();
		identify(p);
		identify(*p);
		delete p;
		sleep(1);
	}
	return (0);
}