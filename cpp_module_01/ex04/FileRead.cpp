/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileRead.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:57:38 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/13 14:57:39 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileRead.hpp"

void    replace(std::string filename, std::string toFind, std::string replace)
{
	std::string 		infile;
    std::string 		outfile;
    std::string			content;
	unsigned long long	i;

	infile = filename;
	outfile = infile + ".replace";
    std::ifstream   ifs(infile);
    if (ifs.is_open())
	{
        if (std::getline(ifs, content, '\0'))
		{
            std::ofstream   ofs(outfile);
            i = content.find(toFind);
            while ( i != std::string::npos )
			{
                content.erase(i, toFind.length());
                content.insert(i, replace);
                i = content.find(toFind);
            }
            ofs << content;
            ofs.close();
        }
        else
		{
            std::cerr << "The file is Empty." << std::endl;
        }
        ifs.close();
    }
	else
	{
        std::cerr << "Cannot open the file." << std::endl;
        exit(1);
    }
}