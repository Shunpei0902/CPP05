/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <sasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 04:47:00 by sasano            #+#    #+#             */
/*   Updated: 2025/10/30 16:42:33 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm default constructor called for " << this->getName() << " with grade to sign of " << this->getGradeToSign() << " and grade to execute of " << this->getGradeToExecute() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called for " << this->getName() << " with grade to sign of " << this->getGradeToSign() << " and grade to execute of " << this->getGradeToExecute() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
    std::cout << "RobotomyRequestForm copy constructor called for " << this->getName() << std::endl;
    *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    this->_target = copy._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor for " << this->getName() << " called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (this->getSigned() == false)
        throw AForm::AFormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << "*drilling noises*" << std::endl;
    std::srand(time(NULL));
    if (rand() % 2)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->_target << " has failed to be robotomized" << std::endl;

    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    }

