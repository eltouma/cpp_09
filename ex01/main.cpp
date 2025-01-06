/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:23:08 by skiam             #+#    #+#             */
/*   Updated: 2025/01/06 00:58:52 by skiam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN		rpn;
	
	try 
	{
		char	*input;
		std::list<double>	lst;

		if (argc != 2)
			return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
		input = strtok(argv[1], " ");
		while (input != NULL)
		{
			if (rpn.checkInput(input, lst))
				return (std::cerr << "Error" << std::endl, 1);
			input = strtok(NULL, " ");
		}
		if (lst.size() != 1)
			return (std::cerr << "Error: stack size is not 1" << std::endl, 1);
		std::cout << lst.back() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
