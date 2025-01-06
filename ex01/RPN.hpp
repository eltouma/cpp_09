/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:11:27 by skiam             #+#    #+#             */
/*   Updated: 2025/01/06 01:11:29 by skiam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstring>
#include <cstdlib>
#include <limits.h>
#include <cerrno>
#include <list>
#include <iostream>

class	RPN {
	
	private:
    
		RPN(const RPN& src);
		RPN& operator=(const RPN& rhs);
		
	public:

        RPN();
		~RPN();
        
        double	doOp(double first, double second, char op);
        int 	checkInput(char *s, std::list<double> &lst);
        
};