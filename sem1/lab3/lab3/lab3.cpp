﻿#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	setlocale(0, "rus");
	char c, probel;
	probel = ' ';
	cout << "Введите символ "; cin >> c;
	cout << setw(35) << setfill(probel) << probel;
	cout << setw(10) << setfill(c) << c << endl;
	cout << setw(34) << setfill(probel) << probel;
	cout << setw(12) << setfill(c) << c << endl;
	cout << setw(33) << setfill(probel) << probel;
	cout << setw(14) << setfill(c) << c << endl;
}