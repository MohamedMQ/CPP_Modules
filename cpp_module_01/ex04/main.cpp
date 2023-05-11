/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:57:49 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/13 14:57:51 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileRead.hpp"

int main (int ac, char **av)
{
	std::string infile;
    std::string outfile;

    if (ac != 4)
	{
        std::cerr << "Usage: ./FileRead <filename> <to_find> <replace>." << std::endl;
        return (1);
    }
	else
	{
		infile = av[1];
		outfile = infile + ".replace";
        replace(av[1], av[2], av[3]);
    }
    return (0);
}
