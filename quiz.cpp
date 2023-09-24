#include <iostream>

int& foo(){
    int x=10;
    return x;
}

int main(){
    foo()=20;
    std::cout<<foo();
    return 0;
}