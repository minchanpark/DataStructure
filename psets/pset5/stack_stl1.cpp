#include <iostream>
#include <string>
#include <stack>

using namespace std;

void printStack(stack<int> s){
    stack<int> t;
    while(!s.empty()){
        cout<<s.top()<<' ';
        t.push(s.top());
        s.pop();
    }
    while (!t.empty())
    {
        s.push(t.top());
        t.pop();
    }
}

void printStack(stack<int> s){
    stack<int> t;
    if(s.empty()){return;}
    
}

void printStack_fromBottom(stack<int> s){
    stack<int> t;
    while(!s.empty()){
        t.push(s.top());
        s.pop();
    }

    while(!t.empty()){
        cout<<t.top()<<' ';
        s.push(t.top());
        t.pop();
    }
}

int main(){
    int list[]={1,2,3,4,5,0,6,0,0,7,0,0,0,8};
    //string list[]={"to", "be", "or", "not", "to", "-", "be", \
                    "-", "-", "that", "-", "-", "-", "is"};
    stack<int> s;
    for(auto item : list){
        if(item != 0){
            s.push(item);
        }
        else{
            cout<<s.top()<<' ';
            s.pop();
        }
    }
    cout<<"\nsize: "<<s.size();
    cout<<"\ntop: "<<s.top();
    cout<<"\nstack T: "; printStack(s);
    cout<<"\nstack B: "; printStack_fromBottom(s);
    cout<<"\nHappy Coding~";
}