/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkParams.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:11:52 by skiam             #+#    #+#             */
/*   Updated: 2025/01/07 00:13:33 by skiam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp" 

int	check_input(char *s, std::vector<int> &vect, std::deque<int> &deque)
{
	std::string	str;
	long	nb;
	char	*endptr;

	str = s;
	nb = strtol(str.c_str(), &endptr, 10);
	if (endptr == str.c_str() || *endptr != '\0')
		return (1);
	if (nb < 0 || nb > INT_MAX)
		return (1);
	vect.push_back(nb);
	deque.push_back(nb);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

char    *isString(int argc, char **argv, char *input, char *&buff)
{
        std::string str;
        char    *dup;

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
                input = strtok(dup, " ");
        }
        else
                input = strtok(argv[1], " ");
        return (input);
}

int	handle_dup(std::vector<int> vect, std::vector<int>::iterator it, char *buff)
{
	std::vector<int>	tmp;
	tmp.insert(tmp.begin(), vect.begin(), vect.end());
	sort(tmp.begin(), tmp.end());
	it = adjacent_find(tmp.begin(), tmp.end());
	if (it != tmp.end())
	{
		if (buff)
			delete [] buff;
		return (1);
	}
	return (0);
}

