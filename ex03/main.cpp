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
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    Bureaucrat burTop = Bureaucrat("Sánchez", 3);
	Bureaucrat minion = Bureaucrat("López", 140);
	Intern ese = Intern();
	AForm* form1;
	AForm* form2;
	AForm* form3;
	AForm* form4;

	std::cout << std::endl;
	std::cout << "\e[33m\e[44m==================================\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m|    Two bureaucrats are here    |\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m==================================\e[00m" << std::endl;
	std::cout << burTop << std::endl;
	std::cout << minion << std::endl;

	std::cout << std::endl;
	std::cout << "\e[33m\e[44m============================================\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m| Let's ask the intern to fill some forms  |\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m============================================\e[00m" << std::endl;
	try
	{
		std::cout << "\e[32mInstancing a form to create a shrubbery in my house.\e[00m" << std::endl;
		form1 = ese.makeForm("Shrubbery Creation Form", "My_house");
		std::cout << *form1 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\e[32mInstancing a form to practice a robotomy on Bender Bending Rodríguez.\e[00m" << std::endl;
		form2 = ese.makeForm("Robotomy Request Form", "Bender Bending Rodríguez");
		std::cout << *form2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\e[32mInstancing a form to forgive Marvin of his crimes.\e[00m" << std::endl;
		form3 = ese.makeForm("Presidential Pardon Form", "Marvin");
		std::cout << *form3 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\e[32mInstancing a form to request a raise\e[00m" << std::endl;
		form4 = ese.makeForm("Salary raise petition", "Me");
		std::cout << *form4 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
    std::cout << "\e[33m\e[44m==========================================\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m|  Sánchez is taking care of everything  |\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m==========================================\e[00m" << std::endl;
    std::cout << "\e[32mSigning form 1.\e[00m" << std::endl;
    try
	{
        burTop.signForm(*form1);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << "\e[32mSigning form 2.\e[00m" << std::endl;
    try
	{
        burTop.signForm(*form2);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << "\e[32mSigning form 3.\e[00m" << std::endl;
    try
	{
        burTop.signForm(*form3);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << "\e[32mExecuting form 1.\e[00m" << std::endl;
    try
	{
        form1->execute(burTop);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << "\e[32mExecuting form 2.\e[00m" << std::endl;
    try
	{
        form2->execute(burTop);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << "\e[32mExecuting form 3.\e[00m" << std::endl;
    try
	{
        form3->execute(burTop);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete(form1), delete(form2), delete(form3);
	return(0);
}
