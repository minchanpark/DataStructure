#include <iostream>
#include <cstdlib>
using namespace std;

void op_print(int (*op)(int, int), int a, int b){
    cout<<"op(): "<<op(a, b)<<endl;
}

int fun(int x, int y){
    return x*2+y;
}

int foo(int x, int y){
    return x+y*2;
}

int add(int x, int y){
    return x+y;
}

int main(){
    int (*fps[])(int, int)={fun, foo, add};

    int n=sizeof(fps)/sizeof(*fps);

    for(int i=0; i<n; i++){
        op_print(fps[i], 2, 3);
    }
}