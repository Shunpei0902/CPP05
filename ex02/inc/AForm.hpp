/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:52:56 by sasano            #+#    #+#             */
/*   Updated: 2025/01/26 05:30:47 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;

    public:
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExcetute);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        virtual ~AForm();

        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        virtual void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;
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
        class AFormAlreadySignedException : public std::exception
        {
            public:
                const char *what() const _NOEXCEPT;
        };
        class FileNotOpenException : public std::exception
        {
            public:
                const char *what() const _NOEXCEPT;
        };
        
};

#endif
