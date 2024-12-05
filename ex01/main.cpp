/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:03:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/05 19:14:52 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstring>

int	checkParams(char *s)
{
	std::string	str;
	size_t	size;
	int	zero;

	str = s;
	size = str.length();
	zero = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (!isdigit(str[i]))
		{
			if (str[i] == '-' && isdigit(str[i + 1]) && size > 1)
			{
				for (size_t j = i + 1; j < size; j++)
				{
					if (!isdigit(str[j]))
						return (1);
				}
				return (0);
			}
			if (!(str[i] == '+' && str[i] == '-' && str[i] == '\\' && str[i] == '*') && size > 1)
				return (1);
		}
		if (isdigit(str[i]) && size > 1)
		{
			for (;str[i] == '0'; i++)
				zero = 1;
			if (zero && str[i - 1] != '0')
				return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error\nWrong number of arguments" << std::endl;
		return (1);
	}
	char	*input;
	input = strtok(argv[1], " ");	
	while (input != NULL)
	{
		std::cout << input << "\n";
		if (checkParams(input))
		{
			std::cerr << "Reponse du code: non\n";
			return (1);
		}
		input = strtok(NULL, " ");	
	}
}
