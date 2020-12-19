//В одномерном массиве, состоящем из n вещественных элементов, вычислить количество отрицательных эле - ментов массива и сумму модулей элементов,
//расположенных после минимального по модулю элемента.
//#include <ctime>
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include <iomanip>
//using namespace std;
//void main() {
//	setlocale(0, "rus");
//	int n, k = 0, ind = 0;
//	float s = 0, min = 9999, *A;
//	cout << "Введите размер массива: ";
//	cin >> n;
//	A = (float*)malloc(n * sizeof(float));
//	srand(time(0));
//	for (int i = 0; i < n; i++) {
//		*(A + i) = (rand() % 20 - 5) / float((rand() % 20 - 5));
//	}
//	for (int i = 0; i < n; i++) {
//		cout << setprecision(2) << *(A + i) << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		if (*(A + i) < 0) {
//			/*cout << setprecision(2) << *(A + i) << "  ";*/
//			k++;
//		}
//	}
//	cout << endl << "Количество отрицательных элементов: " << k << endl;
//	for (int i = 0; i < n; i++) {
//		*(A + i) = abs(*(A + i));
//	}
//	/*cout << endl;
//	for (int i = 0; i < n; i++) {
//		cout << setprecision(2) << *(A + i) << " ";
//	}*/
//	for (int i = 0; i < n; i++) {
//		if (*(A + i) < min) {
//			min = *(A + i);
//			ind = i;
//		}
//	}/*
//	cout << endl;*/
//	cout << "Минимальный элемент по модулю: " << setprecision(2) << min;
//	for (int i = ind + 1; i < n; i++) {
//		s += *(A + i)/1.;
//	}
//	cout << endl << "Сумма элементов после минимального: " << setprecision(2) << float(s) << endl;
//	free(A);
//}

//Найти в матрице первый столбец, все элементы которого положительны.
//Знаки элементов предыдущего столбца изменить на противоположные.
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;
void main() {
	setlocale(0, "rus");
	srand(time(0));
	int **A, *B, n, m, colB = 0, ind = 0;
	cout << "Введите количество строк: ";
	cin >> n;
	cout << "Введите количество столбцов: ";
	cin >> m;
	B = new int[m];
	A = new int *[n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[m];
	}
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			*(*(A + row) + col) = -5 + rand() % 15;
		}
	}
	for (int colB = 0; colB < m; colB++) {
		*(B + colB) = 0;
	}
	for (int col = 0; col < m; col++) {
		for (int row = 0; row < n; row++) {
			if (*(*(A + row) + col) > 0) {
				*(B + colB) += 1;
			}
		}
		colB += 1;
	}
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			cout << setw(2) << *(*(A + row) + col) << " ";
		}
		cout << endl;
	}
	/*for (int colB = 0; colB < m; colB++) {
		cout << setw(2) << *(B + colB) << " ";
	}
	cout << endl;*/
	for (int colB = 0; colB < m; colB++) {
		if (*(B + colB) == n) {
			ind = colB + 1;
			break;
		}
	}
	if (ind) {
		cout << "Столбец номер " << ind;
	}
	else {
		cout << "Нет столбцов, все элементы которого положительны.";
	}
	for (int row = 0; row < n; row++) {
		if (*(*(A + row) + ind - 2) < 0) {
			*(*(A + row) + ind - 2) *= -1;
		}
	}
	cout << endl << "Новая матрица: " << endl;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			cout << setw(2) << *(*(A + row) + col) << " ";
		}
		cout << endl;
	}
	for (int row = 0; row < n; row++) {
		delete[] A[row];
	}
	delete[] A;
	delete[] B;
}