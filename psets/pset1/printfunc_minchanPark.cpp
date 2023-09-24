//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박민찬] Student Number: [21800270]

#include <iostream>

void printfunc(int n, char *names[]) {
    for (int i = 0; i < n; i++){
    std::cout << "Hello " << names[i] << "!" << std::endl;
    }

    std::cout << "Hello World!";
}