/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:57:25 by samartin          #+#    #+#             */
/*   Updated: 2025/03/27 13:00:06 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* Constructors (Default, set type, copy) and destructor */

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& orig) : _name(orig._name), _grade(orig._grade) {}

Bureaucrat::Bureaucrat(const std::string nameP, int gradeP) : _name(nameP), _grade(gradeP)
{
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

/* Asignment operator function
  whatch out: name is constant and it will only copy the grade
 */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& orig)
{
	if (this != &orig)
		this->_grade = orig._grade;
	return (*this);
}

/* Getter functions */

std::string const & Bureaucrat::getName() const
{
	std::string const & nameRef = this->_name;
	return(nameRef);
}

int Bureaucrat::getGrade() const
{
	return(this->_grade);
}

/* Utility member functions */

void Bureaucrat::raiseGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::dropGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

/* Exception classes `what()` override */

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: Grade too low";
}

/* Ostream operator override */

std::ostream& operator<<(std::ostream& stm, const Bureaucrat& bur)
{
	stm << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return (stm);
}
