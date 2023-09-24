//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박민찬] Student Number: [21800270]

#include <iostream>
#include <string>

int main() {
 
 while(true){
    std::string str;
    std::cout << "Enter a name: ";
    std::getline(std::cin, str);

    if(str.empty()){
        break;
    }

    std::cout << "Hello " << str << "!" << std::endl;
 }
 std::cout << "Hello World!\n";
 
 return EXIT_SUCCESS;
}