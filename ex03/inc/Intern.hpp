/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 05:38:03 by sasano            #+#    #+#             */
/*   Updated: 2025/01/26 05:44:51 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    private:

    public:
        Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &copy);
        ~Intern();

        AForm *makeForm(std::string formName, std::string target);
};

#endif