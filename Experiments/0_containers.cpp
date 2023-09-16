/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_containers.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:58:37 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/16 17:08:01 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

# define GRE "\033[32m"
# define RED "\033[31m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

/* 
Containers are objects that store other objects.
They are implemented as class templates.
The container manages the storage space for its elements and provides member functions 
to access them, either directly or through iterators (reference objects with similar 
properties to pointers). 

Types of containers:
- SEQUENCE containers: store elements in a linear sequence and allow fast insertion and
removal of elements anywhere in the sequence. The following sequence containers are
defined in the standard library:
	- vector
	- deque
	- list
	- forward_list (since C++11)
	- array (since C++11)
	- basic_string (since C++11)

- ASSOCIATIVE	 containers: store elements formed by a combination of a key value and a
mapped value, following a specific order. The following associative containers are
defined in the standard library:
	- set
	- multiset
	- map
	- multimap

- UNORDERED ASSOCIATIVE containers: store elements formed by a combination of a key
value and a mapped value, and which allows for fast retrieval of individual elements
based on their keys. In an unordered associative container, the key value is generally
used to uniquely identify the element, while the mapped value is an object with the
content associated to this key. The following unordered associative containers are
defined in the standard library:
	- unordered_set (since C++11)
	- unordered_multiset (since C++11)
	- unordered_map (since C++11)
	- unordered_multimap (since C++11)

ITERATORS:
- Input iterators: read and process values from a sequence (e.g. std::cin)
- Output iterators: write values to a sequence (e.g. std::cout)
- Forward iterators: read and write values to a sequence (e.g. std::forward_list)
- Bidirectional iterators: read and write values to a sequence in both directions
(e.g. std::list)
- Random-access iterators: read and write values to a sequence in both directions and
jump to any element in the sequence (e.g. std::vector)

examples:
- std::vector<int>::iterator
methods:
referencee:
https://en.cppreference.com/w/cpp/container !!!!

moist basic ones:
- begin() - returns an iterator to the first element of the container
- end() - returns an iterator to the element following the last element of the container
- rbegin() - returns a reverse iterator to the first element of the reversed container
- rend() - returns a reverse iterator to the element following the last element of the
reversed container
- cbegin() - returns a constant iterator to the first element of the container
- cend() - returns a constant iterator to the element following the last element of the
container

*/


int main()
{
	std::cout << std::endl;

	// ---------------------------------------------------------------------------------
	// SEQUENCE CONTAINERS
	// -------------------------------------
	std::cout << YEL "SEQUENCE CONTAINERS" RES << std::endl << std::endl;
	///vector
	std::cout << YEL "VECTOR" RES << std::endl;

	std::vector<int> vec; //creates a vector - structure, where the elements can be added on the back
	for (int i = 0; i < 10; i++)
		vec.push_back(i); //pushes the number to the back of the vector
	std::cout << "size: " << vec.size() << std::endl; //reads the size of the vector
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) //iterates through the vector
		std::cout << *it << " "; //prints the value of the iterator	
	std::endl(std::cout);
	
	std::vector<char> vec1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(static_cast<char>(i + 65));
	for (std::vector<char>::iterator it1 = vec1.begin(); it1 != vec1.end(); it1++)
		std::cout << *it1 << " ";


	std::cout << std::endl << std::endl;

	// ---------------------------------------------------------------------------------

	///list
	std::cout << YEL "LIST" RES << std::endl;
//	std::list<int> l = {1, 2, 3, 4, 5}; // this is initializer list, supported from C++11
	std::list<int> l;
	std::list<int>::iterator i;
	for (int i = 0; i < 10; i++)
		l.push_back(i);
	std::cout << "size of the list: " << l.size() << std::endl; //prints out the size of the list
	for (i = l.begin(); i != l.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	//in lists; you can also push to the front
	l.push_front(100);
	//and back
	l.push_back(200);
	//pushing the iterator back to begin and iterates again through...
	for (i = l.begin(); i != l.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	//you can also push in the middle to tye specific position:
	std::list<int>::iterator pos = std::find(l.begin(), l.end(), 5); // finding a position of 5 usijg iterator
	//if (pos != l.end())
		l.insert(pos, 42);
	for (i = l.begin(); i != l.end(); i++)
		std::cout << *i << " ";
	std::cout << "\n\n";

	// ---------------------------------------------------------------------------------
	std::cout << YEL "DEQUE" RES << std::endl;
	//pronounced "deck" - double ended que
	std::deque<int> dq;
	std::deque<int>::iterator idq;
	for (int i = 0; i < 5; i++)
		dq.push_back(i);
	for (int i = -1; i > -6; i--)
		dq.push_front(i);
	//print out size
	std::cout << dq.size() << std::endl;
	for (idq = dq.begin(); idq != dq.end(); idq++)
		std::cout << *idq << " ";
	std::cout << std::endl;
	//removing values:
	dq.pop_back(); //removes one from back
	dq.pop_front(); // removes one from front
	for (idq = dq.begin(); idq != dq.end(); idq++)
		std::cout << *idq << " ";
	std::cout << std::endl;
	//find a position of specific number and delete it
	
	std::deque<int>::iterator idq_pos  = std::find(dq.begin(), dq.end(), 0);
	dq.erase(idq_pos);
	for (idq = dq.begin(); idq != dq.end(); idq++)
		std::cout << *idq << " ";
	std::cout <<"\n\n\n";
	
	// ---------------------------------------------------------------------------------
	/* ASSOCIATIVE CONTAINERS */

	// ---------------------------------------------------------------------------------
	std::cout << GRE "ASSOCIATIVE CONTAINERS" RES << std::endl << std::endl;
	std::cout << GRE "SET" RES << std::endl;
	std::set<int> s;
	std::set<int>::iterator is;
	//set keeps the values ordered, there is no position dependent insertion like push_back or push_front
	//just .insert() method
	s.insert(5);
	s.insert(1);
	s.insert(154);
	//now when printed, it will be ordered:
	std::cout << "set after set.insert of 5, 1, 154 - will be sorted: " << std::endl;
	for (is = s.begin(); is != s.end(); is++)
		std::cout << *is << " ";
	std::cout << std::endl;
	//can sort a list for you:))
	std::list<int> lst;
	std::set<int> s2;
	for (int i = 5; i > -5; i--)
		lst.push_back(i);
	std::cout << "Can sort a list for you:) Here is unsorted list: " << std::endl;
	for (std::list<int>::iterator tmp = lst.begin(); tmp != lst.end(); tmp++) //unlike vectors, lists doesnt support random access [], needs and iterator
		std::cout << *tmp << " ";
	std::cout << std::endl;

	s2.insert(lst.begin(), lst.end()); // inserts the list into the set
	std::cout << "set s2(printing) after it was assigned unsorted values from lst: s2.insert(lst.begin(), lst.end()): " << std::endl;
	for (is = s2.begin(); is != s2.end(); is++) //printing the set, which is now sorted
		std::cout << *is << " ";
	std::cout << std::endl;
	//we can even give the sorted set values back tio the list:)
	lst.assign(s2.begin(), s2.end());
	std::cout << "set assigned back to the lst(printing): lst.assign(s2.begin(), s2.end()): " << std::endl;
	for (std::list<int>::iterator tmp = lst.begin(); tmp != lst.end(); tmp++) //unlike vectors, lists doesnt support random access [], needs and iterator
		std::cout << *tmp << " ";
	std::cout << "\n\n";

	// ------------------------------------------------------------------------------------

	std::cout << GRE "MAP" RES << std::endl;
	std::map<char, int> m;
	std::map<char, int>::iterator mi;

	std::cout << "Assigning key | value pair <char, int> as m[static_cast<char>(i + 65)] = i" << std::endl;
	for (int i = 0; i < 10; i++)
		m[static_cast<char>(i + 65)] = i;

	std::cout << "Printing keys and values using iterator <char, int> mi->first and mi->second: " << std::endl;
	for (mi = m.begin(); mi != m.end(); mi++)
		std::cout << "key: " << mi->first << " || value: " << mi->second << std::endl;
	std::cout << std::endl;
	
	std::cout << "Directly printing value of the key m['B']: " << m['B'] << std::endl;
	std::cout << std::endl;

	//.If you want to print a key for a value, you cannot directly do that - youy need to find it first:
	char key = '\0';
	for (mi = m.begin(); mi != m.end(); mi++)
		if (mi->second == 2)
		{
			key = mi->first;
			break ;
		}
	std::cout << "Found key for value 2: " << key << std::endl;








	


	

	std::cout << std::endl;






	return 0;
}