/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:27:43 by samartin          #+#    #+#             */
/*   Updated: 2025/02/23 17:08:47 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string nameP, int grade);
		Bureaucrat(const Bureaucrat& orig);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& orig);
		const std::string &getName() const;
		const int &getGrade() const;
		void raiseGrade();
		void dropGrade();
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
		int _grade;
};

std::ostream& operator<<(std::ostream& stm, const Bureaucrat& bur);

#endif
