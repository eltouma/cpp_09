/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayon <ahayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:03:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/16 22:34:48 by eltouma          ###   ########.fr       */
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
	std::cout << __func__ << "\n";
	for (unsigned long i = 2; i <= vect.size(); i *= 2)
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
		std::cout << "\nIteration of sorting pairs:\n";
		for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
			std::cout << *it << " ";
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

// std::vector<int>::iterator	findInsertIndex(std::vector<int> &main, std::vector<int> &rest, unsigned long goupSize grps)
// {

// }

/*
int	binarySearch(std::vector<int> &main, int low, int high, std::vector<int> &pending)
{
	int	mid;
	std::vector<int>::iterator it;

//	if (pending.size())
//	{
		std::cout << "\n";
		for (it = main.begin(); it != main.end() - groupSize; it++)
			high = *it;
		for (it = main.begin(); it != main.begin() + groupSize; it++)
			low = *it;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (pending.back() == mid)
			{
				std::cout << "pending.back() == mid\n";
				break ;
			}
			if (pending.back() > mid)
				low = mid + 1;
			if (pending.back() < mid)
				high = mid - 1;
			std::cout << "main size "<< main.size() - (groupNb - 1)<< "\n";
			std::cout << "high "<< high << "\n";
			std::cout << "low "<< low << "\n";
			std::cout << "mid "<< mid << "\n";
			std::cout << "last pending element " << pending.back() << "\n";
			std::cout << "groupSize size "<< groupSize<< "\n";
			std::cout << "groupNb size "<< groupNb << "\n";
		}
//	}
}
*/

std::vector<int>	mergeInsert(std::vector<int> &main)
{
	unsigned long		total_size = main.size();
	std::vector<int>	pending;
	std::vector<int>	jacob = generateJacobsthal(total_size / 2);
	std::vector<int> 	rest;

	int power = static_cast<int>(log(main.size()) / log(2));
	std::cout << "\n\nPower before loop -= 2: " << power << std::endl;
	power -= 2;
	std::cout << "\n\nPower before loop = " << power << std::endl;
	while (power >= 0)
	{
		unsigned long groupSize = pow(2, power);
		std::cout << "\nGroup size = " << groupSize << std::endl;
		unsigned long groupNb 	= total_size / groupSize;
		bool	isOdd = groupNb & 1;
		std::cout << "\nGroup nb = " << groupNb << "\t isOdd = " << isOdd << std::endl;

		if (isOdd == 1) {
			rest.insert(rest.end(), main.begin() + groupSize * (groupNb - 1), main.end());
			main.erase(main.begin() + groupSize * (groupNb - 1), main.end());
		}
		else {
			if (groupNb * groupSize != total_size) {
				std::cout << "JE PASSE ICI\n";
				rest.insert(rest.end(), main.begin() + groupSize * (groupNb), main.end());
				main.erase(main.begin() + groupSize * (groupNb), main.end());
			}
		}
		std::cout << "\n\nRest chain:\n";
		for (std::vector<int>::iterator itR = rest.begin(); itR != rest.end(); itR++)
			std::cout << *itR << " ";
		for (unsigned long iteration = groupSize * 2; iteration < main.size(); iteration += (groupSize * 2))
		{
			if (iteration + groupSize <= main.size())
			{
				std::cout << "\nboucle iter" << std::endl;
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
		// if (isOdd) {

		// }
		int	low;
		int	high;
		int	mid;
		std::vector<int>::iterator it;
		if (pending.size())
		{
			std::cout << "\n";
			for (it = main.begin(); it != main.end() - groupSize; it++)
				high = *it;
			for (it = main.begin(); it != main.begin() + groupSize; it++)
				low = *it;
			std::cout << "BEFORE high "<< high << "\n";
			std::cout << "BEFORE low "<< low << "\n";
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (pending.back() == mid)
				{
					std::cout << "pending.back() == mid\n";
					break ;
				}
				if (pending.back() > mid)
					low = mid + 1;
				if (pending.back() < mid)
					high = mid - 1;
				std::cout << "main size "<< main.size() - (groupNb - 1)<< "\n";
				std::cout << "high "<< high << "\n";
				std::cout << "low "<< low << "\n";
				std::cout << "mid "<< mid << "\n";
				std::cout << "last pending element " << pending.back() << "\n";
				std::cout << "groupSize size "<< groupSize<< "\n";
				std::cout << "groupNb size "<< groupNb << "\n";
			}
		}
		power--;
	}
	return main;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

int	main(int argc, char **argv)
{
	char	*input;
	std::string str;
	char	*dup;
	char	*buff;
	std::vector<int>	vect;
	std::vector<int>	main;
	std::vector<int>	pending;
	std::vector<int>::iterator	it;
	//int	last;
	// int	pendingVect;
	// int	mainVect;

	buff = NULL;
	if (argc < 2)
		return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
	// If argc > 2 => transforme tous les argc en string
	if (argc > 2)
	{
		for (int i = 1; i < argc; i++)
		{
			str.reserve(ft_strlen(argv[i]));
			str += argv[i];
			str.reserve(1);
			str += " ";
		}
		buff = new char[str.size() + 1];
		dup = strcpy(buff, str.c_str());
		input = strtok(buff, " ");
	}
	else
		input = strtok(argv[1], " ");
	size_t i = 0;
	while (input != NULL)
	{
		//	std::cout << "input = " << input << std::endl;
		if (checkInput(input, vect))
		{
			if (buff)
				delete [] buff;
			return (std::cerr << "Error\nWrong input" << std::endl, 1);
		}
		//	std::cout << "element: " << vect[i] << std::endl;
		i += 1;
		input = strtok(NULL, " ");
	}

	// if (vect.size() & 1)
	// {
	// 	std::cout << "last = " << vect.back() << "\n";
	// 	std::cout << "vect.size() vaut " << vect.size() << " c'est impair\n";
	// 	last = vect.back();
	// 	vect.pop_back();
	// 	std::cout << "now last = " << last << "\n";
	// }
	// else
	//	std::cout << "vect.size() vaut " << vect.size() << std::endl;

	if (buff)
		delete [] buff;
	if (vect.size() == 1)
		return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
	// for (size_t i = 0; i != vect.size(); i += 2)
	// {
	// 	if (vect[i] < vect[i + 1]) 
	// 		std::swap(vect[i], vect[i + 1]);

	// }
	sortPairs(vect);

	std::cout << "\nAfter sorting pairs:\n";
	for (it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	mergeInsert(vect);
	// std::cout << "\nVect vector\n";
	// for (size_t i = 0; i != vect.size(); i += 2)
	// {
	// 	mainVect = vect.at(i);
	// 	pendingVect = vect.at(i + 1);
	// 	pending.push_back(pendingVect);
	// 	main.push_back(mainVect);
	// }
	// vect.clear();
	// main.insert(main.begin(), pending.front());
	// pending.erase(pending.begin());
	// std::cout << "\n\nmain vector\n";
	// for (it = main.begin(); it != main.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << "\n\nPending vector\n";
	// for (it = pending.begin(); it != pending.end(); it++)
	// 	std::cout << *it << " ";
}
