/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:11:22 by skiam             #+#    #+#             */
/*   Updated: 2025/01/06 01:11:24 by skiam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& src) {
	*this = src;
}

RPN& RPN::operator=(const RPN& rhs) {
    (void)rhs;
	return *this;
}

double	RPN::doOp(double first, double second, char sign)
{
	if (sign == '+')
		return (first + second);
	if (sign == '-')
			return (second - first);
	if (sign == '*')
			return (first * second);
	if (sign == '/')
	{
		if (first == 0)
			throw std::invalid_argument("Error: division by 0");
		return (second / first);
	}
	return (0);
}

int	RPN::checkInput(char *s, std::list<double> &lst)
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
		if (lst.size() < 2)
			return (1);
		first = lst.back();
		lst.pop_back();
		second = lst.back();
		lst.pop_back();
		result  = doOp(first, second, str[0]);
		lst.push_back(result);
		return (0);
	}
	nb = strtol(str.c_str(), &endptr, 10);
	if (endptr == str.c_str() || *endptr != '\0')
		return (1);
	if (nb < INT_MIN || nb > 9)
		return (1);
	lst.push_back(nb);
	return (0);
}