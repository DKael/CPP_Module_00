/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:26:48 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/11 19:26:49 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	size = 0;
}

void PhoneBook::add(Contact tmp)
{
	list[index] = tmp;
	index++;
	index = index % 8;
	if (size < 8)
		size++;
}

void PhoneBook::print_list()
{
	std::string tmp;

	std::cout << std::setw(10) << "index" << "|"
	<< std::setw(10) << "first name" << "|"
	<< std::setw(10) << "last name" << "|" 
	<< std::setw(10) << "nickname\n";

	for (int i = 0; i < size; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		tmp = list[i].get_first_name();
		if (tmp.length() > 10)
			std::cout << tmp.substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << tmp << "|";
		tmp = list[i].get_last_name();
		if (tmp.length() > 10)
			std::cout << tmp.substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << tmp << "|";
		tmp = list[i].get_nickname();
		if (tmp.length() > 10)
			std::cout << tmp.substr(0, 9) << ".\n";
		else
			std::cout << std::setw(10) << tmp << '\n';
	}
}

Contact PhoneBook::get_contact(int index)
{
	return list[index];
}

int	PhoneBook::get_size()
{
	return size;
}