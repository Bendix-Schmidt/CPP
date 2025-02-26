/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:30:00 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/26 16:03:22 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/whatever.hpp"

int main( void )
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}



//MY OWN TESTING BELOW done before I realized there is a test given :/
/* int main(void)
{
	int x = 5;
	int y = 10;

	//testing swap with ints
	std::cout << "x: " << x << "\ny: " << y << std::endl;
	swap(x, y);
	std::cout << "x after swap: " << x << "\ny after swap: " << y << std::endl;
	swap(x, y);

	//testing swap with strings
	std::string str1 = "first";
	std::string str2 = "second";
	std::cout << "str1: " << str1 << "\nstr2: " << str2 << std::endl;
	swap(str1, str2);
	std::cout << "str1 after swap: " << str1 << "\nstr2 after swap: " << str2 << std::endl;
	swap(str1, str2);

	//testing min and max with ints:
	std::cout << "min of x(5) and y(10): " << min(x, y) << std::endl;
	std::cout << "max of x(5) and y(10): " << max(x, y) << std::endl;

	//testing min and max with strings:
	std::string str3 = "aa";
	std::cout << "min of str1(first) and str2(second): " << min(str1, str2) << std::endl;
	std::cout << "min of str1(first) and str3(aa): " << min(str1, str3) << std::endl;
	std::cout << "max of str1(first) and str2(second): " << max(str1, str2) << std::endl;
	std::cout << "max of str1(first) and str3(aa): " << max(str1, str3) << std::endl;
} */