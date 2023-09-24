//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박민찬] Student Number: [21800270]

// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// Lab 2:
//	1. Using vector class in c++
//	2. ranged-for loop
//	3. function overloading
//	4. include file
//  5. not using `using namespace std;`

#include <iostream>
#include <vector>
#include "printfunc.h"

void printfunc(int n, char *names[]);
void printfunc(std::vector<std::string> &names);

int main(int argc, char *argv[]) {

	// pass one less of argc and argv. Do not change printfunc()."
	std::cout << "Print using printfunc(**argv) \n";
	printfunc(argc - 1, &argv[1]);

	std::cout << "Copy using vector<string> \n";
	// use push_back() method in the vector class
	std::vector<std::string> names;
	for (int i = 1; i < argc; i++)
		names.push_back(argv[i]);

	// print names only using for-loop and names
	// do not use argc/argv and ranged-for loop
	std::cout << "Print names using indexing, but not ranged-for\n";
	for (size_t i = 0; i < names.size(); i++) 
		std::cout << "Hello " << names[i] << "!" << std::endl;

	// print names using printfunc(vector<string>)
	// use ranged-for loop in printfunc(vector<string>)
	// do not use `using namespace std;` in printfunc.cpp 
	std::cout << "Print names using printfunc(vector<string> n)\n";
	printfunc(names);

	return 0;
}
