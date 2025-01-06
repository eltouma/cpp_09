/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:51:35 by ahayon            #+#    #+#             */
/*   Updated: 2025/01/03 18:38:01 by skiam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Error: Please enter a valid file as parameter" << std::endl;
		return (1);
	}
	
	BitcoinExchange	btc;

	btc.loadDataBase("data.csv");
	btc.loadInputFile(argv[1]);

	return (0);
}
