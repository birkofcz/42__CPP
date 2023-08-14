/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ::_operand.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:45:34 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/14 15:55:20 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
:: = scope resolution operator
- identify and specify the context or scope of a particular code element.
- access global variables when there is a local variable of the same name.
- define a function outside of the class
- access static class members
- specify which namespace a function, class, or variable belongs to
 */
#include <iostream>

/* Basic example of accessing global with local of the same name */
int x = 10;  // global x

int main() {
    int x = 5;  // local x
    std::cout << x << std::endl;      // prints local x: 5
    std::cout << ::x << std::endl;    // prints global x: 10
    return 0;
}

/* Accessing static class members */
/* class MyClass {
public:
    static int staticValue;
};

int MyClass::staticValue = 10;  // define the static member outside the class

int main() {
    std::cout << MyClass::staticValue << std::endl;  // Access using ::
    return 0;
}
 */

/* Specify namespace */
/* namespace First {
    void display() {
        std::cout << "Inside First namespace." << std::endl;
    }
}

namespace Second {
    void display() {
        std::cout << "Inside Second namespace." << std::endl;
    }
}

int main() {
    First::display();   // Calls display of First namespace
    Second::display();  // Calls display of Second namespace
    return 0;
}
 */
