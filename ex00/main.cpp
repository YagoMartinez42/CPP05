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
	std::cout << "==================================" << std::endl;
	std::cout << "|    Two bureaucrats are here    |" << std::endl;
	std::cout << "==================================" << std::endl;
	std::cout << milton << std::endl;
	std::cout << gil << std::endl;

	std::cout << std::endl;
	std::cout << "=========================================================" << std::endl;
	std::cout << "| Malcom shouldn't try to join this bureaucratic system |" << std::endl;
	std::cout << "=========================================================" << std::endl;
	try
	{
		std::cout << "Instancing a bureaucrat with grade 266" << std::endl;
		Bureaucrat malcom = Bureaucrat("Malcom", 266);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "=========================================================" << std::endl;
	std::cout << "|  Some people always want more even being at the top   |" << std::endl;
	std::cout << "=========================================================" << std::endl;
	try
	{
		std::cout << "Raising " << gil.getName() << "'s grade" << std::endl;
		gil.raiseGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "=====================================================================" << std::endl;
	std::cout << "| Milton is such a fool that can get a raise and then two demotions |" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	try
	{
		std::cout << "Raising " << milton.getName() << "'s grade" << std::endl;
		milton.raiseGrade();
		std::cout << "After a Raise, " << milton.getName() << " is grade " << milton.getGrade() << std::endl;
		std::cout << "Dropping " << milton.getName() << "'s grade" << std::endl;
		milton.dropGrade();
		std::cout << "Dropping " << milton.getName() << "'s grade" << std::endl;
		milton.dropGrade();
		std::cout << "This message shouldn't be shown, the try block has been interrupted by an exception" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "After all this mess, " << milton.getName() << " is grade " << milton.getGrade() << std::endl;
	return (0);
}
