/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 04:30:48 by sasano            #+#    #+#             */
/*   Updated: 2025/01/26 04:57:57 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm default constructor called for " << this->getName() << " with grade to sign of " << this->getGradeToSign() << " and grade to execute of " << this->getGradeToExecute() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called for " << this->getName() << " with grade to sign of " << this->getGradeToSign() << " and grade to execute of " << this->getGradeToExecute() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
    std::cout << "ShrubberyCreationForm copy constructor called for " << this->getName() << std::endl;
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    this->_target = copy._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor for " << this->getName() << " called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::ofstream file(this->_target + "_shrubbery");
    if (!file.is_open())
        throw AForm::FileNotOpenException();
    file << "      *           *           *           *" << std::endl;
	file << "     ***         ***         ***         ***" << std::endl;
	file << "    *****       *****       *****       *****" << std::endl;
	file << "   *******     *******     *******     *******" << std::endl;
	file << "  *********   *********   *********   *********" << std::endl;
	file << " *********** *********** *********** ***********" << std::endl;
	file << "    |            |            |            |" << std::endl;

    // std::ofstream のスコープを抜けると自動的に閉じられる
    // file.close();
}