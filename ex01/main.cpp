/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:17:34 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/24 14:13:59 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
    Data data;
    data.data = 42;

    uintptr_t serializedData = Serializer::serialize(&data);
    Data* deserializedData = Serializer::deserialize(serializedData);
    if (&data == deserializedData) {
        std::cout << "Successo: Il puntatore deserializzato corrisponde a quello originale." << std::endl;
        std::cout << "Valore Data: " << deserializedData->data << std::endl;
    } else {
        std::cout << "Fallimento: Il puntatore deserializzato non corrisponde a quello originale." << std::endl;
    }
    return 0;
}