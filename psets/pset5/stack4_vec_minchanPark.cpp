//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [minchan Park] Student Number: [21800270]

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Stack {
    vector<string> item;
};
using stack = Stack *;

void free(stack s){
    delete s;
}

int size(stack s){
    return s->item.size();
}

bool empty(stack s){
    return s->item.empty();
}

void pop(stack s){
    s->item.pop_back();
}

string top(stack s){
    if(!s->item.empty()){
        return s->item.back();
    }
    return "";
}

void push(stack s, string item){
    s->item.push_back(item);
}

void printStack(stack s){
    stack t=new Stack;
    while(!empty(s)){
        cout<<top(s)<<' ';
        push(t, top(s));
        pop(s);
    }
    while(!empty(t)){
        push(s, top(t));
        pop(t);
    }
    cout<<endl;
}

void printStack_fromBottom(stack s){
    stack t;
    while(!empty(s)){
        push(t, top(s));
        pop(s);
    }

    while(!empty(t)){
        cout<<top(t)<<' ';
        push(s, top(t));
        pop(t);
    }
}

int main(){
    string list[]={"to", "be", "or", "not", "to", "-", "be", \
                    "-", "-", "that", "-", "-", "-", "is"};
    stack s = new Stack;

    for(auto item : list){
        if(item != "-"){
            push(s, item);
        }
        else{
            cout<<top(s)<<' ';
            pop(s);
        }
    }
    cout<<"\ns.size:  "<<size(s);
    cout<<"\ns.top: "<<top(s);
    cout<<"\nThe stack is: "; printStack(s);
    cout<<"Happy Coding~\n";
    cout<<"\nThe stack from bottom is: "; printStack_fromBottom(s);
    cout<<"\nHappy Coding~";

    free(s);
}
