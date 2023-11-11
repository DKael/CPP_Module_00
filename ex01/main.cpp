/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:26:45 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/11 20:04:42 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string get_input(std::string to_print);
bool is_blank(std::string str);

int main()
{
	PhoneBook pb;
	Contact tmp;
	std::string select;
	std::string	idx_input;
	int	idx;

	while (1)
	{
		std::cout << "Select command (1. ADD, 2. SEARCH, 3. EXIT) : ";
		std::getline(std::cin, select);
		if (select == "ADD")
		{
			tmp.set_first_name(get_input("first name : "));
			tmp.set_last_name(get_input("last name : "));
			tmp.set_nickname(get_input("nickname : "));
			tmp.set_phone_number(get_input("phone number : "));
			tmp.set_darkest_secret(get_input("darkest secret : "));
			pb.add(tmp);
		}
		else if (select == "SEARCH")
		{
			if (pb.get_size() == 0)
			{
				std::cout << "Phonebook empty\n";
				continue;
			}
			pb.print_list();
			std::cout << "Select contact index : ";
			std::getline(std::cin, idx_input);
			idx = 1;
			while (1 > idx || idx > 8 || idx > pb.get_size())
			{
				std::cout << "Index out of range!\n";
				std::cout << "Select contact index : ";
				std::getline(std::cin, idx_input);
			}
			pb.get_contact(idx - 1).print_contact();
		}
		else if (select == "EXIT")
		{
			std::cout << "Program quit\n";
			return 0;
		}
		else
			std::cout << "Invalid command!\n";
	}
}

std::string get_input(std::string to_print)
{
	std::string input;

	std::cout << to_print;
	std::getline(std::cin, input);
	while (input.length() == 0 || is_blank(input) == true)
	{
		std::cout << "Empty field not allowed!\n";
		std::cout << to_print;
		std::getline(std::cin, input);
	}
	return input;
}

bool is_blank(std::string str)
{
	int	size;

	size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (!((8 <= str[i] && str[i] <= 13) || str[i] == 32))
			return false;
	}
	return true;
}