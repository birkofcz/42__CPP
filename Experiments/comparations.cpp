/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparations.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:16:42 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/24 15:51:17 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


/* 
Can we compare strings like this?
 */
int main()
{
	std::string str = "01";
	std::string str2 = "12";
	std::string str3 = "0";
	std::string str4 = "-1";
	std::string str5 = "1.2";
	std::string str6 = "1000";
	std::string str7 = "2011-12-31";
	std::string str8 = "2012-01-09";

	std::cout << str << " < " << str2 << " : " << (str < str2) << std::endl;
	std::cout << str4 << " < " << str3 << " : " << (str4 < str3) << std::endl;
	std::cout << str5 << " < " << str6 << " : " << (str5 < str6) << std::endl;
	std::cout << str7 << " < " << str8 << " : " << (str7 < str8) << std::endl;
	return 0;
}