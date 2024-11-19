/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:01:51 by bschmidt          #+#    #+#             */
/*   Updated: 2024/08/21 18:37:17 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "MyAwesomePhonebook.hpp"
# include <sstream>
# include <iostream>
# include <string>
# include <unistd.h>

class Phonebook
{
	private:
			Contact	contacts[8];
			int		contacts_count;

	public:
		Phonebook();
		~Phonebook();
		
		void	create_contact(void);
		void	add_contact(Contact contact);
		void	display_phonebook(void);
};

#endif //PHONEBOOK_HPP