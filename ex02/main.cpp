/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:12:03 by skiam             #+#    #+#             */
/*   Updated: 2025/01/06 23:21:38 by skiam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"


int	main(int argc, char **argv)
{
	char	*input;
	char	*buff;
	std::vector<int>	vect;
	std::vector<int>	pending_vect;
	// std::deque<int>		deque;
	// std::deque<int>		pending_deque;
	std::vector<int>::iterator	it;

	input = NULL;
	buff = NULL;
	if (argc < 2)
		{std::cerr << "Error: Wrong amount of arguments" << std::endl; return (1);}
	input = isString(argc, argv, input, buff);
	std::cout << "input = ";
	while (input != NULL)
	{
		std::cout << input << " ";
		if (check_input(input, vect))
		{
			if (buff)
				delete [] buff;
			std::cerr << "Error: Input is incorrect" << std::endl;
			return (1);
		}
		input = strtok(NULL, " ");
	}
	if (vect.size() == 1)
		return (std::cerr << "Error: Wrong amount of arguments" << std::endl, 1);
	if (handle_dup(vect, it, buff))
		return (std::cerr << "Error: duplicate numbers" << std::endl, 1);
	clock_t start = clock();
	merge_insert(vect, 1);
	clock_t end = clock();
	double time_to_sort_vect = (double(end - start) / CLOCKS_PER_SEC);
	std::cout << "\nAfter sorting:\n";
	for (it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nTime to process a range of " << vect.size() << " elements with std::vect : "
		<< time_to_sort_vect << "s" << std::endl; 
	if (buff)
		delete [] buff;
}
