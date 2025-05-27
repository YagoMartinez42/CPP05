/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-27 10:11:27 by samartin          #+#    #+#             */
/*   Updated: 2025-05-27 10:11:27 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* Constructor */
Intern::Intern() {}

/* Inter has no attributes, so it copies nothing */
Intern::Intern(const Intern& original)
{
	(void)original;
}

/* Destructor */
Intern::~Intern() {}

/* Inter has no attributes, so it copies nothing */
Intern& Intern::operator=(const Intern& original)
{
	(void)original;
	return (*this);
}

/* Utility member functions */
AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	std::string names[3] = { FORM1, FORM2, FORM3 };
	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			switch (i)
			{
			case 0:
				return new ShrubberyCreationForm(target);
				break;
			case 1:
				return new RobotomyRequestForm(target);
				break;
			case 2:
				return new PresidentialPardonForm(target);
				break;
			}
		}
	}
	throw Intern::InvalidFormName();
	return (NULL);
}

/* Exception classes `what()` override */
const char *Intern::InvalidFormName::what() const throw()
{
	return "Error: Invalid Form Name";
}