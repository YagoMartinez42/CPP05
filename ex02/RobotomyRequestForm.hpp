/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-10 18:28:26 by samartin          #+#    #+#             */
/*   Updated: 2025-05-10 18:28:26 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class  RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string targetP);
		RobotomyRequestForm(const RobotomyRequestForm& orig);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& orig);
		void execute(Bureaucrat const &executor);
	private:
		std::string const _target;
};

#endif