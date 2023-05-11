/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:02:10 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/19 16:12:59 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
 private:
  std::string name;

 public:
  DiamondTrap();
  DiamondTrap(std::string name);
  DiamondTrap(DiamondTrap const& src);
  DiamondTrap& operator=(DiamondTrap const& rhs);
  ~DiamondTrap();

  void attack(const std::string& target);
  void whoAmI();
};

#endif