#include "stack.h"
#include "list.h"

Stack::Stack() {

}

void Stack::push(string el) {
	stack.push_back(el);
}

void Stack::pop() {
	stack.pop_back();
}

string Stack::top() {
	return stack.tail->data;
}

bool Stack::empty() {
	return stack.getSize() == 0;
}