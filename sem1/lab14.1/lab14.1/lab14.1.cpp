//#include <iostream>
//#include <ctime>
//void main()
//{
//	setlocale(0, "rus");
//	using namespace std;
//	const int N = 100, M = 100;
//	int i, j, A[N][M], n, m, mx = 20, s = 0, k = 0;
//	float  avr;
//	cout << "Введите количество строк массива: ";
//	cin >> n;
//	cout << "Введите количество столбцов массива: ";
//	cin >> m;
//	srand(time(0));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			A[i][j] = 1 + rand() % mx;
//			cout << A[i][j] << "   ";
//		}
//		cout << endl;
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (A[i][j] > 0) {
//				s += A[i][j];
//				k += 1;
//			}/*
//			cout << A[i][j] << " ";*/
//		}
//		avr = float(s) / k;
//		cout << s << " " << k << " " << avr;
//		cout << endl;
//		k = 0;
//		s = 0;
//	}
//}

//Задана матрица размером nxm и число k.В переменную b поместить значение 0,
//если все элементы k - го столбца матрицы нулевые, и значение 1 − в противном случае.
#include <iostream>
#include <ctime>
void main()
{
	setlocale(0, "rus");
	using namespace std;
	const int N = 100, M = 100;
	int i, j, A[N][M], n, m, mx = 2, k, b = 0;
	cout << "Введите количество строк массива: ";
	cin >> n;
	cout << "Введите количество столбцов массива: ";
	cin >> m;
	cout << "Введите столбец: ";
	cin >> k;
	srand(time(0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(*(A + i) + j) = rand() % mx;
			cout << A[i][j] << "   ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		if (*(*(A + i) + k - 1) != 0) {
			b++;
		}
	}
	if (b) {
		cout << "b = " << 1;
	}
	else {
		cout << "b = " << 0;
	}
}


//Определить количество различных элементов матрицы
//размером nxm(повторяющиеся элементы счи - тать один раз).

//#include <iostream>
//#include <ctime>
//void main()
//{
//	setlocale(0, "rus");
//	using namespace std;
//	const int N = 100, M = 100;
//	int i, j, A[N][M], B[N], n, m, mx = 10, dim, k = 0;
//	cout << "Введите количество строк массива: ";
//	cin >> n;
//	cout << "Введите количество столбцов массива: ";
//	cin >> m;
//	srand(time(0));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			A[i][j] = 1 + rand() % mx;
//			cout << A[i][j] << "   ";
//		}
//		cout << endl;
//	}
//	dim = n * m;/*
//	cout << "Размерность: " << dim << endl;*/
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			B[k] = A[i][j];
//			k++;
//		}
//	}
//	/*for (int i = 0; i < k; i++) {
//		cout << B[i] << " ";
//	}
//	cout << endl;*/
//	for (int i = 0; i < k; i++) {
//		for (int j = 0; j < k; j++) {
//			if (B[i] == B[j] && i != j) {
//				for (int t = j; t < k; t++) {
//					B[t] = B[t + 1];
//				}
//				k--;
//			}
//		}
//	}
//	/*for (int i = 0; i < k; i++) {
//		cout << B[i] << " ";
//	}*/
//	cout << endl << "Количество различных элементов матрицы равно " << k << endl;
//}