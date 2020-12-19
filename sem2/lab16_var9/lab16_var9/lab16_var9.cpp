#include <iostream>
#include <ctime>
using namespace std;

void BubbleSort(int A[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {
		for (j = n - 1; j >= i; j--) {
			if (A[j - 1] > A[j]) {
				temp = A[j - 1];
				A[j - 1] = A[j];
				A[j] = temp;
			}
		}
	}
}

void qs(int *A, int first, int last) {
	int i = first, j = last, x = A[(first + last) / 2];

	do {
		while (A[i] < x) i++;
		while (A[j] > x) j--;

		if (i <= j) {
			if (A[i] > A[j]) swap(A[i], A[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		qs(A, i, last);
	if (first < j)
		qs(A, first, j);
}

void main() {
	setlocale(0, "rus");
	srand(time(0));
	int *A, *B, *C, mA, mB = 0;
	int time_s, time_e;
	cout << "Введите размер массива A: ";
	cin >> mA;
	A = new int[mA];
	B = new int[mA];
	C = new int[mA];
	for (int i = 0; i < mA; i++) {
		*(A + i) = rand() % 200;
	}
	cout << "Массив A:\n";
	/*for (int i = 0; i < mA; i++) {
		cout << A[i] << " ";
	}*/
	cout << '\n';
	time_s = clock();
	for (int i = 1; i < mA; i+=2) {
		if (A[i+1] % 2 == 1) {
			B[mB] = A[i];
			mB++;
		}
	}
	time_e = clock();
	mB = 0;
	for (int i = 1; i < mA; i += 2) {
		if (A[i + 1] % 2 == 1) {
			C[mB] = A[i];
			mB++;
		}
	}
	cout << "Массив B:\n";
	/*for (int i = 0; i < mB; i++) {
		cout << B[i] << " ";
	}*/
	cout << endl;
	cout << endl << "Времени на фильтрацию: " << time_e - time_s << endl;

	time_s = clock();
	BubbleSort(B, mB);
	time_e = clock();
	cout << "Сортировка пузырёк: \n";
	/*for (int i = 0; i < mB; i++) {
		cout << B[i] << " ";
	}*/
	cout << endl << "Сортировка пузырёк: " << time_e - time_s << endl;
	for (int i = 0; i < mB; i++) {//Делаем B снова не отсортированным
		B[i] = C[i];
	}
	cout << endl;

	time_s = clock();
	qs(B, 0, mB - 1);
	time_e = clock();

	cout << "Сортировка Хоара: \n";
	/*for (int i = 0; i < mB; i++) {
		cout << B[i] << " ";
	}*/
	cout << endl << "Сортировка Хоара: " << time_e - time_s << endl;
	delete A;
	delete B;
	delete C;
}