#include <iostream>

using namespace std;

int factorial(int n){
    if(n<=1) return 1;
    return n*factorial(n-1);    //4!을 계산한다고 하면, 3!*4-->2!*3*4-->1!*2*3*4: 이런 식으로 그 아래 팩토리얼을 사용해야하니까
                                //recursion을 사용하는 것이다. 
}

int main(){
    cout<<factorial(4);
}