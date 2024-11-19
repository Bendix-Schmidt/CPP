/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:01:39 by bschmidt          #+#    #+#             */
/*   Updated: 2024/08/21 18:37:20 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "MyAwesomePhonebook.hpp"
# include <iomanip>
# include <iostream>
# include <string>
# include <unistd.h>

class Contact
{
	private:
			std::string _first_name;
			std::string _last_name;
			std::string _nick_name;
			std::string _phone_number;
			std::string _darkest_secret;

	public:
			Contact();
			~Contact();

			void	set_first_name(std::string first_name);
			void	set_last_name(std::string last_name);
			void	set_nick_name(std::string nick_name);
			void	set_phone_number(std::string phone_number);
			void	set_darkest_secret(std::string darkest_secret);

			void	display_preview(int index);
			void	display_full(int index);
};

#endif //CONTACT_HPP