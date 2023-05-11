/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:02:23 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/19 14:34:25 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
 protected:
  FragTrap();

 public:
  FragTrap(std::string name);
  FragTrap(FragTrap const& src);
  FragTrap& operator=(FragTrap const& rhs);
  ~FragTrap();

  void	highFivesGuys(void);
};

#endif