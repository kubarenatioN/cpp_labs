#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void main() {
	setlocale(0, "rus");
	srand(time(0));
	int **A, **B, **C, n, m, k;
	cout << "Введите количество строк матрицы А ";
	cin >> n;
	cout << "Введите количество столбцов матрицы A ";
	cin >> m;
	cout << "Введите количество столбцов матрицы B ";
	cin >> k;
	A = new int *[n];
	B = new int *[m];
	C = new int *[n];
	for (int i = 0; i < n; i++) {
		*(A + i) = new int[m];
	}
	for (int i = 0; i < m; i++) {
		*(B + i) = new int[k];
	}
	for (int i = 0; i < n; i++) {
		*(C + i) = new int[k];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(*(A + i) + j) = -5 + rand() % 15;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			*(*(B + i) + j) = -5 + rand() % 15;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			*(*(C + i) + j) = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(4) << *(*(A + i) + j);
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cout << setw(4) << *(*(B + i) + j);
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int p = 0; p < k; p++) {
			for (int j = 0; j < m; j++) {
				*(*(C + i) + p) += *(*(A + i) + j)*(*(*(B + j) + p));
			}
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << setw(4) << *(*(C + i) + j);
		}
		cout << endl;
	}
}
