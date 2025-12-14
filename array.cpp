#include "iostream";
#include "array.h"

using namespace std;

Array::Array() {

}

int Array::changeCapacity() {
	int newCap = capacity * 2;
	string* newArray = new string[newCap];
	
	for (int i = 0; i < size; i++)
	{
		newArray[i] = array[i];
	}
	delete[] array;

	array = newArray;
	capacity = newCap;

	return 	capacity = newCap;
}

void Array::push(string el) {
	if (size == capacity) {
		changeCapacity();
	}
	array[size++] = el;
}

void Array::pop() {
	size--;
}

string Array::get(int index) {
	if (index < size) return array[index];
	return "";
}

void Array::insert(int index, string el) {
	if (size == capacity) {
		changeCapacity();
	}
	for (int i = size; i > index; i--)
	{
		array[i] = array[i-1];
	}
	size++;
	array[index] = el;
}

void Array::erase(int index) {
	size--;
	for (int i = index; i < size; i++)
	{
		array[i] = array[i + 1];
	}
}

int Array::getSize() {
	return size;
}

void Array::print() {
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}