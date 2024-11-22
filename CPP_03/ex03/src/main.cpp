/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:33:38 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/20 19:42:05 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    // Test ClapTrap
    ClapTrap clap("Clappy");
    clap.attack("target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "ClapTrap " << clap.get_name() << " has " << clap.get_HP() << " HP, "
              << clap.get_EP() << " EP, and " << clap.get_AD() << " AD." << std::endl;

    // Test ScavTrap
    ScavTrap scav("Scavvy");
    scav.attack("target2");
    scav.guardGate();

    std::cout << "ScavTrap " << scav.get_name() << " has " << scav.get_HP() << " HP, "
              << scav.get_EP() << " EP, and " << scav.get_AD() << " AD." << std::endl;

    // Test FragTrap
    FragTrap frag("Fraggy");
    frag.attack("target3");
    // Add any specific FragTrap actions if implemented

    std::cout << "FragTrap " << frag.get_name() << " has " << frag.get_HP() << " HP, "
              << frag.get_EP() << " EP, and " << frag.get_AD() << " AD." << std::endl;

    // Test DiamondTrap
    DiamondTrap diamond("Diamondy");
    diamond.attack("target4");
    diamond.whoAmI();

    std::cout << "DiamondTrap " << diamond.get_name() << " has " << diamond.get_HP() << " HP, "
              << diamond.get_EP() << " EP, and " << diamond.get_AD() << " AD." << std::endl;

    return 0;
}