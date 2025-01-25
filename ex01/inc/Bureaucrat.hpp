/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:45:14 by sasano            #+#    #+#             */
/*   Updated: 2025/01/26 03:45:16 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &form) const;
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const _NOEXCEPT;
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const _NOEXCEPT;
        };
};

#endif