/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:07:29 by sasano            #+#    #+#             */
/*   Updated: 2025/01/26 02:07:35 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Bureaucrat1", 1);
        Bureaucrat b2("Bureaucrat2", 150);
        Bureaucrat b3("Bureaucrat3", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}