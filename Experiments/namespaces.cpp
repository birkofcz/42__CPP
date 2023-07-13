/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namespaces.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:50:44 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/13 13:49:07 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

/* Defining two user namespaces with functions of the same name */
namespace first_space
{
	void func()
	{
		cout << "Inside first_space" << endl;
	}
}

// second name space
namespace second_space
{
	void func()
	{
		cout << "Inside second_space" << endl;
	}
}

//using namespace first_space;
//using namespace second_space;
/* int main ()
{
// This calls function from first name space.
	func();
	return 0;
} */

/* More interesting stuff - calling the namespace functions cik-cak 
Telling the compiler which namespace we want to use */
int main()
{
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			first_space::func();
		else
			second_space::func();
	}
	return 0;
}