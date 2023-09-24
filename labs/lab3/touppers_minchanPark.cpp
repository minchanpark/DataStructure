//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박민찬] Student Number: [21800270]
#include <iostream>
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////////////
// Define void touppers() that converts an input arguments into all uppercases
// Use C++ reference and a for loop.

void touppers(string& str){
    for(int i=1; i<=str.length(); i++){
        if('a'<=str[i]&&str[i]<='z'){
            str[i]=str[i]-32;
        }
    }
}

///////////////////// your code above ////////////////////////////////////////
int main() {
    string str;
    cout << "Enter words: ";
    getline(cin, str);

    cout << "uncomment the following line and implement touppers() \n";
    touppers(str);

    cout << str << endl;
    return 0;
}