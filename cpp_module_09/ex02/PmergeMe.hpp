/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:04:33 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/12/02 11:04:35 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <algorithm>
# include <climits>
# include <iomanip>
# include <vector>
# include <list>

class PmergeMe {
	private:
		std::vector<int>	_vector;
		std::vector<int>	_sortedVector;
		std::list<int>		_list;
		std::list<int>		_sortedList;

	public:
		PmergeMe();
		~PmergeMe();
		int checkNum(const std::string& arg, const std::string& type);
		void sortVector();
		float parseSortVector(int ac, char **av);
		void sortList();
		float parseSortList(int ac, char **av);
		void parseSortNums(int ac, char **av);
};

#endif
