//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [minchan Park] Student Number: [21800270]

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
struct Stack {
    vector<T> item;
};

template<typename T>
using stack = Stack<T> *;

template<typename T>
void free(stack<T> s){
    delete s;
}

template<typename T>
int size(stack<T> s){
    return s->item.size();
}

template<typename T>
bool empty(stack<T> s){
    return s->item.empty();
}

template<typename T>
void pop(stack<T> s){
    s->item.pop_back();
}

template<typename T>
auto top(stack<T> s){
    if(!s->item.empty()){
        return s->item.back();
    }
    return T();
}

template<typename T>
void push(stack<T> s, T item){
    s->item.push_back(item);
}

template<typename T>
void printStack(stack<T> s){
    stack<T> t=new Stack<T>;
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

template<typename T>
void printStack_fromBottom(stack<T> s){
    stack<T> t=new Stack<T>;
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
    //string list[]={"to", "be", "or", "not", "to", "-", "be", \
                    "-", "-", "that", "-", "-", "-", "is"};
    int list[]={1,2,3,4,5,0,6,0,0,7,0,0,0,8};

    stack<int> s = new Stack<int>;

    for(auto item : list){
        if(item != 0||"-"){
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