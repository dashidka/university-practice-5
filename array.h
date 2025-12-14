#pragma once
#include "iostream"
#include "string"

using namespace std;

class Array
{
	string* array = new string[2];
	int size = 0;
	int capacity = 2;
public:
	Array();
	void push(string el);
	void pop();
	void insert(int index, string el);
	void erase(int index);
	string get(int index);
	int getSize();
	void print();
private:
	int changeCapacity();
};

