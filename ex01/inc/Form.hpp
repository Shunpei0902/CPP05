/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:52:56 by sasano            #+#    #+#             */
/*   Updated: 2025/01/26 03:47:42 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;

    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExcetute);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        ~Form();

        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);
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
        class FormAlreadySignedException : public std::exception
        {
            public:
                const char *what() const _NOEXCEPT;
        };
        
};

#endif
