#include <iostream>
using namespace std;

int bunnyEars(int n){
    cout<<n<<endl;
    if(n>0){
        return bunnyEars(n-1)+2; 
    }
    return 0; 
}

int main(){
    cout<<bunnyEars(4)<<endl;
}