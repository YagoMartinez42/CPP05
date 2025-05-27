/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:37:43 by samartin          #+#    #+#             */
/*   Updated: 2025/03/27 21:23:29 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>

class Bureaucrat;

class AForm
{
	public:
		virtual ~AForm();
		AForm& operator=(const AForm& orig);
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
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		virtual void execute(Bureaucrat const &executor) const = 0;
	protected:
		AForm();
		AForm(std::string nameP, int grade2SignP, int grade2ExeP);
		AForm(const AForm& orig);
	private:
		std::string const _name;
		bool _signed;
		const int _grade2Sign;
		const int _grade2Exe;
};

std::ostream& operator<<(std::ostream& stm, const AForm& frm);

#endif
