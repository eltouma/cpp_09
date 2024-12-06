/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:03:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/06 11:40:58 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <limits.h>
#include <cerrno>
#include <stack>
#include <list>

double	doOp(double first, double second, char op)
{
	switch (op)
	{
		case '+':
			return (first + second);
		case '-':
			return (second - first);
		case '*':
			return (first * second);
		case '/':
			if (first == 0)
				throw std::invalid_argument("ZeroDivisionError (divided by 0)");
			return (second / first);
	}
	return (0);
}

int	checkParams(char *s, std::stack<double, std::list<double> > &stck)
{
	std::string	str;
	size_t	size;
	long	nb;
	double	result;
	double	first;
	double	second;
	char	*endptr;

	str = s;
	size = str.length();
	if ((str[0] == '+' || str[0] == '-' || str[0] == '/' || str[0] == '*') && size == 1)
	{
		if (stck.size() < 2)
			return (1);
		first = stck.top();
		stck.pop();
		second = stck.top();
		stck.pop();
		result  = doOp(first, second, str[0]);
		stck.push(result);
		return (0);
	}
	errno = 0;
	nb = strtol(str.c_str(), &endptr, 10);
	if (endptr == str.c_str() || *endptr != '\0')
		return (1);
	if (errno == ERANGE || nb < INT_MIN || nb > 10)
		return (1);
	stck.push(nb);
	return (0);
}

int	main(int argc, char **argv)
{
	try {
		char	*input;
		std::stack<double, std::list<double> >	stck;

		if (argc != 2)
			return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
		input = strtok(argv[1], " ");
		while (input != NULL)
		{
			if (checkParams(input, stck))
				return (std::cerr << "Error" << std::endl, 1);
			input = strtok(NULL, " ");
		}
		if (stck.size() != 1)
			return (std::cerr << "Error: stack size is greater than 1 at the end" << std::endl, 1);
		std::cout << stck.top() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
