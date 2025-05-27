/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-27 09:59:01 by samartin          #+#    #+#             */
/*   Updated: 2025-05-27 09:59:01 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# ifndef FORM1
#  define FORM1 "Shrubbery Creation Form"
# endif
# ifndef FORM2
#  define FORM2 "Robotomy Request Form"
# endif
# ifndef FORM3
#  define FORM3 "Presidential Pardon Form"
# endif

class Intern
{
	public:
		Intern();
		Intern(const Intern& orig);
		~Intern();
		Intern& operator=(const Intern& orig);
		AForm* makeForm(const std::string& name, const std::string& target) const;
		class InvalidFormName : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif