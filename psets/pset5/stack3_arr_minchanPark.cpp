//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [minchan Park] Student Number: [21800270]

#include <iostream>
#include <string>

using namespace std;

struct Stack {
    string* item;
    int N;
    int capacity;
};

using stack = Stack *;

stack newStack(int capacity = 1) {
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

void resize(stack s, int new_capacity) {
    string* copied = new string[new_capacity];
    for (int i = 0; i < s->N; i++)
        copied[i] = s->item[i];
    delete[] s->item;
    s->item = copied;
    s->capacity = new_capacity;
}

void pop(stack s) {
    s->N--;
    
    if ((s->N < s->capacity / 4) && s->capacity > 1) {
        int newCapacity = s->capacity / 2;
        resize(s, newCapacity);
    }
}

string top(stack s) {
    if (!empty(s))
        return s->item[s->N - 1];
    return "";
}

void push(stack s, string item) {
    
    if (s->N == s->capacity) {
        int newCapacity = s->capacity * 2;
        resize(s, newCapacity);
    }
    s->item[s->N++] = item;
}

void printStack(stack s) {
    stack t=newStack();
    while (!empty(s)) {
        push(t, top(s));
        cout << top(s) << ' ';
        pop(s);
    }
    while(!empty(t)){
        push(s, top(t));
        pop(t);
    }
    cout<<endl;
}

void printStack_fromBottom(stack s) {
    stack t = newStack();
    while (!empty(s)) {
        push(t, top(s));
        pop(s);
    }

    while (!empty(t)) {
        cout << top(t) << ' ';
        pop(t);
    }
    cout<<endl;
}

int main() {
    string list[] = {"to", "be", "or", "not", "to", "-", "be", \
                    "-", "-", "that", "-", "-", "-", "is"};

    stack s = newStack();
    for (auto item : list) {
        if (item != "-") {
            push(s, item);
            cout << "size: " << size(s) << " capa: " << s->capacity << endl;
        }
        else {
            if (!empty(s)) {
                cout << top(s) << ' ';
                pop(s);
            }
        }
    }
    cout << "\nsize: " << size(s);
    cout << "\ntop: " << top(s);
    cout << "\nstack T: "; printStack(s);
    cout << "Happy Coding^^\n" << endl;
    cout << "The stack from bottom is: "; printStack_fromBottom(s);
    cout << "Happy Coding~~";
}
