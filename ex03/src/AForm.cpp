/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <sasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:52:48 by sasano            #+#    #+#             */
/*   Updated: 2025/10/30 16:34:43 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("defualt"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "AForm default constructor called for " << this->getName() << " with grade to sign of " << this->getGradeToSign() << " and grade to execute of " << this->getGradeToExecute() << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "AForm constructor called for " << this->getName() << " with grade to sign of " << this->getGradeToSign() << " and grade to execute of " << this->getGradeToExecute() << std::endl;
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "AForm copy constructor called for " << this->getName() << std::endl;
    *this = copy;
}

AForm &AForm::operator=(const AForm &copy)
{
    std::cout << "Form assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    this->_signed = copy._signed;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm destructor for " << this->getName() << " called" << std::endl;
}

std::string AForm::getName() const
{
    return (this->_name);
}

bool AForm::getSigned() const
{
    return (this->_signed);
}

int AForm::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw Bureaucrat::GradeTooLowException();
    else if (this->getSigned())
        throw AForm::AFormAlreadySignedException();
    else
    {
        this->_signed = true;
        std::cout << this->getName() << " was signed by " << bureaucrat.getName() << std::endl;
    }
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char *AForm::AFormAlreadySignedException::what() const throw()
{
    return ("Form is already signed");
}

const char *AForm::AFormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}

const char *AForm::FileNotOpenException::what() const throw()
{
    return ("File couldn't be opened");
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
    out << "AForm " << form.getName() << " is ";
    if (form.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " with grade to sign of " << form.getGradeToSign() << " and grade to execute of " << form.getGradeToExecute();
    return (out);
}