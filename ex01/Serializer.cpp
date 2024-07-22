/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:00:53 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/22 17:55:19 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer default costructor called" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
	std::cout << "Serializer copy costructor called" << std::endl;
}

Serializer&	Serializer::operator=(const Serializer &s)
{
	(void)s;
	return *this;
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast <uintptr_t> (ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast <Data *> (raw);
}