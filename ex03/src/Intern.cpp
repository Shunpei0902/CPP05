/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 05:40:48 by sasano            #+#    #+#             */
/*   Updated: 2025/01/26 05:44:04 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    std::cout << "Intern assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

static AForm *createRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *createShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm *createPresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    AForm *(*formCreators[3])(std::string) = {createRobotomyRequestForm, createShrubberyCreationForm, createPresidentialPardonForm};
    std::string formNames[3] = {"RobotomyRequestForm", "ShrubberyCreationForm", "PresidentialPardonForm"};

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (formCreators[i](target));
        }
    }
    std::cout << "Intern cannot create " << formName << std::endl;
    return (NULL);
}