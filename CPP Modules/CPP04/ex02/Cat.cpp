/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:03:38 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/17 14:42:02 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->brains = new Brain();
	std::cout << "Default Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = other;
}

Cat::~Cat(void)
{
	delete this->brains;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat Assignement operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->brains = new Brain (*other.brains);
	}
	return (*this);
}

Brain	*Cat::getBrains(void) { return (this->brains); }

void	Cat::makeSound(void) const
{
	std::cout << RED << "Meow" << DEFAULT << std::endl;
}