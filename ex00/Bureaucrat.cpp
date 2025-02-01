/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:57:25 by samartin          #+#    #+#             */
/*   Updated: 2025/02/01 19:17:57 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/**
 * Constructors and destructor.
 * Classes with constant attributes can't have a copy constructor neither an
 *  asignment operator, because consts can only be initiallized and not asigned.
 */

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string nameP, int gradeP) : _name(nameP), _grade(gradeP)
{
	//Aquí va la cosa de este ejercicio
}

Bureaucrat::~Bureaucrat() {}

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
	this->_grade--; //check
}

void Bureaucrat::dropGrade()
{
	this->_grade++; //check
}
