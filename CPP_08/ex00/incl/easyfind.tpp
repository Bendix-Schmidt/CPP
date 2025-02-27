/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:15:17 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/27 16:46:38 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator iterator;
	
	iterator = std::find(container.begin(), container.end(), value);
	if (iterator == container.end())
		throw std::runtime_error("value not found in container");
	return (iterator);
}