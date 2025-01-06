/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:11:27 by skiam             #+#    #+#             */
/*   Updated: 2025/01/06 18:09:30 by skiam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstring>
#include <cstdlib>
#include <limits.h>
#include <cerrno>
#include <list>
#include <iostream>
#include <stack>

class	RPN {
	
	public:

        RPN();
		~RPN();
		RPN(const RPN& src);
		RPN& operator=(const RPN& rhs);
        
        double	do_op(double first, double second, char op);
        int 	check_input(char *s, std::stack<int, std::list<double> > &stack);
        
};