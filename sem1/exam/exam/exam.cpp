//#include <iostream>
//#include <ctime>
//#include <iomanip>
//using namespace std;
//
//int formir(int **a, int rows, int cols) {
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			a[i][j] = rand() % 200;
//		}
//	}
//	return **a;
//}
//
//void main() {
//	setlocale(0, "rus");
//	srand(time(0));
//	int **A, n, m;
//	cout << "Введите количество строк матрицы: ";
//	cin >> n;
//	cout << "Введите количество столбцов матрицы: ";
//	cin >> m;
//
//	A = new int*[n];
//	for (int i = 0; i < n; i++) {
//		*(A + i) = new int[m];
//	}
//
//	formir(A, n, m);
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << setw(5) << *(*(A + i) + j);
//		}
//		cout << endl;
//	}
//
//	for (int i = 0; i < n; i++) {
//		delete A[i];
//	}
//	delete[] A;
//}
//
//#include <iostream>
//#include <ctime>
//#include <iomanip>
//using namespace std;
//
//void increase(int **A, int n, int m) {
//	int **B = new int *[n];
//	for (int i = 0; i < n; i++) {
//		*(B + i) = new int[m];
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			*(*(B + i) + j) = *(*(A + i) + j) + 1;
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << setw(3) << *(*(B + i) + j);
//		}
//		cout << endl;
//	}
//}
//
//void main() {
//	setlocale(0, "rus");
//	srand(time(0));
//	int **A, n, m;
//	cout << "Введите количество строк матрицы: ";
//	cin >> n;
//	cout << "Введите количество столбцов матрицы: ";
//	cin >> m;
//	A = new int *[n];
//	for (int i = 0; i < n; i++) {
//		*(A + i) = new int[m];
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			*(*(A + i) + j) = rand() % 20;
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << setw(3) << *(*(A + i) + j);
//		}
//		cout << endl;
//	}
//	cout << endl;
//	increase(A, n, m);	
//}

//#include <iostream>
//#include <ctime>
//using namespace std;
//
//int *func(int *A, int m) {
//	int j, *pm;
//	for (int j = 0; j < m; j++) {
//		*(A + j) = rand() % 10;
//	}
//	for (j = 1, pm = A; j < m; j++) {
//		if (*(A + j) > *pm) {
//			pm = &*(A + j);
//		}
//	}
//	return pm;
//}
//
//void main() {
//	setlocale(0, "rus");
//	srand(time(0));
//	int *A, m, max;
//	cout << "Введите количество элементов массива: ";
//	cin >> m;
//	A = new int[m];
//	max = *func(A, m);
//	for (int j = 0; j < m; j++) {
//		cout << *(A + j) << " ";
//	}
//	cout << endl << max;
//}

//Ввести вещественные числа в массив А[n, m](n, m > 0) и ко всем числам каждой строки  прибавить единицу.
//Если первый элемент строки нулевой, ничего не делать.

//#include <iostream>
//#include <ctime>
//#include <iomanip>
//using namespace std;

//int matrix(int **A, int n, int m) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			*(*(A + i) + j) = rand() % 10 - 5;
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << setw(3) << setprecision(3) << *(*(A + i) + j);
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (*(*(A + i) + 0) == 0) {
//				break;
//			}
//			else {
//				*(*(A + i) + j) += 1;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << setw(3) << setprecision(3) << *(*(A + i) + j);
//		}
//		cout << endl;
//	}
//	return 0;
//}

//Дана строка.Все русские буквы привести к верхнему регистру, латинские заменить символом « ? ».
//Вывести результат на экран.
//char stroka(char *S) {
//	cin.ignore(cin.rdbuf()->in_avail());
//	cout << "Введите строку: ";
//	cin.getline(S, 51);
//}
//
//void main() {
//	setlocale(0, "rus");
//	srand(time(0));
//	int **A, n, m;
//	char *S;
//	cout << "Введите количество строк матрицы: ";
//	cin >> n;
//	cout << "Введите количество столбцов матрицы: ";
//	cin >> m;
//	A = new int *[n];
//	for (int i = 0; i < n; i++) {
//		*(A + i) = new int[m];
//	}
//	matrix(A, n, m);
//	S = new char[51];
//	stroka(S);
//}

//Все четные элементы целочисленного массива K(n) поместить в массив L(n),
//а нечетные – в массив М(n).Подсчитать количество тех и других.
//#include <iostream>
//#include <ctime>
//using namespace std;
//void main() {
//	setlocale(0, "rus");
//	srand(time(0));
//	int *K, *L, *M, n, k = 0, t;
//	cout << "Введите размер массива K: ";
//	cin >> n;
//	K = new int[n];
//	for (int i = 0; i < n; i++) {
//		*(K + i) = 1 + rand() % 10;
//	}
//	for (int i = 0; i < n; i++) {
//		cout << *(K + i) << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		if (*(K + i) % 2 == 0) {
//			k += 1;
//		}
//	}
//	t = n - k;
//	L = new int[k];
//	M = new int[t];
//	for (int k = 0, i = 0, t = 0; i < n; i++) {
//		if (*(K + i) % 2 == 0) {
//			*(L + k) = *(K + i);
//			k += 1;
//		}
//		else {
//			*(M + t) = *(K + i);
//			t += 1;
//		}
//	}
//	for (int i = 0; i < k; i++) {
//		cout << *(L + i) << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < t; i++) {
//		cout << *(M + i) << " ";
//	}
//}
//
//Задан массив из k чисел.Сдвинуть элементы массива циклически на n позиций вправо.
//#include <iostream>
//#include <ctime>
//using namespace std;
//void main() {
//	setlocale(0, "rus");
//	srand(time(0));
//	int *A, k, n;
//	cout << "Введите размер массива: ";
//	cin >> k;
//	cout << "Введите количество позиций: ";
//	cin >> n;
//	A = new int[k];
//	for (int i = 0; i < k; i++) {
//		*(A + i) = rand() % 10;
//	}
//	for (int i = 0; i < k; i++) {
//		cout << *(A + i) << " ";
//	}
//	for (int i = 0; i < n; i++) {
//		int a = *(A + k - 1);
//		for (int i = k - 1; i > -1; i--) {
//			*(A + i) = *(A + i - 1);
//		}
//		*A = a;
//	}
//	cout << endl;
//	for (int i = 0; i < k; i++) {
//		cout << *(A + i) << " ";
//	}
//}

//Удалить элементы, индексы которых кратны 7.
//Добавить после каждого нечетного элемента массива элемент со значением 4.
//#include <iostream>
//#include <ctime>
//using namespace std;
//void main() {
//	setlocale(0, "rus");
//	srand(time(0));
//	int A[100], n;
//	cout << "Введите размер массива: ";
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		*(A + i) = rand() % 10;
//	}
//	for (int i = 0; i < n; i++) {
//		cout << *(A + i) << " ";
//	}
//	for (int i = 6; i < n; i += 6) {
//		for (int j = i; j < n; j++) {
//			*(A + j) = *(A + j + 1);
//		}
//		n -= 1;
//	}
//	for (int i = 0; i < n; i += 3) {
//		for (int j = n; j > i; j--) {
//			*(A + j) = *(A + j - 1);
//			*(A + j - 1) = 4;
//		}
//		n += 1;
//	}
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		cout << *(A + i) << " ";
//	}
//}


//Anya Belaya
//#include <iostream>
//#include <ctime>
//using namespace std;
//void main() {
//	setlocale(0, "rus");
//	srand(time(0));
//	int A[100][100], n, B[100], p = 1, s = 0;
//	cout << "Введите количество строк: ";
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			*(*(A + i) + j) = rand() % 10 - 1;
//		}
//	}
//	for (int j = 0; j < n; j++) {
//		*(B + j) = 0;
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << *(*(A + i) + j) << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (*(*(A + i) + j) < 0) {
//				*(B + i) += 1;
//			}
//		}
//	}
//	/*for (int i = 0; i < n; i++) {
//		cout << *(B + i) << " ";
//	}
//	cout << endl;*/
//	for (int j = 0; j < n; j++) {
//		if (*(B + j) == 0) {
//			for (int i = 0; i < n; i++) {
//				p *= *(*(A + j) + i);
//			}
//			cout << p << " ";
//			p = 1;
//		}
//	}
//	for (int i = 0, j = 0; i < n, j < n; i++, j++) {
//		s += *(*(A + i) + j);
//	}
//	cout << endl;
//	cout << s;
//}

//Angelya
#include <iostream>
using namespace std;
void main() {
	setlocale(0, "rus");
	int B[100], A[100], C[100], D[100], j = 0, n = 1, N;
	cout << "Введите число: ";
	cin >> N;
	while (N > 0) {
		*(B + j) = N % 10;
		N = N / 10;
		j++;
	}
	/*for (int i = 0; i < j; i++) {
		cout << *(B + i) << " ";
	}
	cout << endl;*/
	for (int i = 0, t = j - 1; i < j, t > -1; i++, t--) {
		*(A + i) = *(B + t);
	}
	for (int i = 0; i < j; i++) {
		cout << *(A + i) << " ";
	}
	cout << endl;
	int k = 0;
	for (int i = 0; i < j; i++) {
		for (int p = 0; p < j; p++) {
			if (i != p && *(A + i) == *(A + p)) {
				n++;
			}
		}
		*(C + k) = *(A + i);
		*(D + k) = n;
		k++;
		n = 1;
	}
	for (int i = 0; i < k; i++) {
		cout << *(C + k) << " " << *(D + k) << endl;
	}
}