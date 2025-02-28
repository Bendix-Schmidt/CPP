/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:09:32 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/28 18:13:33 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//methods
void	Span::addNumber(int num)
{
	if (storedNums < N)
	{
		storage[storedNums] = num;
		storedNums++;
	}
	else
		throw LimitException();
}

int		Span::shortestSpan(void) const
{
	if (storedNums <= 1)
		throw StorageException();
	
	std::vector<int> sortedStorage = storage;
	std::sort(sortedStorage.begin(), sortedStorage.end());

	int span = std::abs(sortedStorage[1] - sortedStorage[0]);
	
	for (size_t i = 2; i < storedNums; i++)
	{
		int newSpan = std::abs(sortedStorage[i] - sortedStorage[i - 1]);
		if (newSpan < span)
			span = newSpan;
	}
	return (span);
}

int		Span::longestSpan(void) const
{
	if (storedNums <= 1)
		throw StorageException();
	
	std::vector<int> sortedStorage = storage;
	std::sort(sortedStorage.begin(), sortedStorage.end());

	int span = std::abs(sortedStorage.back() - sortedStorage.front());

	return (span);
}

void	Span::fillStorage(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	srand(time(NULL));
	while (start != end)
	{
		int num = rand();
		addNumber(num);
		start++;
	}
}

//getters
unsigned int	Span::getN(void) const
{
	return (N);
}

unsigned int	Span::getStoredNums(void) const
{
	return (storedNums);
}

int		Span::getIntatIndex(int index) const
{
	return (storage[index]);
}

std::vector<int>::iterator Span::getStorageStart(void)
{
	return (storage.begin());
}

std::vector<int>::iterator Span::getStorageEnd(void)
{
	return (storage.end());	
}

const char*	Span::LimitException::what() const throw()
{
	return ("Number could not be added - Storage is already full.");
}

const char*	Span::StorageException::what() const throw()
{
	return ("Not enough numbers stored to define a span");
}

//constructors
Span::Span() : N(0), storedNums(0){}

Span::Span(unsigned int n) : N(n), storedNums(0)
{
	this->storage = std::vector<int>(n);
}

Span::Span(const Span &original)
{
	*this = original;
}

Span &Span::operator=(const Span &original)
{
	if (this == &original)
        return *this;
	this->N = original.N;
	this->storedNums = original.storedNums;
	this->storage = original.storage;
	return (*this);
}

Span::~Span() {}

//outstream:
std::ostream &operator<<(std::ostream &stream, Span const &storage)
{
	stream << "Storage-Vector: [";
	for (size_t i = 0; i < storage.getStoredNums(); i++)
	{
		stream << storage.getIntatIndex(i) << " ";
	}
	stream << "]";
	return (stream);
}