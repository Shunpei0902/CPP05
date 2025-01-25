/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:07:29 by sasano            #+#    #+#             */
/*   Updated: 2025/01/26 03:48:19 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 1);
        Form form("Form", 1, 1);
        form.beSigned(bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}