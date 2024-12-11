/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:03:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/11 01:15:28 by skiam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <limits.h>
#include <cerrno>
#include <vector>
#include <cmath>


int	checkInput(char *s, std::vector<int> &vect)
{
	std::string	str;
	long	nb;
	char	*endptr;

	str = s;
	errno = 0;
	nb = strtol(str.c_str(), &endptr, 10);
	if (endptr == str.c_str() || *endptr != '\0')
		return (1);
	if (errno == ERANGE || nb < 0 || nb > INT_MAX)
		return (1);
	vect.push_back(nb);
	return (0);
}

void	sortPairs(std::vector<int> &vect)
{
	for (unsigned long i = 2; i < vect.size(); i *= 2)
	{
		unsigned long k = i;
		for (unsigned long j = (i / 2); k <= vect.size(); j += i)
		{
			if (vect[j - 1] > vect[k - 1])
			{
				std::cout << "boucle swap\n";
				unsigned long l = 0;
				while (l < (k - j))
				{
					std::swap(vect[j - l - 1], vect[k - l - 1]);
					l++;
				}
			}
			k += i;
		}
		//std::cout << "\nIteration of sorting pairs:\n";
		// for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		// 	std::cout << *it << " ";
	}
}
std::vector<int> generateJacobsthal(int n) 
{
    std::vector<int> jacobsthal;

    // Handle the base cases
    if (n >= 1) jacobsthal.push_back(0); // J(0) = 0
    if (n >= 2) jacobsthal.push_back(1); // J(1) = 1

    // Generate the sequence up to J(n-1)
    for (int i = 2; i < n; ++i) {
        int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

std::vector<int>	mergeInsert(std::vector<int> &main)
{
		unsigned long		total_size = main.size();
		std::vector<int>	pending;
		std::vector<int>	jacob = generateJacobsthal(total_size / 2);

		int power = static_cast<int>(std::log(main.size()) / std::log(2));
		power -= 2;
		std::cout << "\n\nPower before loop = " << power << std::endl;
		while (power >= 0)
		{
			unsigned long groupSize = std::pow(2, power);
			std::cout << "\nGroup size = " << groupSize << std::endl;
			//unsigned long groupsNb 	= total_size / groupSize;
			
			for (unsigned long iteration = groupSize * 2; iteration < main.size(); iteration += (groupSize * 2))
			{
				if (iteration + groupSize <= main.size())
				{
					pending.insert(pending.end(), main.begin() + iteration, main.begin() + (iteration + groupSize));
					main.erase(main.begin() + iteration, main.begin() + (iteration + groupSize));
					iteration -= groupSize;
				}
			}
			std::cout << "\n\nMain chain:\n";
			for (std::vector<int>::iterator itM = main.begin(); itM != main.end(); itM++)
		 		std::cout << *itM << " ";
			std::cout << "\n\nPending chain:\n";
			for (std::vector<int>::iterator itP = pending.begin(); itP != pending.end(); itP++)
		 		std::cout << *itP << " ";
			// if (pend.size() > groupSize)
			// {
				
			// }
			power--;
		}
		return main;
}

int	main(int argc, char **argv)
{
	try {
		char	*input;
		std::vector<int>	vect;
		std::vector<int>	main;
		std::vector<int>	pending;
		std::vector<int>::iterator	it;
		int	last;
		// int	pendingVect;
		// int	mainVect;

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
			std::cout << "last = " << vect.back() << "\n";
			std::cout << "vect.size() vaut " << vect.size() << " c'est impair\n";
			last = vect.back();
			vect.pop_back();
			std::cout << "now last = " << last << "\n";
		}
		else
			std::cout << "vect.size() vaut " << vect.size() << " c'est pair\n";

		// for (size_t i = 0; i != vect.size(); i += 2)
		// {
		// 	if (vect[i] < vect[i + 1]) 
		// 		std::swap(vect[i], vect[i + 1]);

		// }
		sortPairs(vect);
		mergeInsert(vect);
		
	// 	std::cout << "\nAfter sorting pairs:\n";
	// 	for (it = vect.begin(); it != vect.end(); it++)
	// 		std::cout << *it << " ";
	// 	std::cout << "\nVect vector\n";
	// 	for (size_t i = 0; i != vect.size(); i += 2)
	// 	{
	// 		mainVect = vect.at(i);
	// 		pendingVect = vect.at(i + 1);
	// 		pending.push_back(pendingVect);
	// 		main.push_back(mainVect);
	// 	}
	// 	vect.clear();
	// 	main.insert(main.begin(), pending.front());
	// 	pending.erase(pending.begin());
	// 	std::cout << "\n\nmain vector\n";
	// 	for (it = main.begin(); it != main.end(); it++)
	// 		std::cout << *it << " ";
	// 	std::cout << "\n\nPending vector\n";
	// 	for (it = pending.begin(); it != pending.end(); it++)
	// 		std::cout << *it << " ";
	// 	std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
