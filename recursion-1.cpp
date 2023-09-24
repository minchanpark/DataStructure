#include <iostream>

using namespace std;

int funnyEars(int n){
    if(n<=0) return 0;
    if(n%2==0){                     //짝수인 경우
        return funnyEars(n-1)+3;
    }
    return funnyEars(n-1)+2;        //홀수인 경우
}

int main(){
    int funnies[]={0,1,2,3,4,10,11};
    for(auto n: funnies){
        cout<<funnyEars(n)<<endl;
    }
}