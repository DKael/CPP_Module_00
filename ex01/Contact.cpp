/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:26:54 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/11 19:26:54 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::get_first_name() const
{
	return this->first_name;
}

std::string Contact::get_last_name() const
{
	return this->last_name;
}

std::string Contact::get_nickname() const
{
	return this->nickname;
}

std::string Contact::get_phone_number() const
{
	return this->phone_number;
}

std::string Contact::get_darkest_secret() const
{
	return this->darkest_secret;
}

void Contact::set_first_name(std::string _first_name)
{
	this->first_name = _first_name;
}

void Contact::set_last_name(std::string _last_name)
{
	this->last_name = _last_name;
}

void Contact::set_nickname(std::string _nickname)
{
	this->nickname = _nickname;
}

void Contact::set_phone_number(std::string _phone_number)
{
	this->phone_number = _phone_number;
}

void Contact::set_darkest_secret(std::string _darkest_secret)
{
	this->darkest_secret = _darkest_secret;
}

void Contact::print_contact()
{
	std::cout << "first name : " << first_name << '\n';
	std::cout << "last name : " << last_name << '\n';
	std::cout << "nickname : " << nickname << '\n';
	std::cout << "phone number : " << phone_number << '\n';
	std::cout << "darkest secret : " << darkest_secret << '\n';
}