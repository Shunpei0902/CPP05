/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <sasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 05:32:57 by sasano            #+#    #+#             */
/*   Updated: 2025/10/30 17:01:53 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void test_intern_make_form() {
    Intern intern;
    Bureaucrat bureaucrat("InternBureaucrat", 1);

    AForm *form = intern.makeForm("RobotomyRequestForm", "InternTarget");
    AForm *form2 = intern.makeForm("ShrubberyCreationForm", "InternTarget");
    AForm *form3 = intern.makeForm("PresidentialPardonForm", "InternTarget");
    // assert(form != NULL);
    bureaucrat.signForm(*form);
    bureaucrat.signForm(*form2);
    // assert(form->isSigned());
    bureaucrat.executeForm(*form);
    bureaucrat.executeForm(*form2);
    bureaucrat.executeForm(*form3);
    delete form;
}

void test_invalid_form_name() {
    Intern intern;
    try {
        AForm *form = intern.makeForm("InvalidFormName", "target");
        assert(form == NULL);
    } catch (const std::exception &e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
}

int main() {
    try {
        test_intern_make_form();
        test_invalid_form_name();
        std::cout << "All tests passed!" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}