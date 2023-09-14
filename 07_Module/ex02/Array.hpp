/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:05:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/14 16:19:41 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

/* Colors */
# define GRE "\033[32m"
# define RED "\033[31m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

/* Templates */
template <class T>
class Array
{
	private:
		T*		_array;
		int		_size;

	public:
		//Default constructor
		Array()
		{
			_array = NULL;
			_size = 0;
		}

		//Constructor with parameter
		Array(unsigned int n)
		{
			_array = new T[n];
			_size = n;
		}
		
		//Copy constructor
		Array(const Array& original)
		{
			_array = new T[original._size];
			_size = original._size;
			for (int i = 0; i < original._size; i++)
				_array[i] = original._array[i];
		}

		//Assignment operator
		Array& operator=(const Array& src)
		{
			if (this != &src)
			{
				delete[] _array;
				_array = new T[src._size];
				_size = src._size;
				for (unsigned int i = 0; i < src._size; i++)
					_array[i] = src._array[i];
			}
			return (*this);
		}
		//Destructor
		~Array() {delete[] _array;}

		//Access to elements of array through operator[] (subscript operator)
		T& operator[](int index) const
		{
			if (index < 0 || index >= this->_size)
				throw std::length_error("Index out of range"); //throwing predefined exception here.
			return (this->_array[index]);
		}	

		//Return size of array - member function size()
		int size() const {return _size;}
};

//Template function to print array
template <typename T>
void printArray(Array<T> arr)
{
	if (arr.size() == 0) 
	{
		std::cout << RED << "Empty array" << RES << std::endl;
		return;
	}
	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

#endif