#include "list.h"
#include "string.h"
#include "iostream";

using namespace std;

Node* List::push_front(string el) {
	Node* ptr = new Node(el);
	ptr->next = head;
	if (head != NULL) {
		head->prev = ptr;
	}
	if (tail == NULL) {
		tail = ptr;
	}
	head = ptr;
	return ptr;
}

Node* List::push_back(string el) {
	Node* ptr = new Node(el);
	ptr->prev = tail;
	if (tail != NULL) {
		tail->next = ptr;
	}
	if (head == NULL) {
		head = ptr;
	}
	tail = ptr;
	return ptr;
}

void List::pop_front() {
	if (head == NULL) {
		return;
	}
	Node* ptr = head->next;
	if (ptr != NULL) {
		ptr->prev = NULL;
	}
	else {
		tail = NULL;
	}
	delete head;
	head = ptr;
}

void List::pop_back() {
	if (tail == NULL) {
		return;
	}
	Node* ptr = tail->prev;
	if (ptr != NULL) {
		ptr->next = NULL;
	}
	else {
		head = NULL;
	}
	delete tail;
	tail = ptr;
}

Node* List::getAt(int index) {
	Node* ptr = head;
	for (int i = 0; i < index; i++)
	{
		if (ptr->next == NULL) return ptr;
		ptr = ptr->next;
	}
	return ptr;
}

int List::getSize() {
	int count = 0;
	Node* ptr = head;
	while (ptr != nullptr) {
		count++;
		ptr = ptr->next;
	}
	return count;
}

Node* List::insert(int index, string el) {
	Node* right = getAt(index);
	if (right == NULL) return push_back(el);
	Node* left = right->prev;
	if (left == NULL) return push_front(el);

	Node* ptr = new Node(el);
	right->prev = ptr;
	left->next = ptr;
	ptr->prev = left;
	ptr->next = right;

	return ptr;
}

void List::erase(int index) {
	Node* ptr = getAt(index);
	if (ptr == NULL) return;

	if (ptr->prev == NULL) {
		pop_front();
		return;
	}
	if (ptr->next == NULL) {
		pop_back();
		return;
	}
	Node* left = ptr->prev;
	Node* right = ptr->next;
	left->next = right;
	right->prev = left;

	delete ptr;
}

void List::print() {
	for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
		cout << ptr->data << " ";
	}
}