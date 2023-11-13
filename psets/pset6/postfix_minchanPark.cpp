//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [minchan Park] Student Number: [21800270]
#include <iostream>
#include <stack>
#include <string>
#include <cassert>
using namespace std;

template<typename T>
void printStack(stack<T> orig) {
    stack<T> temp;

    while (!orig.empty()) {
        temp.push(orig.top());
        orig.pop();
    }

    while (!temp.empty()) {
        cout << temp.top();
        temp.pop();
    }
}

string evaluate(string tokens) {
    stack<string> st;

    for (char token : tokens) {
        if (isspace(token)) continue; 

        if (token == '+' || token == '-' || token == '*' || token == '/') {
            assert(st.size() >= 2);
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();
            string result = "(" + operand2 + token + operand1 + ")";
            st.push(result);
        }
        else {
            string str(1, token);
            st.push(str);
        }
    }
    string result = st.top();
    cout << "token exhausted: ";
    cout << result << endl;
    return result;
}

bool is_numeric(string tokens) {
    for (char token : tokens) {
        if (!(token == '+' || token == '-' || token == '*' || token == '/' || isdigit(token) || isspace(token))) {
            return false;
        }
    }
    return true;
}

double evaluate_numeric(string tokens) {
    stack<double> st;

    for (char token : tokens) {
        if (isspace(token)) continue;  

        if (token == '+' || token == '-' || token == '*' || token == '/') {
            assert(st.size() >= 2);
            double operand1 = st.top();
            st.pop();
            double operand2 = st.top();
            st.pop();
            double result;

            if (token == '+') {
                result = operand2 + operand1;
            }
            else if (token == '-') {
                result = operand2 - operand1;
            }
            else if (token == '*') {
                result = operand2 * operand1;
            }
            else if (token == '/') {
                result = operand2 / operand1;
            }
            st.push(result);
        }
        else {
           
            double numeric_value = token - '0';
            st.push(numeric_value);
        }
    }
    cout << "token exhausted: check the stack, its size() should be 1.\n";
    printStack(st);

    double result = st.top();
    cout << "<evaluate() returns " << result << endl;
    return result;
}