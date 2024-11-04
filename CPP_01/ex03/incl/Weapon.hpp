/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:21:18 by bschmidt          #+#    #+#             */
/*   Updated: 2024/10/30 18:24:55 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIOLENCE_HPP
#define VIOLENCE_HPP

#include <iostream>
#include <string>

class	Weapon
{
	private:
		std::string _type;

	public:
		Weapon(const std::string& type);
    	~Weapon();
		
		const	std::string&	getType() const;
		void	setType(const std::string& type);
};

#endif // VIOLENCE_HPP