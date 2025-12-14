#pragma once
#include "iostream"
#include "string.h"

using namespace std;

class Node {
public:
	string data;
	Node* prev, *next;

public:
	Node(string data) {
		this->data = data;
		this->prev = this->next = NULL;
	}
};

class List
{
public:
	Node* head, *tail;
public:
	List() {
		this->head = this->tail = NULL;
	}
	Node* push_front(string el);
	Node* push_back(string el);
	void pop_front();
	void pop_back();
	Node* getAt(int index);
	Node* insert(int index, string el);
	void erase(int index);
	void print();
	int getSize();
};

