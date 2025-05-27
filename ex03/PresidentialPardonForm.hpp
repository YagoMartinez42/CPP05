/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-10 18:34:34 by samartin          #+#    #+#             */
/*   Updated: 2025-05-10 18:34:34 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP
# include "AForm.hpp"

class  PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string targetP);
		PresidentialPardonForm(const PresidentialPardonForm& orig);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& orig);
		void execute(Bureaucrat const &executor) const;
	private:
		std::string const _target;
};

#endif