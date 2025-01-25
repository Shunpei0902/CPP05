/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 04:30:25 by sasano            #+#    #+#             */
/*   Updated: 2025/01/26 05:12:16 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const &executor) const;
};

#endif