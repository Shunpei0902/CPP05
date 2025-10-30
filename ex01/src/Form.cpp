/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <sasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:52:48 by sasano            #+#    #+#             */
/*   Updated: 2025/10/30 14:36:23 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("defualt"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form default constructor called for " << this->getName() << " with grade to sign of " << this->getGradeToSign() << " and grade to execute of " << this->getGradeToExecute() << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form constructor called for " << this->getName() << " with grade to sign of " << this->getGradeToSign() << " and grade to execute of " << this->getGradeToExecute() << std::endl;
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "Form copy constructor called for " << this->getName() << std::endl;
    *this = copy;
}

Form &Form::operator=(const Form &copy)
{
    std::cout << "Form assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    this->_signed = copy._signed;
    return (*this);
}

Form::~Form()
{
    std::cout << "Form destructor for " << this->getName() << " called" << std::endl;
}

std::string Form::getName() const
{
    return (this->_name);
}

bool Form::getSigned() const
{
    return (this->_signed);
}

int Form::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw Bureaucrat::GradeTooLowException();
    else if (this->getSigned())
        throw Form::FormAlreadySignedException();
    else
    {
        this->_signed = true;
        std::cout << this->getName() << " was signed by " << bureaucrat.getName() << std::endl;
    }
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char *Form::FormAlreadySignedException::what() const throw()
{
    return ("Form is already signed");
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << "Form " << form.getName() << " is ";
    if (form.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " with grade to sign of " << form.getGradeToSign() << " and grade to execute of " << form.getGradeToExecute();
    return (out);
}