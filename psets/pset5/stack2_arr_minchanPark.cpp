//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [minchan Park] Student Number: [21800270]

#include <iostream>
#include <string>

using namespace std;

struct Stack {
    string *item;
    int N;
    int capacity;
};

using stack = Stack *;

stack newStack(int capacity) {
    stack s = new Stack;
    s->item = new string[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}

void free(stack s) {
    delete[] s->item;
    delete s;
}

int size(stack s) { return s->N; }

bool empty(stack s) { return s->N == 0; }

void pop(stack s) { s->N--; }

string top(stack s) {
    return s->item[s->N - 1];
}

void push(stack s, string item) {
    s->item[s->N++] = item;
}

void printStack(stack s) {
    stack t=newStack(14);
    while (!empty(s)) {
        push(t, top(s));
        cout << top(s) << ' ';
        pop(s);
    }
    while(!empty(t)){
        push(s, top(t));
        pop(t);
    }
    cout << endl;
}

void printStack_fromBottom(stack s){
    stack t = newStack(14);
    while(!empty(s)){
        push(t, top(s));
        pop(s);
    }
    while(!empty(t)){
        cout << top(t) << ' ';
        pop(t);
    }
    cout << endl;
}

int main(){
    string list[]={"to", "be", "or", "not", "to", "-", "be", \
                    "-", "-", "that", "-", "-", "-", "is"};
    stack s = newStack(14);
    for(auto item : list){
        if(item != "-"){
            push(s, item);
        }
        else{
            cout<<top(s)<<' ';
            pop(s);
        }
    }
    cout<<"\nsize: "<<size(s);
    cout<<"\ntop: "<<top(s);
    cout<<"\nstack T: "; printStack(s);
    cout<<"Happy Coding^^\n"<<endl;
    cout<<"The stack from bottom is: "; printStack_fromBottom(s);
    cout<<"Happy Coding~~";
}