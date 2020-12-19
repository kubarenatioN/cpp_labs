#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
void matrix(int n, int m) {
	int **A;
	srand(time(0));
	A = new int *[n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			A[i][j] = rand() % 30;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(2) << A[i][j] << " ";
		}
		cout << endl;
	}
}
void main() {
	setlocale(0, "rus");
	int n, m;
	cout << "Введите количество строк матрицы: ";
	cin >> n;
	cout << "Введите количество столбцов матрицы: ";
	cin >> m;
	matrix(n, m);
}