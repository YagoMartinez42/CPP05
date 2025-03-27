/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:37:25 by samartin          #+#    #+#             */
/*   Updated: 2025/03/27 13:00:15 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* Constructors (Default, set type, copy) and destructor */

Form::Form() : _name(""), _grade2Sign(150), _grade2Exe(150) {}

Form::Form(const Form& orig) : _name(orig._name), _grade2Sign(orig._grade2Sign), _grade2Exe(orig._grade2Exe), _signed(orig._signed) {}

Form::Form(const std::string nameP, const int grade2SignP, const int grade2ExeP) : _name(nameP), _grade2Sign(grade2SignP), _grade2Exe(grade2ExeP)
{
	if (this->_grade2Sign < 1 || this->_grade2Exe < 1)
		throw Form::GradeTooHighException();
	else if (this->_grade2Sign > 150 || this->_grade2Exe > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

/* Asignment operator function
  The only non const value is the boolean signed.
  This operator is required by canonical form, but makes no sense to use it
 */

Form& Form::operator=(const Form& orig)
{
	if (this != &orig)
		this->_signed = orig._signed;
	return (*this);
}

/* Getter functions */

std::string const & Form::getName() const
{
	std::string const & nameRef = this->_name;
	return (nameRef);
}

int Form::getGrade2Sign() const
{
	return (this->_grade2Sign);
}

int Form::getGrade2Exe() const
{
	return (this->_grade2Exe);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

/* Sign function */

void Form::beSigned(Bureaucrat bur)
{
	if (bur.getGrade() <= this->_grade2Sign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

/* Exception classes `what()` override */

const char *Form::GradeTooHighException::what() const throw()
{
	return "Error: Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Error: Grade too low";
}

/* Ostream operator override */

std::ostream& operator<<(std::ostream& stm, const Form& form)
{
	stm << "Form " << form.getName() << ":" << std::endl;
	stm << "Bureaucrat grade needed to sign it: " << form.getGrade2Sign() << "." << std::endl;
	stm << "Bureaucrat grade needed to execute it: " << form.getGrade2Exe() << "." << std::endl;
	stm << "It is ";
	if (!form.getSigned())
		stm << "not ";
	stm << "signed." << std::endl;
	return (stm);
}
