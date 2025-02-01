/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:27:43 by samartin          #+#    #+#             */
/*   Updated: 2025/02/01 18:19:35 by samartin         ###   ########.fr       */
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
		std::string const & getName() const;
		int getGrade() const;
		void raiseGrade();
		void dropGrade();
	private:
		std::string const _name;
		int _grade;
};

#endif
