/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:23:08 by skiam             #+#    #+#             */
/*   Updated: 2025/01/06 21:17:10 by skiam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN		rpn;
	
	try 
	{
		char	*input;
		std::stack<int, std::list<double> >	stack;

		if (argc != 2)
			return (std::cerr << "Error: Wrong number of arguments" << std::endl, 1);
		input = strtok(argv[1], " ");

		while (input != NULL)
		{
			if (rpn.check_input(input, stack))
				return (1);
			input = strtok(NULL, " ");
		}
		if (stack.size() != 1)
			return (std::cerr << "Error: stack size is not 1" << std::endl, 1);
		std::cout << stack.top() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
