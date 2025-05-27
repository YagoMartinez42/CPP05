/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-30 11:28:42 by samartin          #+#    #+#             */
/*   Updated: 2025-04-30 11:28:42 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

/* Constructors (Default, copy, set target) and destructor */

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& orig) : AForm(orig.getName(), orig.getGrade2Sign(), orig.getGrade2Exe()) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string targetP) : AForm("Shrubbery Creation Form", 145, 137), _target(targetP) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* Concrete Form execute override */

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string ATree = "   o\n oooo\n oooooo\n oooo\n  ||\n";
	std::string alsoATree = "Enjoy\n └-this\n └-ascci tree";
	std::string fileName = this->_target + "_shrubbery";
	std::ofstream aFile;

	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (this->getGrade2Exe() < executor.getGrade())
		throw AForm::GradeTooLowException();
	aFile.open (fileName.c_str());
	aFile << ATree << std::endl << alsoATree << std::endl;
}
