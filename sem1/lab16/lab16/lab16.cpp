#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
void change(int **A, int n, int m) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(*(A + i) + j) = rand() % 20 - 15;
		}
	}
	cout << "Начальная матрица:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(2) << *(*(A + i) + j) << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < m; j++) {
			if (*(*(A + i) + j) < 0) {
				*(*(A + i) + j) *= -1;
			}
		}
	}
	
}
void up(char *str) {
	int i = 0, len = 0;
	while (*(str + i) != '\0') {
		len += 1;
		i++;
	}
	for (int i = 0; i < len; i++) {
		if (*(str + i) >= 'A' && *(str + i) <= 'Z') {
			*(str + i) = *(str + i) - 'A' + 'a';
		}
	}
	if (*str >= 'a' && *str <= 'z') {
		*str = *str + 'A' - 'a' ;
	}
	for (int i = 0; i < len; i++) {
		if (*(str + i) == ' ' || *(str + i) == '.') {
			if (*(str + i + 1) >= 'a' && *(str + i + 1) <= 'z') {
				*(str + i + 1) = *(str + i + 1) + 'A' - 'a';
			}
		}
	}
	cout << str << endl;
}
void main() {
	setlocale(0, "rus");
	int n, m, choice, stop = 3, **A;
	char *s;
	while (stop == 3) {
		cout << "Выберите действие: " << endl;
		cout << "1 - Задача с матрицей." << endl;
		cout << "2 - Задача со строкой." << endl;
		cin >> choice;
		switch (choice) {
		case 1: cout << "Введите количество строк матрицы: ";
				cin >> n;
				cout << "Введите количество столбцов матрицы: ";
				cin >> m;
				A = new int *[n];
				for (int i = 0; i < n; i++) {
					*(A + i) = new int[m];
				}
				change(A, n, m);
				cout << "Новая матрица:" << endl;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						cout << setw(2) << *(*(A + i) + j) << " ";
					}
					cout << endl;
				}
				for (int i = 0; i < n; i++) {
					delete[] * (A + i);
				}
				delete[] A;
				break;
		case 2: cout << "Введите строку: " << endl;
				cin.ignore(cin.rdbuf()->in_avail());
				/*gets_s(s);
				up(s);*/
				s = new char[51];
				cin.getline(s, 51);
				up(s);
				delete[] s;
				break;
		}
		cout << "Желаете продолжить?" << endl;
		cout << "Да - нажмите 3" << endl;
		cout << "Нет - нажмите 4" << endl;
		cin >> stop;
	}
}