/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <sasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:07:29 by sasano            #+#    #+#             */
/*   Updated: 2025/10/30 16:19:44 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // Test: Bureaucrat with valid grade signs a form
    try
    {
        Bureaucrat bureaucrat("Alice", 1);
        Form form("TopSecret", 1, 1);
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Test 1 failed: " << e.what() << std::endl;
    }

    // Test: Bureaucrat with too low grade tries to sign
    try
    {
        Bureaucrat lowRank("Bob", 150);
        Form form("Classified", 1, 1);
        lowRank.signForm(form);
    }
    catch (std::exception &e)
    {
        std::cerr << "Test 2 passed: " << e.what() << std::endl;
    }

    // Test: Form with invalid grade
    try
    {
        Form invalidForm("Invalid", 1, 151);
    }
    catch (std::exception &e)
    {
        std::cerr << "Test 3 passed: " << e.what() << std::endl;
    }

    // Test: Bureaucrat with invalid grade
    try
    {
        Bureaucrat invalidBureaucrat("Charlie", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << "Test 4 passed: " << e.what() << std::endl;
    }

    return 0;
}