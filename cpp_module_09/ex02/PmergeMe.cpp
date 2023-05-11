/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:04:29 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/12/04 09:51:05 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

int PmergeMe::checkNum(const std::string& arg, const std::string& type) {
    std::stringstream streamNum(arg);
    long num;

    if (!(streamNum >> num)
		|| !(streamNum.eof())
		|| num < 0
		|| num > INT_MAX) {
        return 0;
	}
	if (type == "vector")
		_vector.push_back(num);
	else
		_list.push_back(num);
    return 1;
}

void mergeSortVec(std::vector<std::pair<int, int> >& arr) {
    if (arr.size() > 1) {
        std::vector<std::pair<int, int> > left;
        std::vector<std::pair<int, int> > right;

        for (size_t i = 0; i < arr.size() / 2; i++)
            left.push_back(arr[i]);
        for (size_t i = arr.size() / 2; i < arr.size(); i++)
            right.push_back(arr[i]);

        mergeSortVec(left);
        mergeSortVec(right);

        size_t i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i].first < right[j].first) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < left.size()) {
            arr[k] = left[i];
            i++;
            k++;
        }
        while (j < right.size()) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
}

void PmergeMe::sortVector() {
	std::vector <std::pair<int,int> > pairs;
	std::vector<int>	unsortedArr, jscSt, jscStComb;
	int struggler = -1;

	for (size_t i = 0; i < _vector.size() - 1; i += 2)
		pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
	if (_vector.size() % 2)
		struggler = _vector[_vector.size() - 1];

	for (size_t i = 0; i < pairs.size(); i++) {
		if (pairs[i].first > pairs[i].second) {
			int tmp = pairs[i].first;
			pairs[i].first = pairs[i].second;
			pairs[i].second = tmp;
		}
	}

	mergeSortVec(pairs);

	for (size_t i = 0; i < pairs.size(); i++) {
		_sortedVector.push_back(pairs[i].first);
		unsortedArr.push_back(pairs[i].second);
	}


    for (size_t i = 0; i < 30; i++) {
		if (pairs.size() > 1) {
			if (i == 0)
				jscSt.push_back(0);
			else if (i == 1)
				jscSt.push_back(1);
			else
				jscSt.push_back(jscSt[i - 1] + 2 * jscSt[i - 2]);
		} else
			break;
	}

	int k = 1;
	if (jscSt.size()) {
		jscStComb.push_back(jscSt[2]);
		for (size_t i = 3; i < jscSt.size() && jscStComb.size() <= unsortedArr.size(); i++) {
			jscStComb.push_back(jscSt[i]);
			k = 1;
			while (jscStComb.size() <= unsortedArr.size()) {
				int valueToCheck = jscSt[i] - k;
				if (std::find(jscStComb.begin(), jscStComb.end(), jscSt[i] - k) == jscStComb.end()) {
					if (static_cast<size_t>(valueToCheck) <= unsortedArr.size())
						jscStComb.push_back(jscSt[i] - k);
				} else
					break;
				k++;
			}
		}
	}

	if (unsortedArr.size()) {
		int currentNum = unsortedArr.front();
		std::vector<int>::iterator current = std::lower_bound(_sortedVector.begin(), _sortedVector.end(), currentNum);
		_sortedVector.insert(current, currentNum);
		for (size_t i = 1; i < jscStComb.size(); i++) {
			if (static_cast<size_t>(jscStComb[i]) > unsortedArr.size())
				continue;
			currentNum = unsortedArr[jscStComb[i] - 1];
			current = std::lower_bound(_sortedVector.begin(), _sortedVector.end(), currentNum);
			_sortedVector.insert(current, currentNum);
		}
	}

	if (struggler != -1) {
		int currentNum = struggler;
		std::vector<int>::iterator current = std::lower_bound(_sortedVector.begin(), _sortedVector.end(), currentNum);
		_sortedVector.insert(current, currentNum);
	}
}

float PmergeMe::parseSortVector(int ac, char **av) {
	long startVectorTime, endVectorTime;

	startVectorTime = clock();
	for (int i = 1; i < ac; ++i) {
        std::string numStr(av[i]);
        if (!checkNum(numStr, "vector")) {
            std::cerr << "Error\n";
            exit(1);
		}
    }
	sortVector();
	endVectorTime = clock();
	return ((endVectorTime - startVectorTime) / CLOCKS_PER_SEC);
}

void mergeSortList(std::list<std::pair<int, int> >& arr) {
    if (arr.size() > 1) {
        std::list<std::pair<int, int> > left, right;
        std::list<std::pair<int, int> >::iterator mid = arr.begin();
        size_t halfSize = arr.size() / 2;
        for (size_t i = 0; i < halfSize; ++i)
            ++mid;
        left.splice(left.end(), arr, arr.begin(), mid);
        right.splice(right.end(), arr, mid, arr.end());
        mergeSortList(left);
        mergeSortList(right);
        arr.clear();
        std::list<std::pair<int, int> >::iterator leftIt = left.begin();
        std::list<std::pair<int, int> >::iterator rightIt = right.begin();
        while (leftIt != left.end() && rightIt != right.end()) {
            if (leftIt->first < rightIt->first) {
                arr.push_back(*leftIt);
                ++leftIt;
            } else {
                arr.push_back(*rightIt);
                ++rightIt;
            }
        }
        while (leftIt != left.end()) {
            arr.push_back(*leftIt);
            ++leftIt;
        }
        while (rightIt != right.end()) {
            arr.push_back(*rightIt);
            ++rightIt;
        }
    }
}
void PmergeMe::sortList() {
	std::list <std::pair<int,int> > pairs;
	std::list<int> unsortedArr, jscSt, jscStComb;
	int	struggler = -1;

    for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ) {
        int first = *it;
        ++it;
        if (it != _list.end()) {
            int second = *it;
            pairs.push_back(std::make_pair(first, second));
            ++it;
        } else
            struggler = first;
    }

	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
        if (it->first < it->second) {
            int tmp = it->first;
            it->first = it->second;
            it->second = tmp;
        }
    }

	mergeSortList(pairs);

	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        _sortedList.push_back(it->first);
        unsortedArr.push_back(it->second);
    }

	for (size_t i = 0; i < 30; i++) {
		if (pairs.size() > 1) {
			if (i == 0) {
				jscSt.push_back(0);
			} else if (i == 1) {
				jscSt.push_back(1);
			} else {
				std::list<int>::iterator it1 = jscSt.end();
				--it1;
				std::list<int>::iterator it2 = it1;
				--it2;
				jscSt.push_back(*it1 + 2 * (*it2));
			}
		} else {
			break;
		}
	}

	if (jscSt.size()) {
		std::list<int>::iterator it = jscSt.begin();
		for (size_t i = 0; i < 2; i++)
            it++;
		jscStComb.push_back(*it);
		for (it++; it != jscSt.end() && jscStComb.size() <= unsortedArr.size(); ++it) {
			jscStComb.push_back(*it);
			int k = 1;
			while (jscStComb.size() <= unsortedArr.size()) {
				int valueToCheck = *it - k;
				if (std::find(jscStComb.begin(), jscStComb.end(), valueToCheck) == jscStComb.end()) {
					if (static_cast<size_t>(valueToCheck) <= unsortedArr.size())
						jscStComb.push_back(valueToCheck);
				} else
					break;
				k++;
			}
		}
	}

	// for (std::list<int >::iterator it = unsortedArr.begin(); it != unsortedArr.end(); it++) //////////
	// 	std::cout << *it << " | ";
	// std::cout << "\n";
	// for (std::list<int >::iterator it = jscStComb.begin(); it != jscStComb.end(); it++) //////////
	// 	std::cout << *it << " | ";
	// std::cout << "\n";

	if (!unsortedArr.empty()) { 
		std::list<int>::iterator current = unsortedArr.begin();
		int currentNum = *current;
		current = std::lower_bound(_sortedList.begin(), _sortedList.end(), currentNum);
		_sortedList.insert(current, currentNum);
		std::list<int>::iterator it = jscStComb.begin();
		for (size_t i = 1; it != jscStComb.end(); ++i, ++it) {
			if (static_cast<size_t>(*it) >= unsortedArr.size())
				continue;
			std::list<int>::iterator unsortedIt = unsortedArr.begin();
			for (size_t j = 0; j < static_cast<size_t>(*it); j++)
				++unsortedIt;
			currentNum = *unsortedIt;
			current = std::lower_bound(_sortedList.begin(), _sortedList.end(), currentNum);
			_sortedList.insert(current, currentNum);
		}
	}

	if (struggler != -1) {
		int currentNum = struggler;
		std::list<int>::iterator current = std::lower_bound(_sortedList.begin(), _sortedList.end(), currentNum);
		_sortedList.insert(current, currentNum);
	}
}

float PmergeMe::parseSortList(int ac, char **av) {
	double startListTime, endListTime;

	startListTime = clock();
	for (int i = 1; i < ac; ++i) {
        std::string numStr(av[i]);
        if (!checkNum(numStr, "list")) {
            std::cerr << "Error\n";
            exit(1);
		}
    }
	sortList();
	endListTime = clock();
	return ((endListTime - startListTime) / CLOCKS_PER_SEC);
}

void PmergeMe::parseSortNums(int ac, char **av) {
	double vectorTime, listTime;

	vectorTime = parseSortVector(ac, av);
	listTime = parseSortList(ac, av);
	std::cout << "Before:	";
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
		std::cout << *it << " ";
    std::cout << std::endl;
	std::cout << "after:	";
	for (std::vector<int>::iterator it = _sortedVector.begin(); it != _sortedVector.end(); it++)
		std::cout << *it << " ";
    std::cout << std::endl;
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << vectorTime << " us\n";
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list : " << std::fixed << std::setprecision(5) << listTime << " us\n";
}