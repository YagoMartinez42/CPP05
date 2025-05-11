/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:37:25 by samartin          #+#    #+#             */
/*   Updated: 2025/03/27 21:23:44 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* Constructors (Default, set type, copy) and destructor */

AForm::AForm() : _name(""), _grade2Sign(150), _grade2Exe(150) {}

AForm::AForm(const AForm& orig) : _name(orig._name), _grade2Sign(orig._grade2Sign), _grade2Exe(orig._grade2Exe), _signed(orig._signed) {}

AForm::AForm(const std::string nameP, const int grade2SignP, const int grade2ExeP) : _name(nameP), _grade2Sign(grade2SignP), _grade2Exe(grade2ExeP)
{
	if (this->_grade2Sign < 1 || this->_grade2Exe < 1)
		throw AForm::GradeTooHighException();
	else if (this->_grade2Sign > 150 || this->_grade2Exe > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

/* Asignment operator function
  The only non const value is the boolean `signed`.
  This operator is required by canonical form, but makes no sense to use it
 */

AForm& AForm::operator=(const AForm& orig)
{
	if (this != &orig)
		this->_signed = orig._signed;
	return (*this);
}

/* Getter functions */

std::string const & AForm::getName() const
{
	std::string const & nameRef = this->_name;
	return (nameRef);
}

int AForm::getGrade2Sign() const
{
	return (this->_grade2Sign);
}

int AForm::getGrade2Exe() const
{
	return (this->_grade2Exe);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

/* Sign function */

void AForm::beSigned(Bureaucrat *bur)
{
	if (bur->getGrade() <= this->_grade2Sign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

/* Exception classes `what()` override */

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Error: Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Error: Grade too low";
}

/* Ostream operator override */

std::ostream& operator<<(std::ostream& stm, const AForm& AForm)
{
	stm << "Form " << AForm.getName() << ":" << std::endl;
	stm << "Bureaucrat grade needed to sign it: " << AForm.getGrade2Sign() << "." << std::endl;
	stm << "Bureaucrat grade needed to execute it: " << AForm.getGrade2Exe() << "." << std::endl;
	stm << "It is ";
	if (!AForm.getSigned())
		stm << "not ";
	stm << "signed." << std::endl;
	return (stm);
}
