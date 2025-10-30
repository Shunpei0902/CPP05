/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <sasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:07:29 by sasano            #+#    #+#             */
/*   Updated: 2025/10/30 14:30:35 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

static void test_creation()
{
    std::cout << "== test_creation ==" << std::endl;
    Bureaucrat b1("Bureaucrat1", 1);
    Bureaucrat b2("Bureaucrat2", 150);
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
}

static void test_increment_decrement()
{
    std::cout << "== test_increment_decrement ==" << std::endl;
    Bureaucrat b("Tester", 2);
    std::cout << b << std::endl;

    std::cout << "incrementing..." << std::endl;
    b.incrementGrade();
    std::cout << b << std::endl;
    try
    {
        std::cout << "incrementing past top..." << std::endl;
        b.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << "caught: " << e.what() << std::endl;
    }
    
    Bureaucrat low("Low", 149);
    std::cout << low << std::endl;
    std::cout << "decrementing..." << std::endl;
    low.decrementGrade();
    std::cout << low << std::endl;
    try
    {
        std::cout << "decrementing past bottom..." << std::endl;
        low.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << "caught: " << e.what() << std::endl;
    }
}

static void test_invalid_creation()
{
    std::cout << "== test_invalid_creation ==" << std::endl;
    try
    {
        Bureaucrat badHigh("BadHigh", 0);
    }
    catch (const std::exception &e)
    {
        std::cout << "caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat badLow("BadLow", 151);
    }
    catch (const std::exception &e)
    {
        std::cout << "caught: " << e.what() << std::endl;
    }
}

static void test_copy_assign()
{
    std::cout << "== test_copy_assign ==" << std::endl;
    Bureaucrat a("A", 42);
    Bureaucrat b = a; // copy
    std::cout << "copy: " << b << std::endl;

    Bureaucrat c("C", 5);
    c = a; // assign
    std::cout << "assign: " << c << std::endl;
}

int main()
{
    try
    {
        test_creation();
        test_increment_decrement();
        test_invalid_creation();
        test_copy_assign();
    }
    catch (std::exception &e)
    {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }
    return (0);
}