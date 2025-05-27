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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat burTop = Bureaucrat("Sánchez", 3);
	Bureaucrat minion = Bureaucrat("López", 140);

	std::cout << std::endl;
	std::cout << "\e[33m\e[44m==================================\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m|    Two bureaucrats are here    |\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m==================================\e[00m" << std::endl;
	std::cout << burTop << std::endl;
	std::cout << minion << std::endl;

	std::cout << std::endl;
	std::cout << "\e[33m\e[44m============================================\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m|    Three different forms on the table    |\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m============================================\e[00m" << std::endl;
	std::cout << "\e[32mInstancing a form to create a shrubbery in my house.\e[00m" << std::endl;
    ShrubberyCreationForm form1("My_house");
    std::cout << form1 << std::endl;
    std::cout << "\e[32mInstancing a form to practice a robotomy on Bender Bending Rodríguez.\e[00m" << std::endl;
    RobotomyRequestForm form2("Bender Bending Rodríguez");
    std::cout << form2 << std::endl;
   	std::cout << "\e[32mInstancing a form to forgive Marvin of his crimes.\e[00m" << std::endl;
    PresidentialPardonForm form3("Marvin");
    std::cout << form3 << std::endl;
	std::cout << std::endl;
    std::cout << "\e[33m\e[44m============================================\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m| López is going to try and sign all forms |\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m============================================\e[00m" << std::endl;
    std::cout << "\e[32mSigning form 1.\e[00m" << std::endl;
    try
	{
        minion.signForm(form1);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << "\e[32mSigning form 2.\e[00m" << std::endl;
    try
	{
        minion.signForm(form2);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << "\e[32mSigning form 3.\e[00m" << std::endl;
    try
	{
        minion.signForm(form3);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
    std::cout << "\e[33m\e[44m==============================================================\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m| He can even try to execute the one that is actually signed |\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m==============================================================\e[00m" << std::endl;
    std::cout << "\e[32mExecuting form 1.\e[00m" << std::endl;
    try
	{
        form1.execute(minion);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
    std::cout << "\e[33m\e[44m============================================\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m| Now Sánchez has to do everything himself |\e[00m" << std::endl;
	std::cout << "\e[33m\e[44m============================================\e[00m" << std::endl;
	std::cout << "\e[32mAre these things signed?.\e[00m" << std::endl;
    std::cout << "\e[32mExecuting form 1.\e[00m" << std::endl;
    try
	{
        form1.execute(burTop);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\e[32mExecuting form 2.\e[00m" << std::endl;
    try
	{
        form2.execute(burTop);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\e[32mOh, not all are.\e[00m" << std::endl;
    std::cout << "\e[32mSigning form 2.\e[00m" << std::endl;
	try
	{
        burTop.signForm(form2);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\e[32mSigning form 3.\e[00m" << std::endl;
	try
	{
        burTop.signForm(form3);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\e[32mSo, here we go again.\e[00m" << std::endl;
	std::cout << "\e[32mExecuting form 2.\e[00m" << std::endl;
    try
	{
        form2.execute(burTop);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\e[32mExecuting form 3.\e[00m" << std::endl;
    try
	{
        form3.execute(burTop);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return(0);
}
