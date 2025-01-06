/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:11:22 by skiam             #+#    #+#             */
/*   Updated: 2025/01/06 21:02:00 by skiam            ###   ########.fr       */
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

// double	RPN::do_op(double first, double second, char sign)
// {
// 	if (sign == '+')
// 		return (first + second);
// 	if (sign == '-')
// 			return (second - first);
// 	if (sign == '*')
// 			return (first * second);
// 	if (sign == '/')
// 	{
// 		if (first == 0)
// 			throw std::invalid_argument("Error: division by 0");
// 		return (second / first);
// 	}
// 	return (0);
// }

// int	RPN::check_input(char *s, std::list<double> &lst)
// {
// 	std::string	str;
// 	size_t	size;
// 	char	*endptr;
// 	long	nb;
// 	double	res;
// 	double	first;
// 	double	second;
	

// 	str = s;
// 	size = str.length();
// 	if ((str[0] == '+' || str[0] == '-' || str[0] == '/' || str[0] == '*') && size == 1)
// 	{
// 		if (lst.size() < 2)
// 			{std::cerr << "Error: not enough number in the list to do the operation" << std::endl; return (1);}
// 		first = lst.back();
// 		lst.pop_back();
// 		second = lst.back();
// 		lst.pop_back();
// 		res  = do_op(first, second, str[0]);
// 		lst.push_back(res);
// 		return (0);
// 	}
// 	nb = strtol(str.c_str(), &endptr, 10);
// 	if (endptr == str.c_str() || *endptr != '\0')
// 		return (1);
// 	if (nb < INT_MIN || nb > 9)
// 		{std::cerr << "Error: the numbers used as arguments must be less than 10" << std::endl; return (1);}
// 	lst.push_back(nb);
// 	return (0);
// }

double	RPN::do_op(double first, double second, char sign)
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

int	RPN::check_input(char *s, std::stack<int, std::list<double> > &stack)
{
	std::string	str;
	size_t	size;
	char	*endptr;
	long	nb;
	double	res;
	double	first;
	double	second;
	

	str = s;
	size = str.length();
	if ((str[0] == '+' || str[0] == '-' || str[0] == '/' || str[0] == '*') && size == 1)
	{
		if (stack.size() < 2)
			{std::cerr << "Error: not enough number in the list to do the operation" << std::endl; return (1);}
		first = stack.top();
		stack.pop();
		second = stack.top();
		stack.pop();
		res  = do_op(first, second, str[0]);
		stack.push(res);
		return (0);
	}
	nb = strtol(str.c_str(), &endptr, 10);
	if (endptr == str.c_str() || *endptr != '\0')
		{std::cerr << "Error: wrong input" << std::endl; return (1);}
	if (nb < INT_MIN || nb > 9)
		{std::cerr << "Error: the numbers used as arguments must be less than 10" << std::endl; return (1);}
	stack.push(nb);
	return (0);
}