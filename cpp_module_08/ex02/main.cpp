/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:01:00 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/02/06 12:04:02 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
    MutantStack<int> myStack;
    std::list<int> theirList;

    std::cout << "\033[33m ========================================\033[0m\n";
    std::cout << "\033[33m|                BEGINING                |\033[0m\n";
    std::cout << "\033[33m ========================================\033[0m\n\n";
    std::cout << "\033[31m===============\033[0m\n";
    std::cout << "\033[31m==== STACK ====\033[0m\n";
    std::cout << "\033[31m===============\033[0m\n\n";
    for (int i = 0; i < 6; i++)
        myStack.push(i + 10);
    std::cout << "myStack size before removing (1st element) : " << myStack.size() << std::endl;
    std::cout << "myStack top element before removing (1st element): " << myStack.top() << std::endl;
    myStack.pop();
    std::cout << "myStack size after removing (1st element) : " << myStack.size() << std::endl;
    std::cout << "myStack top element after removing (1st element) : " << myStack.top() << std::endl;
    std::cout << "\n===> Normal iterators <===\n";
    for (MutantStack<int>::iterator start = myStack.begin(); start != myStack.end(); start++)
        std::cout << *start << " ";
    std::cout << "\n===> Reverse iterators <===\n";
    for (MutantStack<int>::reverseIterator start = myStack.rbegin(); start != myStack.rend(); start++)
        std::cout << *start << " ";
    std::cout << "\n===> const iterators (access only) <===\n";
    for (MutantStack<int>::constIterator start = myStack.cbegin(); start != myStack.cend(); start++)
        std::cout << *start << " ";
    std::cout << "\n===> const reverse iterators (access only) <===\n";
    for (MutantStack<int>::constReverseIterator start = myStack.crbegin(); start != myStack.crend(); start++)
        std::cout << *start << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\033[31m==============\033[0m\n";
    std::cout << "\033[31m==== LIST ====\033[0m\n";
    std::cout << "\033[31m==============\033[0m\n\n";
    for (int i = 0; i < 6; i++)
        theirList.push_back(i + 10);
    std::cout << "theirList size before removing (1st element) : " << theirList.size() << std::endl;
    std::cout << "theirList top element before removing (1st element) : " << theirList.back() << std::endl;
    theirList.pop_back();
    std::cout << "theirList size after removing (1st element) : " << theirList.size() << std::endl;
    std::cout << "theirList top element after removing (1st element) : " << theirList.back() << std::endl;
    std::cout << "\n===> Normal iterators <===\n";
    for (std::list<int>::iterator start = theirList.begin(); start != theirList.end(); start++)
        std::cout << *start << " ";
    std::cout << "\n===> Reverse iterators <===\n";
    for (std::list<int>::reverse_iterator start = theirList.rbegin(); start != theirList.rend(); start++)
        std::cout << *start << " ";
    std::cout << "\n===> const iterators (access only) <===\n";
    for (std::list<int>::const_iterator start = theirList.cbegin(); start != theirList.cend(); start++)
        std::cout << *start << " ";
    std::cout << "\n===> const reverse iterators (access only) <===\n";
    for (std::list<int>::const_reverse_iterator start = theirList.crbegin(); start != theirList.crend(); start++)
        std::cout << *start << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\033[33m ========================================\033[0m\n";
    std::cout << "\033[33m|                 ENDING                 |\033[0m\n";
    std::cout << "\033[33m ========================================\033[0m\n";
    return 0;
}

// int main()
// {
// MutantStack<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// //[...]
// mstack.push(0);
// MutantStack<int>::iterator it = mstack.begin();
// MutantStack<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::stack<int> s(mstack);
// return 0;
// }