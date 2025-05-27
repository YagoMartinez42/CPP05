/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-10 18:30:10 by samartin          #+#    #+#             */
/*   Updated: 2025-05-10 18:30:10 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

/* Constructors (Default, copy, set target) and destructor */

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& orig) : AForm(orig.getName(), orig.getGrade2Sign(), orig.getGrade2Exe()) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string targetP) : AForm("Robotomy Request Form", 72, 45), _target(targetP) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

/* Concrete Form execute override */

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (this->getGrade2Exe() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::srand(std::time(0));
	std::cout << "\e[33mdrrññññiiiiii!!!\e[00m" << std::endl;
	if (std::rand() & 1)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else 
		std::cout << "The robotomy failed." << std::endl;
}
