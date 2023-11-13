//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [minchan Park] Student Number: [21800270]

#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct Stack {
    T *item;
    int N;
    int capacity;
};

template<typename T>
using stack = Stack<T> *;

template<typename T>
stack<T> newStack(int capacity) {
    stack<T> s = new Stack<T>;
    s->item = new T[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}

template<typename T>
void free(stack<T> s) {
    delete[] s->item;
    delete s;
}

template<typename T>
int size(stack<T> s) { return s->N; }

template<typename T>
bool empty(stack<T> s) { return s->N == 0; }

template<typename T>
void pop(stack<T> s) { s->N--; }

template<typename T>
T top(stack<T> s) {
    return s->item[s->N - 1];
}

template<typename T>
void push(stack<T> s, T item) {
    s->item[s->N++] = item;
}

template<typename T>
void printStack(stack<T> s) {
    stack<T> t=newStack<T>(14);
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

template<typename T>
void printStack_fromBottom(stack<T> s){
    stack<T> t = newStack<T>(14);
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
    //string list[]={"to", "be", "or", "not", "to", "-", "be", \
                    "-", "-", "that", "-", "-", "-", "is"};
    int list[]={1,2,3,4,5,0,6,0,0,7,0,0,0,8};

    stack<int> s = newStack<int>(14);
    for(auto item : list){
        if(item != 0){
            push(s, item);
        }
        else{
            cout<<top(s)<<' ';
            pop(s);
        }
    }
    cout<<"\nsize: "<<size(s);
    cout<<"\ntop: "<<top(s);
    cout<<"\nThe stack is: "; printStack(s);
    cout<<"Happy Coding^^\n"<<endl;
    cout<<"The stack from bottom is: "; printStack_fromBottom(s);
    cout<<"Happy Coding~~";
}