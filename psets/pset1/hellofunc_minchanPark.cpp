//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박민찬] Student Number: [21800270]

#include <iostream>
#include <string>
#include <vector>

void printfunc(int n, char *names[]);

int main(int argc, char *argv[]) {
 
    if(argc!=1){
        printfunc(argc-1, &argv[1]);
    }

    else if(argc==1){
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
}
