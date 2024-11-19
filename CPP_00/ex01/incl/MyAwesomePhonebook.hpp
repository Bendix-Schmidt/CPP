/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhonebook.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:36:45 by bschmidt          #+#    #+#             */
/*   Updated: 2024/08/21 18:36:48 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYAWESOMEPHONEBOOK_HPP
# define MYAWESOMEPHONEBOOK_HPP

# include <iostream>
# include <string>
# include <unistd.h>

# include "Contact.hpp"
# include "Phonebook.hpp"

std::string		get_command(void);
std::string		get_input(const std::string& prompt);

#endif