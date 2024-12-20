/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayon <ahayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:03:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/20 01:14:38 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
std::vector<int>::iterator	binarySearch(int value, std::vector<int> vect, unsigned long groupSize, unsigned long groupNb)
{
	std::vector<int>::iterator low = vect.begin() + (groupSize);
	std::vector<int>::iterator high = vect.end();
	while (low != high)
	{
		int mid = (*low + *high) / 2;
		std::cout << "mid = " << mid << std::endl;
		if (value >= mid)
		{
			low = vect.begin() + (groupSize * groupNb) / 2;
			groupNb /= 2;
			low++;
		}
		else
		{
			high = vect.begin() + (groupSize * groupNb) / 2;
			groupNb /= 2;
			high--;
		}
	}
	return low;
}
*/
/*
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
*/


//std::vector<int>::iterator	findInsertIndex(std::vector<int> &main, std::vector<int> &rest, unsigned long goupSize grps)
// {

// }


//	if (pending.size())
//	{
/*
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
*/
//	}
//}

//std::vector<int>	mergeInsert(std::vector<int> &main)
//{
/*
	unsigned long		total_size = main.size();
	std::vector<int>	pending;
	std::vector<int>	jacob = generateJacobsthal(total_size / 2);
	std::vector<int> 	rest;

	sortPairs(main);
//	int power = static_cast<int>(log(main.size()) / log(2));
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

		if (isOdd == 1) {int
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
		std::cout << "\n\nPending chain:\n";int
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
					std::cout << "pending.back() == mid\n";int
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
			std::cout << "\n\nMain chain:\n";
			for (std::vector<int>::iterator itM = main.begin(); itM != main.end(); itM++)
		 		std::cout << *itM << " ";
			std::cout << "\n\nPending chain:\n";
			for (std::vector<int>::iterator itP = pending.begin(); itP != pending.end(); itP++)
		 		std::cout << *itP << " ";
			if (pending.size() > 0)
			{int
				std::vector<int>::iterator	placetobe = binarySearch(*(pending.begin() + groupSize), main, groupSize, groupNb);
				std::cout << "placetobe = " << *placetobe << std::endl;
			}
			// if (isOdd) {
				
			// }
			power--;

		}
		power--;
	}
	return main;

}
   */

std::vector<int> generateJacobsthal(int maxValue) 
{
	std::vector<int> jacobsthal;

	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
    for (unsigned long i = 2; i < static_cast<unsigned long>(maxValue); ++i) 
	{
        int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        if (next > maxValue) break;
        jacobsthal.push_back(next);
	}
	return jacobsthal;
}

std::vector<int> JacobOrder(unsigned long n)
{
	std::vector<int> jacob = generateJacobsthal(static_cast<int>(n));
	std::vector<int> jacobOrder;
		
	//std::cout << "jacob.begin() " << *jacob.begin() << "\n";
	for (std::vector<int>::iterator it = jacob.begin() + 3; it < jacob.end(); it++)
	{
		int prevValue = *(it - 1);
		//std::cout << "prevValue " << prevValue << "\n";
		for (int currValue = *it; currValue > prevValue; currValue--)
		{
			//std::cout << "dans le if prevValue " << prevValue << "\n";
			//std::cout << "dans le if currValue " << currValue << "\n";
			jacobOrder.push_back(currValue);
		}
	}
	
	for (std::vector<int>::iterator it = jacobOrder.begin(); it < jacobOrder.end(); it++)
		std::cout << "jacob order : " << *it << std::endl;
	return (jacobOrder);
}

std::vector<int>::iterator	binarySearch(std::vector<int>::iterator start, std::vector<int>::iterator end, int sizeElement, int valToFind)
{
	std::cout << __func__ << "\n";
	std::vector<int>::iterator	it;
	size_t	mid;

	mid  = std::distance(start, end) / sizeElement / 2;
	it = start + mid * sizeElement;
	std::cout << "mid " << mid << " *it " << *it << " start " << *start << " end " << *end << std::endl;

	if (valToFind <	*it)
	{
		if (it == start)
		{
			std::cout << "it: " << *it << " == start: " << *start << std::endl;
			return (start - (sizeElement - 1));
		}
		return binarySearch(start, it - sizeElement, sizeElement, valToFind);
	}
	else
	{
		if (it == end)
		{
			std::cout << "it: " << *it << " == end: " << *end << std::endl;
			return (end + 1);
		}
		return binarySearch(it + sizeElement, end, sizeElement, valToFind);
	}
}

void initPending(std::vector<int> &vect, int sizeElement, std::vector<std::pair<std::vector<int>, int> > &pending)
{
	int	nbElements;
	int	nbElementsToPush;
	std::vector<int>::iterator firstValGroup;
	std::vector<int>::iterator lastValGroup;

	std::cout << "\n\033[1;36mvect.size() \033[0m" << vect.size() << " sizeElement " << sizeElement << "\n";
	nbElements = vect.size() / sizeElement;
	nbElementsToPush = (nbElements / 2) - 1;
	if (nbElements & 1)
		nbElementsToPush += 1;
	std::cout << "nbElements " << nbElements << ", nbElementsToPush " << nbElementsToPush << "\n";
	firstValGroup = vect.begin() + sizeElement * 2;
	if (!nbElementsToPush)
		return ;
	std::cout << "firstValGroup " << *firstValGroup << "\n";
	for (int i = 0; i < nbElementsToPush; i++)
	{
		std::pair<std::vector<int>, int> tmpPair;
		lastValGroup = firstValGroup + sizeElement - 1;
	printVect(vect);
		std::cout << "lastValGroup " << *lastValGroup << " end " << *(vect.end() - 1) << "\n";
		tmpPair.first.insert(tmpPair.first.begin(), firstValGroup, lastValGroup + 1);
		if (vect.end() - 1 != lastValGroup)
			tmpPair.second = *(lastValGroup + 1);
		else
			tmpPair.second = -1;
		pending.push_back(tmpPair);
		firstValGroup = vect.erase(firstValGroup, lastValGroup + 1);
		std::cout << "\n\n";
		printVect(vect);
		std::cout << "\n\n";
		firstValGroup += sizeElement;
	}
}

void	sortPairs(std::vector<int> &vect, int sizeElement)
{
	int	pairNb;
	int	firstElement;
	int	lastElement;
	

	pairNb = vect.size() / (sizeElement * 2);
	firstElement = sizeElement - 1;
	lastElement = sizeElement - 1 + sizeElement;
	for (int i = 1; i <= pairNb; i++)
	{
		if (vect[firstElement] > vect[lastElement])
			for (int j = 0; j < sizeElement; j++)
				std::swap(vect[firstElement - j], vect[lastElement - j]);
		firstElement += sizeElement * 2;
		lastElement += sizeElement * 2;
	}
}

void	printPending(std::vector<std::pair<std::vector<int>, int> > pending)
{
	for (size_t i = 0; i < pending.size(); i++)
	{
		for (size_t j = 0; j < pending[i].first.size(); j++)
		{
			std::cout << "first: " << pending[i].first.at(j) << " ";
		}
		std::cout << "second: " << pending[i].second << "\n";
	}
	
}

void	printVect(std::vector<int> vect)
{
	std::cout << "vect: " << std::endl;
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << "\n\n";
	
}

void	mergeInsert(std::vector<int> &vect, int sizeElement)
{
	std::vector<std::pair<std::vector<int>, int> > pending;
	std::vector<int>::iterator end;
	std::vector<int>::iterator insertIt;

	sortPairs(vect, sizeElement);
	if (vect.size() / sizeElement >= 2)
		mergeInsert(vect, sizeElement * 2);
	else
		return ;
	std::cout << "vect.size() " << vect.size() << " sizeElement " << sizeElement << "\n";
	std::vector<int> jacobOrder = JacobOrder(vect.size());
	unsigned long total_size = vect.size();
	printVect(vect);
	initPending(vect, sizeElement, pending);
	printPending(pending);
	std::vector<int>::iterator jacIt = jacobOrder.begin();
	while (vect.size() != total_size)
	{
		std::cout << "\n\033[1;32mvect.size() \033[0m" << vect.size() << "\n";
		std::cout << "\n\tdebut boucle insertion jacIt = " << *jacIt << " ett JacIt - 2 :" << *jacIt - 2 << " ok" << std::endl;
		if (pending[*jacIt - 2].second) {
			
			std::cout << "suite boucle insertion" << std::endl;
			std::cout << "pending[*jacIt -2 ].second " << pending[*jacIt -2 ].second << " OK" << "\n";
			end = find(vect.begin(), vect.end(), pending[*jacIt -2 ].second) - 1;
			std::cout << "end " << *end << " ";
			insertIt = binarySearch(vect.begin() + sizeElement - 1, end, sizeElement, pending[*jacIt - 2].first.back());
			std::cout << "insertIt " << *insertIt << " pending[*jacIt - 2].first.begin() " << *pending[*jacIt - 2].first.begin() << " pending[*jacIt - 2].first.end() " << *(pending[*jacIt - 2].first.end() - 1) << "\n";
			vect.insert(insertIt, pending[*jacIt - 2].first.begin(), pending[*jacIt - 2].first.end());
			//pending.erase(pending.begin());
			std::cout << "\t\tVect en fin de bouble\n\n";
			printVect(vect);
		}
		if  (pending[*jacIt - 2].second == -1)
			{
				std::cout << "\033[1;31mboldon est -1\033[0m\n";
					return ;
			}
		jacIt++;
	//	}
	}
	std::cout << "PRINT VECT TEST\n";
	printVect(vect);
	pending.clear();
}

int	main(int argc, char **argv)
{
	char	*input;
	char	*buff;
	std::vector<int>	vect;
	std::vector<int>	main;
	std::vector<int>	pending;
	std::vector<int>::iterator	it;

	input = NULL;
	buff = NULL;
	if (argc < 2)
		return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
	input = isString(argc, argv, input, buff);
	std::cout << "input = ";
	while (input != NULL)
	{
		std::cout << input << " ";
		if (checkInput(input, vect))
		{
			if (buff)
				delete [] buff;
			return (std::cerr << "Error\nWrong input" << std::endl, 1);
		}
		input = strtok(NULL, " ");
	}
	std::cout << "\n";
	if (vect.size() == 1)
		return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
	mergeInsert(vect, 1);
	std::cout << "\nAfter sorting pairs:\n";
	for (it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	if (buff)
		delete [] buff;
}
