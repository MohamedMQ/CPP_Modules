/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:02:42 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/19 14:02:44 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
 protected:
  ScavTrap();

 public:
  ScavTrap(std::string name);
  ScavTrap(ScavTrap const& src);
  ScavTrap& operator=(ScavTrap const& rhs);
  ~ScavTrap();

  void attack(const std::string& target);
  void guardGate(void);
};

#endif