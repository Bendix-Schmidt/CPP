/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:14:01 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/27 16:32:24 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &container, int value);

#include "easyfind.tpp"

#endif // EASYFIND_HPP
