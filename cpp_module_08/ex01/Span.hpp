/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:42:02 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/02/06 11:01:40 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <limits.h>
# include <vector>

class Span {
    private:
        unsigned int        _N;
        std::vector<int>    _nums;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span &cpy);
        ~Span();
        Span &operator=(const Span &cpy);
        void addNumber(int num);
        unsigned long shortestSpan();
        unsigned long longestSpan();
        class excededMaxNumber : public std::exception {
            public:
                const char *what() const throw ();
        };
        class notEnouphNumberLenght : public std::exception {
            public:
                const char *what() const throw ();
        };
        void addNumbersAtOnce(std::vector<int>::iterator& start, std::vector<int>::iterator& end);
};

#endif