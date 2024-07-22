/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:53:17 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/22 17:07:18 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data
{
	int data;
};

class Serializer
{
private:
	Serializer(void);
	Serializer(const Serializer &copy);
	Serializer&	operator=(const Serializer &s);
public:
	~Serializer(void);
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif