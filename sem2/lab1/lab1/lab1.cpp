#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void count(int *A, int n, int &max, int &min, int &sum) {
	for (int i = 0; i < n; i++) {
		if (*(A + i) > max) {
			max = *(A + i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (*(A + i) < min) {
			min = *(A + i);
		}
	}
	sum = max + min;
}

void check(int **B, int n2, int m2) {
	int amount = 0;
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < m2; j++) {
			if (*(*(B + i) + j) == 0) {
				amount++;
				break;
			}
		}
	}
	if (amount != n2) {
		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < m2; j++) {
				if (*(*(B + i) + j) < 0) {
					*(*(B + i) + j) = 0;
				}
			}
		}
		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < m2; j++) {
				cout << setw(4) << *(*(B + i) + j);
			}
			cout << endl;
		}
	}
	else {
		cout << "Все строки матрицы содержат хотя бы 1 нулевой элемент" << endl;
	}
}

void main() {
	setlocale(0, "rus");
	srand(time(0));
	int *A, n, max = -999, min = 999, sum = 0;
	int **B, n2, m2;
	int choice;
	cout << "Задача номер...";
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Введите количество элементов массива: ";
		cin >> n;
		A = new int[n];
		for (int i = 0; i < n; i++) {
			*(A + i) = -20 + rand() % 50;
		}
		for (int i = 0; i < n; i++) {
			cout << *(A + i) << " ";
		}
		cout << endl;
		count(A, n, max, min, sum);
		cout << "максимальный элемент: " << max << endl;
		cout << "минимальный элемент: " << min << endl;
		cout << "их сумма: " << sum << endl;
		delete[] A;
		break;
	case 2:
		cout << "Введите количество строк матрицы ";
		cin >> n2;
		cout << "Введите количество столбцов матрицы ";
		cin >> m2;
		B = new int *[n2];
		for (int i = 0; i < n2; i++) {
			*(B + i) = new int[m2];
		}
		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < m2; j++) {
				*(*(B + i) + j) = -1 + rand() % 5;
			}
		}
		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < m2; j++) {
				cout << setw(4) << *(*(B + i) + j);
			}
			cout << endl;
		}
		cout << endl;
		check(B, n2, m2);
		delete[] B;
		break;
	default:
		break;
	}
}