/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:39:13 by samartin          #+#    #+#             */
/*   Updated: 2025/02/23 17:19:23 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat milton = Bureaucrat("Milton", 150);
	Bureaucrat gil = Bureaucrat ("Gil", 1);

	std::cout << std::endl;
	std::cout << "\e[33m\e[44m==================================\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m|    Two bureaucrats are here    |\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m==================================\e[00m" << std::endl;
	std::cout << milton << std::endl;
	std::cout << gil << std::endl;

	std::cout << std::endl;
	std::cout << "\e[33m\e[44m=========================================================\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m| Malcom shouldn't try to join this bureaucratic system |\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m=========================================================\e[00m" << std::endl;
	try
	{
		std::cout << "\e[32mInstancing a bureaucrat with grade 266\e[00m" << std::endl;
		Bureaucrat malcom = Bureaucrat("Malcom", 266);
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "\e[33m\e[44m=========================================================\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m|  Some people always want more even being at the top   |\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m=========================================================\e[00m" << std::endl;
	try
	{
		std::cout << "\e[32mRaising " << gil.getName() << "'s grade\e[00m" << std::endl;
		gil.raiseGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "\e[33m\e[44m=====================================================================\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m| Milton is such a fool that can get a raise and then two demotions |\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m=====================================================================\e[00m" << std::endl;
	try
	{
		std::cout << "\e[32mRaising " << milton.getName() << "'s grade\e[00m" << std::endl;
		milton.raiseGrade();
		std::cout << "\e[32mAfter a Raise, " << milton.getName() << " is grade " << milton.getGrade() << "\e[00m" << std::endl;
		std::cout << "\e[32mDropping " << milton.getName() << "'s grade\e[00m" << std::endl;
		milton.dropGrade();
		std::cout << "\e[32mDropping " << milton.getName() << "'s grade\e[00m" << std::endl;
		milton.dropGrade();
		std::cout << "This message shouldn't be shown, the try block has been interrupted by an exception" << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\e[32mAfter all this mess, " << milton.getName() << " is the same grade.\e[00m" << std::endl;
	std::cout << milton << std::endl;
	return (0);
}
