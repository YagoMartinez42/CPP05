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

int main()
{
    Bureaucrat presi("Perro X", 1);
    ShrubberyCreationForm aform("My_house");
    aform.beSigned(&presi);
    aform.execute(presi);
    return(0);
}
