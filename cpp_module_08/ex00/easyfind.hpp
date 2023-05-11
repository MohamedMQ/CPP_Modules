/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:29:57 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/02/06 11:57:23 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <iostream>
# include <vector>
# include <list>

class notFoundException : public std::exception {
    public:
        const char *what() const throw();
};

const char *notFoundException::what() const throw() {
    return ("Value not found");
}

template <typename T>
int easyfind(T& container, int num) {
    typename T::iterator iter;
    iter = std::find(container.begin(), container.end(), num);
    if (iter == container.end())
        throw notFoundException();
    return *iter;
}

#endif