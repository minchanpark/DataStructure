#include <iostream>

using namespace std;

void foo(int n){
    if(n<1){return ;}
    cout<<n<<" ";
    foo(n-1);
    cout<<n<<" ";
    return;
}

int main(){
    int x=3;
    foo(x);
}