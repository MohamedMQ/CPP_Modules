/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:51:28 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/11 11:14:06 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Funcs.hpp"

int main() {
    Base* base1;
    Base* base2;

    base1 = generate();
    base2 = generate();
    identify(base1);
    identify(base2);
    identify(*base1);
    identify(*base2);
    delete base1;
    delete base2;
    return 0;
}