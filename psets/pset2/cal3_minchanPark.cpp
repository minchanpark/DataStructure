//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: minchanPark Student Number: 21800270

#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int add(int a, int b){return a+b;}
int mul(int a, int b){return a*b;}
int sub(int a, int b){return a-b;}
int dvd(int a, int b){if(b!=0) return a/b; else return 0;}

char get_op( map<char, int(*)(int, int)> fp_map){
    string opstr;
    char op;
    for(auto x: fp_map) opstr+=x.first;
    do{
        stringstream ss;
        string str;
        cout<<"Enter an operator( "<<opstr<<" ): ";
        getline(cin, str);
        ss << str;
        ss >> op;
        if(fp_map.find(op) != fp_map.end()) break;
    } while (true);
    return op;
}

int get_int(){
    int x;
    do{
        cout<<"Enter an integer: ";
        string str;
        getline(cin, str);
        try{
            x=stoi(str);
            break;
        }
        catch(invalid_argument& e){
            cerr<<e.what()<<" error occured. Retry~"<< endl;
        }
    }while(true);
    return x;
}

int main(){

    map<char, int(*)(int, int)> fp_map{ 
        make_pair('+', add), make_pair('-', sub), make_pair('*', mul), make_pair('/', dvd),
    };

    int a{get_int()};
    char op{get_op(fp_map)};
    int b{get_int()};

    cout<<a<<" "<<op<<" "<<b<<" = "<<fp_map[op](a, b)<<endl;

    return 0;
}