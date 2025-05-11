/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:37:43 by samartin          #+#    #+#             */
/*   Updated: 2025/03/27 21:23:29 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string nameP, int grade2SignP, int grade2ExeP);
		Form(const Form& orig);
		~Form();
		Form& operator=(const Form& orig);
		std::string const & getName() const;
		int getGrade2Sign() const;
		int getGrade2Exe() const;
		bool getSigned() const;
		void beSigned(Bureaucrat *bur);
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	private:
		std::string const _name;
		const int _grade2Sign;
		const int _grade2Exe;
		bool _signed;
};

std::ostream& operator<<(std::ostream& stm, const Form& frm);

#endif
