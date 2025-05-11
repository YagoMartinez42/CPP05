/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 16:39:12 by samartin          #+#    #+#             */
/*   Updated: 2025-04-14 16:39:12 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat milton = Bureaucrat("Milton", 100);
	Bureaucrat bob = Bureaucrat ("Bob", 10);

	std::cout << std::endl;
	std::cout << "\e[33m\e[44m==================================\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m|    Two bureaucrats are here    |\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m==================================\e[00m" << std::endl;
	std::cout << milton << std::endl;
	std::cout << bob << std::endl;

	std::cout << std::endl;
	std::cout << "\e[33m\e[44m========================================================\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m| Some forms on the table, but only one is well writen |\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m========================================================\e[00m" << std::endl;
	std::cout << "\e[32mInstancing a form to request more forms\e[00m" << std::endl;
	Form more = Form("More forms petition", 26, 90);
	std::cout << more << std::endl;
	try
	{
		std::cout << "\e[32mInstancing a form to request a break\e[00m" << std::endl;
		Form holi = Form("Holidays break petition", 0, 140);
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\e[32mInstancing a form to request a raise\e[00m" << std::endl;
		Form raise = Form("Salary raise petition", 120, 200);
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "\e[33m\e[44m===============================================\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m|  Now the bureaucrats try to sign the form   |\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m===============================================\e[00m" << std::endl;
	try
	{
		std::cout << "\e[32mMilton signing\e[00m" << std::endl;
		milton.signForm(more);
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\e[32mThe form should remain unsigned:\n\e[00m" << more << std::endl;
	try
	{
		std::cout << "\e[32mBob signing\e[00m" << std::endl;
		bob.signForm(more);
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\e[32mThe form is now like this:\e[00m" << std::endl;
	std::cout << more << std::endl;
	return (0);
}
