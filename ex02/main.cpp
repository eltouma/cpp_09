/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:03:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/09 15:15:03 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <limits.h>
#include <cerrno>
#include <vector>


int	checkInput(char *s, std::vector<int> &vect)
{
	std::string	str;
	size_t	size;
	long	nb;
	char	*endptr;

	str = s;
	size = str.length();
	errno = 0;
	nb = strtol(str.c_str(), &endptr, 10);
	if (endptr == str.c_str() || *endptr != '\0')
		return (1);
	if (errno == ERANGE || nb < 0 || nb > INT_MAX)
		return (1);
	vect.push_back(nb);
	return (0);
}

int	main(int argc, char **argv)
{
	try {
		char	*input;
		std::vector<int>	vect;
//		std::vector<int>	main;
//		std::vector<int>	pending;
		std::vector<int>::iterator	it;

		int	last;

		if (argc != 2)
			return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
		input = strtok(argv[1], " ");
		size_t i = 0;
		while (input != NULL)
		{
			if (checkInput(input, vect))
				return (std::cerr << "Error" << std::endl, 1);
			std::cout << "element: " << vect[i] << std::endl;
			i += 1;
			input = strtok(NULL, " ");
		}
		if (vect.size() & 1)
		{
			std::cout << "last = " << vect.back()<< "\n";
			std::cout << "vect.size() vaut " << vect.size() << " c'est impair\n";
			last = vect.back();
			vect.pop_back();
			std::cout << "now last = " << vect.back() << "\n";
		}
		else
			std::cout << "vect.size() vaut " << vect.size() << " c'est pair\n";
/*
		for (size_t i = 0; i != vect.size(); i += 2)
		{
			if (vect[i] < vect[i + 1]) 
			{
				std::swap(vect[i], vect[i + 1]);
		//		pending.push_back(*it + 1);
			}

		}
*/
		std::cout << "\nVect vector\n";
		for (it = vect.begin(); it != vect.end(); it++)
			std::cout << *it << " ";
//		std::cout << "\n\nPending vector\n";
//		for (it = pending.begin(); it != pending.end(); it++)
//			std::cout << *it << " ";
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
