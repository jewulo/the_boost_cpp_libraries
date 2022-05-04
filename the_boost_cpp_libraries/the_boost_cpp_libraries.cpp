// the_boost_cpp_libraries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// https://theboostcpplibraries.com/


#include <iostream>

#include "p1_raii_memmagr.h"

int main()
{
	raii_mm::smart_pointers::sole_ownership::scoped_ptr();
	raii_mm::smart_pointers::sole_ownership::scoped_array();

	raii_mm::smart_pointers::shared_ownership::shared_ptr();
	raii_mm::smart_pointers::shared_ownership::custom_deleter();
	raii_mm::smart_pointers::shared_ownership::make_shared();
	raii_mm::smart_pointers::shared_ownership::shared_array();

	raii_mm::smart_pointers::special_smart_pointers::weak::weak_ptr();


	std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
