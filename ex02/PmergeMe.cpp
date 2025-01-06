/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:30:09 by skiam             #+#    #+#             */
/*   Updated: 2025/01/06 22:10:17 by skiam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	jacobsthal(int n)
{
	int jacob[] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763};
	return jacob[n];
}

std::vector<int>::iterator	binary_search(std::vector<int>::iterator start, std::vector<int>::iterator end, int elemSize, int valToFind)
{
	std::vector<int>::iterator	it;
	size_t	mid;

	mid  = std::distance(start, end) / elemSize / 2;
	it = start + mid * elemSize;
//	std::cout << "mid " << mid << " *it " << *it << " start " << *start << " end " << *end << std::endl;

	if (valToFind <	*it)
	{
		if (it == start)
		{
//			std::cout << "it: " << *it << " == start: " << *start << std::endl;
			return (start - (elemSize - 1));
		}
		return binary_search(start, it - elemSize, elemSize, valToFind);
	}
	else
	{
		if (it == end)
		{
//			std::cout << "it: " << *it << " == end: " << *end << std::endl;
			return (end + 1);
		}
		return binary_search(it + elemSize, end, elemSize, valToFind);
	}
}

void	init_pending(std::vector<int> &vect, int elemSize, std::vector<std::pair<std::vector<int>, int> > &pending)
{
	int	nbElements;
	int	nbElementsToPush;
	std::vector<int>::iterator firstValGroup;
	std::vector<int>::iterator lastValGroup;

	nbElements = vect.size() / elemSize;
	nbElementsToPush = (nbElements / 2) - 1;
	if (nbElements & 1)
		nbElementsToPush += 1;
	firstValGroup = vect.begin() + elemSize * 2;
	if (!nbElementsToPush)
		return ;
	for (int i = 0; i < nbElementsToPush; i++)
	{
		std::pair<std::vector<int>, int> tmpPair;
		lastValGroup = firstValGroup + elemSize - 1;
		tmpPair.first.insert(tmpPair.first.begin(), firstValGroup, lastValGroup + 1);
		if (vect.end() - 1 != lastValGroup)
			tmpPair.second = *(lastValGroup + 1);
		else
			tmpPair.second = -1;
		pending.push_back(tmpPair);
		firstValGroup = vect.erase(firstValGroup, lastValGroup + 1);
		firstValGroup += elemSize;
	}
	std::cout << std::endl;
}


void	sort_pairs(std::vector<int> &vect, int elemSize)
{
	int	nbOfGroups;
	int	firstElement;
	int	lastElement;


	nbOfGroups = vect.size() / (elemSize * 2);
	std::cout << "Number of groups " << nbOfGroups << std::endl;
	firstElement = elemSize - 1;
	lastElement = elemSize - 1 + elemSize;
	std::cout << "Original pairs" << std::endl;
	printGroup(vect, elemSize, nbOfGroups);
	for (int i = 1; i <= nbOfGroups; i++)
	{
		if (vect[firstElement] > vect[lastElement])
			for (int j = 0; j < elemSize; j++)
				std::swap(vect[firstElement - j], vect[lastElement - j]);
		firstElement += elemSize * 2;
		lastElement += elemSize * 2;
	}
	std::cout << "Sorted pairs" << std::endl;
	printGroup(vect, elemSize, nbOfGroups);
	std::cout << std::endl;
}


void	merge_insert(std::vector<int> &vect, int elemSize)
{
	int nbOfGroups = vect.size() / (elemSize * 2);
	int	jacobIn = 0;
	std::vector<std::pair<std::vector<int>, int> > pending;
	std::vector<int>::iterator end;
	std::vector<int>::iterator insertIt;

	sort_pairs(vect, elemSize);
	if (vect.size() / elemSize >= 2)
		merge_insert(vect, elemSize * 2);
	else
		return  ;

	std::cout << "-------------------------------------DONE---------------------------------------\n\n";


	draw_tab("Current vector");
	printGroup(vect, elemSize, nbOfGroups);
	printOdd(vect, elemSize);
	init_pending(vect, elemSize, pending);
	if (!pending.size())
		std::cout << "No pend - no insertions. Move on" << std::endl;
	else
	{
		std::cout << std::endl;
		draw_tab("Pending");
	}
	printPending(pending);
	std::cout << std::endl;
	int	prev_jacob = 1;
	int	next_jacob = jacobsthal(jacobIn);
	jacobIn++;
	size_t	insertIndex;
	while (pending.size())
	{
		if (next_jacob <= prev_jacob) 
		{
			prev_jacob = next_jacob;
			next_jacob = jacobsthal(jacobIn);
			jacobIn++;
		}
		insertIndex = next_jacob - prev_jacob;
		if (insertIndex > pending.size())
			insertIndex = pending.size();
		insertIndex -= 1;
//		std::cout << "\n\033[1;32mvect.size() \033[0m" << vect.size() << "\n";
		end = find(vect.begin(), vect.end(), pending[insertIndex].second) - 1;
		if (pending[insertIndex].second == -1)
		{
//			std::cout << "\033[1;31mend == -1; " << *end << " elemSize = " << elemSize << " \033[0m\n";
			//			printGroup(vect, elemSize, nbOfGroups);
		}
		insertIt = binary_search(vect.begin() + elemSize - 1, end, elemSize, pending[insertIndex].first.back());
//		std::cout << "insertIt " << *insertIt << " pending[insertIndex].first.begin() " << *pending[insertIndex].first.begin() << " pending[insertIndex].first.end() " << *(pending[insertIndex].first.end() - 1) << "\n";
		vect.insert(insertIt, pending[insertIndex].first.begin(), pending[insertIndex].first.end());
		pending.erase(pending.begin() + insertIndex);
		next_jacob -= 1;
//		std::cout << "\t\tVect en fin de bouble\n\n";
		//		printGroup(vect, elemSize, nbOfGroups);
	}
	std::cout << std::endl;
	draw_tab("New vector");
	printGroup(vect, elemSize, nbOfGroups);
	printOdd(vect, elemSize);
	std::cout << std::endl;
}
