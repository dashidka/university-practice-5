#pragma once
#include "List.h"
#include "string"


class Stack
{
	List stack;
public:
	Stack();
	void push(string el);
	void pop();
	string top();
	bool empty();
};

