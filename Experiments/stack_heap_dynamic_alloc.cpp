/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_heap_dynamic alloc.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:48:13 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/06 14:16:51 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* Dynamic allocation in C++ */

/* Dynamicka alokace nam umoznuje vytvaret promenne ne na zaklade deklarace, 
ale podle potreby programu
Experiment with valgrind ./a.out to see what is going on with or without delete statement.
 */

/* Dynamic allocation happens on the HEAP - and needs to be freed after the prigram is done. */

int main()
{
	std::string *name = new std::string; //"new is used to dyamically alloc memory space"
	
	std::cout << std::endl;

	std::cout << "[[ DYNAMIC MEMORY ALLOCATION ]]" << std::endl;
	std::cout << std::endl;
	std::cout << "std::string *name = new std::string;" << std::endl << std::endl;

	*name = "Alice";
	std::cout << "Address of the poiter 'name' to dynamic memory: " << name << std::endl;
	std::cout << "Saved name: " << *name << " is " << name->length() << " chars long." << std::endl;
	
	
	*name = "EleanorTheThird";
	std::cout << "Address of the poiter 'name' to dynamic memory: " << name << std::endl;
	std::cout << "Saved name: " << *name << " is " << name->length() << " chars long." << std::endl;

	delete name; // frees the memory
	name = nullptr;
	std::cout << "Address of the poiter 'name' to dynamic memory: " << name << std::endl;
	std::cout << "Saved name: " << *name << std::endl << std::endl; //here will be segfault;

	return 0;	
}

/* Stack version - it is not about the resizing. Experiment with valgrind */
/* int main() {
    std::cout << "[[ STACK MEMORY ALLOCATION ]]" << std::endl;
    std::cout << std::endl;

    std::string name = "Alice"; // This is on the stack, but the memory for the string content is dynamically managed
    std::cout << "Saved name: " << name << " is " << name.length() << " chars long." << std::endl;

    name = "EleanorTheThird"; // Still on the stack, but can adjust its size because the content memory is dynamic
    std::cout << "Saved name: " << name << " is " << name.length() << " chars long." << std::endl;

    return 0;
} */

/* CHRONO livbrary (C11) - just to illustrate stack / heap access times */
/* #include <iostream>
#include <chrono>
#include <random>

const int ARRAY_SIZE = 1000000;
const int NUM_ACCESSES = 100000;

int main() {
    int stackArray[ARRAY_SIZE];
    int* heapArray = new int[ARRAY_SIZE];

    // Initialize random engine
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, ARRAY_SIZE - 1);

    // Measure stack access time
    auto startStack = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_ACCESSES; ++i) {
        stackArray[dis(gen)] = i;
    }
    auto endStack = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> stackTime = endStack - startStack;

    // Measure heap access time
    auto startHeap = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_ACCESSES; ++i) {
        heapArray[dis(gen)] = i;
    }
    auto endHeap = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> heapTime = endHeap - startHeap;

    std::cout << "Stack access time: " << stackTime.count() << " ms" << std::endl;
    std::cout << "Heap access time: " << heapTime.count() << " ms" << std::endl;

    delete[] heapArray;

    return 0;
} */

/* Theory */
/* 
Choosing between stack and heap memory in C++ often depends on specific requirements and the nature of the problem being solved. 
Here are some reasons to use one over the other:

///Stack Memory:
Automatic Memory Management: Objects created on the stack are automatically destroyed when they go out of scope. 
This can help prevent memory leaks, especially in scenarios where the lifetime of an object is well-defined by its scope.

Performance: Stack allocations and deallocations are typically faster than heap allocations because they involve 
just moving the stack pointer. This can make a difference in performance-critical applications.

Predictable Lifetime: The lifetime of a stack variable is bound by its scope, making it easier to reason 
about its existence and destruction.

Less Overhead: Heap memory management involves additional overhead for keeping track of allocated and 
free blocks. Stack memory doesn't have this overhead.

Safety: Because of its predictable lifetime and automatic management, there's less room for errors like memory 
leaks or dangling pointers.

///When to Use Stack Memory:
For short-lived variables.
When you know the size of the data at compile time.
For function local variables.
When you want to avoid manual memory management.

///Heap Memory:
Dynamic Memory Allocation: Heap allows for dynamic memory allocation, which means allocating memory during runtime. 
This is useful when the size of the data is not known in advance.
Variable Lifetime: Objects in the heap remain alive until they're explicitly deleted, allowing for more flexible and longer lifetimes.
Larger Memory Blocks: The stack has size limitations, which can vary depending on the system and compiler settings. If 
you need large arrays or buffers, the heap is usually a better choice.
Data Sharing Across Function Calls: Since heap-allocated data persists beyond function calls, it's useful when you want 
to create data in one function and use it in another without copying.

/// When to Use Heap Memory:
When you need data to outlive the function call that created it.
For large data structures that might exceed stack limits.
When the exact amount of required memory isn't known at compile time (e.g., user input determines size).
For data structures that grow and shrink dynamically (like vectors, lists, and other containers).
In Summary:
The choice between stack and heap should be based on the specific requirements of your program. If the size of the data is known in advance, and it's short-lived, stack allocation is usually preferred. However, for dynamic and long-lived data, or when dealing with large amounts of data, heap allocation is more appropriate. Always be cautious with heap memory to avoid memory leaks and remember to delete what you new. */
