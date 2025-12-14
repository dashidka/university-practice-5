#include "application.h"
#include "iostream"
#include <sstream>
#include "list.h"
#include "array.h"
#include "stack.h"
#include "sort.h"
#include "number.h"

using namespace std;

Application::Application()
{

}


int Application::exec() {
	int ch;
	Array array;
	List list;
	while (true) {
		system("cls");
		ch = menu();
		switch (ch)
		{
		case 1:
			while (ch != 0) {
				string tmp;
				int index;
				ch = menu_array();
				switch (ch)
				{
				case 1:
					cout << "Input element: ";
					cin >> tmp;
					array.push(tmp);
					break;
				case 2:
					array.pop();
					cout << endl << "Succesful pop";
					break;
				case 3:
					cout << "Input index: ";
					cin >> index;
					cout << endl << "Input element: ";
					cin >> tmp;
					array.insert(index, tmp);
					break;
				case 4:
					cout << "Input index: ";
					cin >> index;
					array.erase(index);
					cout << endl << "Succesful erase";
					break;
				case 5:
					array.print();
					break;
				case 6:
					cout << "Size array = " << array.getSize();
					break;
				}
				cout << "\n\n";
			}
			break;
		case 2:
			while (ch != 0) {
				string tmp;
				int index;
				ch = menu_list();
				switch (ch)
				{
				case 1:
					cout << "Input element: ";
					cin >> tmp;
					list.push_front(tmp);
					break;
				case 2:
					cout << "Input element: ";
					cin >> tmp;
					list.push_back(tmp);
					break;
				case 3:
					list.pop_front();
					cout << endl << "Succesful pop";
					break;
				case 4:
					list.pop_back();
					cout << endl << "Succesful pop";
					break;
				case 5:
					cout << "Input index: ";
					cin >> index;
					cout << "Element: " << list.getAt(index);
					break;
				case 6:
					cout << "Input index: ";
					cin >> index;
					cout << endl << "Input element: ";
					cin >> tmp;
					list.insert(index, tmp);
					break;
				case 7:
					cout << "Input index: ";
					cin >> index;
					list.erase(index);
					cout << endl << "Succesful erase";
					break;
				case 8:
					list.print();
					break;
				}
				cout << "\n\n";
			}
			break;
		case 3:
			while (ch != 0) {
				string infix;
				ch = menu_sort();
				switch (ch)
				{
				case 1:
					cout << "Input infix: ";
					cin.ignore(1000, '\n');
					getline(cin, infix);
					auto tokens = splitBySpaces(infix);
					auto rpn = shuntingYardSimple(tokens);
					cout << "Postfix: ";
					rpn.print();
					break;
				}
				cout << "\n\n";
			}
			break;
		case 0:
			exit(0);
			break;
		default:
			break;
		}
	}
	return 0;
}

int Application::menu() {
	int ch;
	cout << "1) Array" << endl
		<< "2) List" << endl
		<< "3) Sorting station" << endl
		<< "0) Exit" << endl << "> ";
	cin >> ch;
	cout << endl;
	return ch;
}

int Application::menu_array() {
	int ch;
	cout << "1) Push" << endl
		<< "2) Pop" << endl
		<< "3) Insert" << endl
		<< "4) Erase" << endl
		<< "5) Print" << endl
		<< "6) Get size" << endl
		<< "0) Back" << endl << "> ";
	cin >> ch;
	cout << endl;
	return ch;
}

int Application::menu_list() {
	int ch;
	cout << "1) Push on front" << endl
		<< "2) Push on back" << endl
		<< "3) Pop on front" << endl
		<< "4) Pop on back" << endl
		<< "5) Get at" << endl
		<< "6) Insert" << endl
		<< "7) Erase" << endl
		<< "8) Print" << endl
		<< "0) Back" << endl << "> ";
	cin >> ch;
	cout << endl;
	return ch;
}

int Application::menu_sort() {
	int ch;
	cout << "1) Sort (infix -> postfix)" << endl
		<< "0) Back" << endl << "> ";
	cin >> ch;
	cout << endl;
	return ch;
}
