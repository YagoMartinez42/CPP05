/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-10 18:34:30 by samartin          #+#    #+#             */
/*   Updated: 2025-05-10 18:34:30 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

/* Constructors (Default, copy, set target) and destructor */

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& orig) : AForm(orig.getName(), orig.getGrade2Sign(), orig.getGrade2Exe()) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string targetP) : AForm("Presidential Pardon Form", 25, 5), _target(targetP) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

/* Concrete Form execute override */

void PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (this->getGrade2Exe() > executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
