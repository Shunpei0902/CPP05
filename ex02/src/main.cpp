/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 05:32:57 by sasano            #+#    #+#             */
/*   Updated: 2025/01/26 05:33:22 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 1);
        RobotomyRequestForm robotomyRequestForm("RobotomyRequestForm");
        ShrubberyCreationForm shrubberyCreationForm("ShrubberyCreationForm");
        PresidentialPardonForm presidentialPardonForm("PresidentialPardonForm");

        bureaucrat.executeForm(robotomyRequestForm);
        bureaucrat.executeForm(shrubberyCreationForm);
        bureaucrat.executeForm(presidentialPardonForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}