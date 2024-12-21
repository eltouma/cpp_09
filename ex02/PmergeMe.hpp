/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:08:34 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/21 01:05:03 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <limits.h>
#include <cerrno>
#include <vector>
#include <cmath>
#include <algorithm>

int	checkInput(char *s, std::vector<int> &vect);
int	ft_strlen(char *str);
char    *isString(int argc, char **argv, char *input, char *&buff);
int	handleDuplicate(std::vector<int> vect, std::vector<int>::iterator it, char *buff);
void	printVect(std::vector<int> vect);
