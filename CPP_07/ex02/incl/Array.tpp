/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bendixschmidt <bendixschmidt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:16:07 by bendixschmi       #+#    #+#             */
/*   Updated: 2025/02/26 20:27:30 by bendixschmi      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.hpp"

template<typename T>
Array<T>::Array(): array(NULL), size(0) {}

template <typename T>
Array<T>Array(unsigned int n): array(new T[n]), size(n){}

template <typename>