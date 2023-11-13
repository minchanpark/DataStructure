//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [minchan Park] Student Number: [21800270]
// infix.cpp :
//
// The program evaluates a given infix expression which is fully parenthesized.
// It uses Dijkstra's two-stack algorithm. For simplicity of coding, however,
// the expression is to be fully parenthesized.
// For example:
//   ((3 - 1 ) * 5) + 4
//   2 * ((34 - 4) * 2)
//   1 + (((12 * 2) / 4) - 1)
//
// Author: idebtor@gmail.com
//
// returns value of expression after evaluation.

#include <iostream>
#include <cassert>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#if 0    //////////////////////////////////////////////////////////////////////
// set #if 1, if you want to use this stack using vector instead of STL stack.
// a basic stack functinality only provided for pedagogical purpose only.
#include <vector>
template <typename T>
struct stack {
	vector<T> item;

	bool empty() const {
		return item.empty();
	}
	auto size() const {
		return item.size();
	}
	void push(T const& data) {
		item.push_back(data);
	}
	void pop() {
		if (item.empty())
			throw out_of_range("stack<>::pop(): pop stack");
		item.pop_back();
	}
	T top() const {
		if (item.empty())
			throw out_of_range("stack<>::top(): top stack");
		return item.back();
	}
};
#else  /////////////////////////// using STL stack //////////////////////////
#include <stack>
#endif ///////////////////////////////////////////////////////////////////////

template <typename T>
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

	cout << endl;
}

double apply_op(double a, double b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
	cout << "Unsupported operator encountered: " << op << endl;
	return 0;
}

double compute(stack<int>& va_stack, stack<char>& op_stack) {
	double left = va_stack.top(); va_stack.pop();
	double right = va_stack.top(); va_stack.pop();
	char op = op_stack.top(); op_stack.pop();
	double value = apply_op(left, right, op);

	DPRINT(cout << " va/op_stack.pop: " << value << endl;);
	return value;
}

double evaluate(string tokens) {
	DPRINT(cout << ">evaluate: tokens=" << tokens << endl;);
	stack<double> va_stack;              
	stack<char> op_stack;                
	double value = 0;

	for (size_t i = 0; i < tokens.length(); i++) {
		
		if (isspace(tokens[i]) || tokens[i] == '(') continue;
		DPRINT(cout << " tokens[" << i << "]=" << tokens[i] << endl;);

		if (isdigit(tokens[i])) {
			int ivalue = 0;
			while (i < tokens.length() && isdigit(tokens[i])) {
				ivalue = ivalue * 10 + (tokens[i] - '0'); 
			}
			i--;
			va_stack.push(ivalue);
		}
		else if (tokens[i] == ')') { 

			while (!op_stack.empty() && op_stack.top() != '(') {
				double right = va_stack.top();
				va_stack.pop();
				double left = va_stack.top();
				va_stack.pop();
				char op = op_stack.top();
				op_stack.pop();
				double result = apply_op(left, right, op);
				va_stack.push(result);
			}
			if (!op_stack.empty() && op_stack.top() == '(') {
				op_stack.pop(); 
			}
		}
		else { 
			op_stack.push(tokens[i]);
		}
	}

	DPRINT(cout << "tokens exhausted: now, check two stacks:" << endl;);
	DPRINT(printStack(va_stack);  cout << endl;);
	DPRINT(printStack(op_stack);  cout << endl;);

	while (!op_stack.empty()) {
		char op = op_stack.top();
		op_stack.pop();

		double right = va_stack.top();
		va_stack.pop();

		double left = va_stack.top();
		va_stack.pop();

		double result = apply_op(left, right, op);
		va_stack.push(result);
	}

	assert(va_stack.size() == 1);
	value = va_stack.top();

	DPRINT(cout << "post-conditions" << endl;);
	DPRINT(printStack(va_stack); cout << endl;);

	return value;
}