//#include <iostream>
//#include <ctime>
//using namespace std;
//void main()
//{
//	setlocale(0, "rus");
//	int k = 0, a, N, m, A[100], B[100], C[100], i = 0;
//	cout << "Введите N: ";
//	cin >> N;
//	cout << "Введите m: ";
//	cin >> m;
//	do {
//		*(A + i) = N % 10;
//		N = N / 10;
//		i++;
//	} while (N > 0);
//	a = i;
//	for (int j = 0; j < a, i > 0; j++, i--) {
//		*(B + j) = *(A + i - 1);
//	}
//	for (int i = 0; i < a; i++) {
//		if (*(B + i) % m == 0) {
//			*(C + k) = *(B + i);
//			k++;
//		}
//	}
//	for (int i = 0; i < k; i++) {
//		cout << *(C + i) << " ";
//	}
//}
//#include <iostream>
//#include <ctime>
//using namespace std;
//void main() {
//	setlocale(0, "rus");
//	int A[100], B[100], szA = 10, szB = 10,  mx = 20, max;
//	srand(time(0));
//	for (int i = 0; i < szA; i++) {
//		A[i] = 1 + rand() % mx;
//		cout << A[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < szB; i++) {
//		B[i] = 1 + rand() % mx;
//		cout << B[i] << " ";
//	}
//	for (int i = 0; i < szA; i++) {
//		for (int j = 0; j < szB; j++) {
//			if (A[i] == B[j]) {
//				for (int t = i; t < szA; t++) {
//					A[t] = A[t + 1];
//				}
//				szA--;
//				j = 0;
//				i = 0;
//			}
//
//		}
//	}
//	cout << endl;
//	for (int i = 0; i < szA; i++) {
//		cout << A[i] << " ";
//	}
//	max = A[0];
//	for (int i = 1; i < szA; i++) {
//		if (A[i] > max) {
//			max = A[i];
//		}
//	}
//	cout << endl;
//	cout << max;
//}
#include <iostream>
#include <ctime>
using namespace std;
void main() {
	setlocale(0, "rus");
	int A[100], B[100], szA = 10, szB = 10, mx = 20, max;
	srand(time(0));
	for (int i = 0; i < szA; i++) {
		*(A + i) = 1 + rand() % mx;
		cout << *(A + i) << " ";
	}
	cout << endl;
	for (int i = 0; i < szB; i++) {
		*(B + i) = 1 + rand() % mx;
		cout << *(B + i) << " ";
	}
	for (int i = 0; i < szA; i++) {
		for (int j = 0; j < szB; j++) {
			if (*(A + i) == *(B + j)) {
				for (int t = i; t < szA; t++) {
					*(A + t) = *(A + t + 1);
				}
				szA--;
				j = 0;
				i = 0;
			}

		}
	}
	cout << endl;
	for (int i = 0; i < szA; i++) {
		cout << *(A + i) << " ";
	}
	max = *(A + 0);
	for (int i = 1; i < szA; i++) {
		if (*(A + i) > max) {
			max = *(A + i);
		}
	}
	cout << endl;
	cout << max;
}
	