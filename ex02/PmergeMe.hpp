/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:07:57 by skiam             #+#    #+#             */
/*   Updated: 2025/01/06 23:16:44 by skiam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <limits.h>
#include <cerrno>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>
#include <ctime>

void	init_pending(std::vector<int> &vect, int sizeElement, std::vector<std::pair<std::vector<int>, int> > &pending);
std::vector<int>::iterator	binarySearch(std::vector<int>::iterator start, std::vector<int>::iterator end, int sizeElement, int valToFind);
void	sort_pairs(std::vector<int> &vect, int sizeElement);
void	merge_insert(std::vector<int> &vect, int sizeElement);
int	    check_input(char *s, std::vector<int> &vect);
int	    ft_strlen(char *str);
char    *isString(int argc, char **argv, char *input, char *&buff);
int	    handle_dup(std::vector<int> vect, std::vector<int>::iterator it, char *buff);
void	printVect(std::vector<int> vect);
void	printGroup(std::vector<int> vect, int sizeElement, int nbOfGroups);
void	printPending(std::vector<std::pair<std::vector<int>, int> > pending);
void	printOdd(std::vector<int> vect, int sizeElement);
void    draw_tab(const std::string& str);
