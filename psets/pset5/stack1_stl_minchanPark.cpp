//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [minchan Park] Student Number: [21800270]

#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*void printStack(stack<int> s){
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
}*/

void printStack(stack<int> s){
    if(s.empty()){return;}

    int topElement = s.top();
    cout << topElement << ' ';
    s.pop();

    printStack(s);

    s.push(topElement);
}

/*void printStack_fromBottom(stack<int> s){
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
}*/

void printStack_fromBottom(stack<int> s){
    if(s.empty()){return;}

    int topElement = s.top();
    s.pop();

    printStack_fromBottom(s);

    s.push(topElement);

    cout << topElement << ' ';
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