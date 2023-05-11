/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:04:14 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/12/02 11:04:16 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <sstream>
# include <cstdlib>

class RPN {
	private:
		std::stack<float> _nums;

	public:
		RPN();
		~RPN();
		RPN(RPN const &copy);
		RPN &operator=(RPN const &other);
		void calcRPN(std::string const &ch);
		void checkEquationRPN(std::string const &equation);
		void calcEquationRPN(std::string const &equation);
		void parseCalcRPN(std::string const &equation);

};

#endif
