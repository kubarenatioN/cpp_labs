//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "lab8Header.h"
using namespace std;

int main(int argc, char **argv)
{
	setlocale(0, "rus");
	int value, n;

	ofstream inFile;
	ifstream fromFile;

	Element *begin = NULL;
	Element *end = begin;
	do {
		Menu();
		cin >> menuChoice;
		switch (menuChoice) {
		case 1:
			cout << "Сколько элементов стека добавить? "; cin >> n;
			for (int i = 0; i < n; i++) {
				cout << "Значение: ";  cin >> value;
				Push(&begin, value);
				numOfElements++;
			}
			break;
		case 2:
			cout << "Сколько элементов стека достать? "; cin >> n;
			if (n < numOfElements + 1) {
				for (int i = 0; i < n; i++) {
					Pop(&begin);
					numOfElements--;
				}
			}
			else {
				cout << "Слишком большое значение.\n";
			}
			break;
		case 3:
			Clear(&begin);
			break;
		case 4:
			inFile.open("file.txt");
			Input(begin, inFile);
			inFile.close();
			break;
		case 5:
			fromFile.open("file.txt");
			Output(&begin, fromFile);
			fromFile.close();
			break;
		case 6:
			Count(begin);
			break;
		default:
			break;
		}
	} while (menuChoice != 0);

	return 0;
}
