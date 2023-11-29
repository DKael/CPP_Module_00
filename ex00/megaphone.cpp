/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:45:16 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/29 09:45:17 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		std::string	str;
		int			size;
		std::locale	loc;

		for (int i = 1; i < argc; i++)
		{
			str = argv[i];
			size = str.size();
			for (int j = 0; j < size; j++)
				str[j] = std::toupper(str[j], loc);
			std::cout << str;
		}
		std::cout << '\n';
	}
}
