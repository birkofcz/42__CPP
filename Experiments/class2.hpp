/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class2.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:07:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/29 14:33:21 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS2_H
# define CLASS2_H

class Sample {

public:

	int foo; // declared integer; ATTRIBUTE
	
	Sample(void);  //this is a constructor of a class (no type): <class_name>(parameters);
	~Sample(void); // this is a destructor of a class (no type): ~<class_name>(parameters);

	void bar(void); //member function prototype - METHOD
};

#endif

/* Destructors release memory space occupied by the objects created by the constructor. 
In destructor, objects are destroyed in the reverse of object creation.

Constructors and destructors are both special member function (methods) of a Class */