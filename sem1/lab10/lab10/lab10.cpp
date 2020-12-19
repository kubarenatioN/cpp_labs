#include <iostream>
#include <ctime>
using namespace std;
void main() {
	setlocale(0, "rus");
	const int N = 100;
	int n = 0, a, i, sz, A[N], mx = 10;
	cout << "Введите размер массива A: "; cin >> sz;
	cout << "Массив A: " << endl;
	srand(time(0));
	for (i = 0; i < sz; i++) {
		A[i] = 1 + rand() % mx;
		cout << A[i] << "  ";
	}
	cout << endl << "Введите значение: "; cin >> a;
	while (n < sz+1) {
		for (int i = 0; i < sz; i++) {
			if (A[i] == a) {
				for (int j = i; j < sz; j++) {
					A[j] = A[j + 1];
				}
				sz--;
			}
		}
		n++;
	}
	cout << "" << endl;
	cout << "Новый массив А: " << endl;
	for (int i = 0; i < sz; i++) {
		cout << A[i] << "  ";
	}
	cout << "" << endl;
	cout << "" << endl;
	cout << "Массив А с добавлением 1: " << endl;
	for (int i = 0; i < sz; i = i + 3) {
		sz += 1;
		for (int j = sz - 1; j > i; j--) {
			A[j] = A[j - 1];
		}
		A[i] = 1;
	}
	for (int i = 0; i < sz; i++) {
		cout << A[i] << "  ";
	}
}
//#include <iostream>
//using namespace std;
//void main() {
//	setlocale(0, "rus");
//	int k;
//	char A[100];
//	char B[100];
//	char C[100];
//	cout << "Введите размер k исходного массива: "; cin >> k;
//	for (int i = 0; i < k; i++) {
//		cin >> A[i];
//	}
//	cout << "Исходный массив: " << endl;
//	for (int i = 0; i < k; i++) {
//		cout << A[i] << "  ";
//	}
//	cout << endl;
//	int j = 0, t = 0;
//	for (int i = 0; i < k; i++) {
//		if (A[i] >= 'a' && A[i] <= 'z' || A[i] >= 'A' && A[i] <= 'Z') {
//			B[j] = A[i];
//			j++;
//		}
//		else {
//			C[t] = A[i];
//			t++;
//		}
//	}
//	cout << "Массив символов: " << endl;
//	for (int i = 0; i < j; i++) {
//		cout << B[i] << "  ";
//	}
//	cout << endl;
//	cout << "Массив цифр: " << endl;
//	for (int i = 0; i < t; i++) {
//		cout << C[i] << "  ";
//	}
//}