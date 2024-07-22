/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:30:34 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/22 17:43:40 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

class Base
{
public:
	virtual ~Base(void);
};

class	A : public Base 
{
};

class	B : public Base
{
};

class	C : public Base
{
};

#endif