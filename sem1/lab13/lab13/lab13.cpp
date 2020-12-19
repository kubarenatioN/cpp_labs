//Написать программу, реализующую вставку в строку n символов,
//начиная с позиции k.

#include <iostream>
using namespace std;
void main() {
	setlocale(0, "rus");
	const int N = 100;
	char s1[N], s;
	int i = 0, n, k, len = 0;
	cout << "Введите строку: ";
	gets_s(s1);
	cout << "Введите символ: ";
	cin >> s;
	cout << "Введите количество символов n: ";
	cin >> n;
	cout << "Введите позицию k: ";
	cin >> k;
	while (s1[i] != 0) {
		len += 1;
		i++;
	}
	for (int j = 0; j < n; j++) {
		for (int i = len; i > k - 1; i--) {
			s1[i] = s1[i - 1];
		}
		s1[k] = s;
		len++;
	}
	for (int i = 0; i < len; i++) {
		cout << s1[i];
	}
}

//Дана строка, состоящая из групп нулей и единиц.Каждая группа отделяется от другой одним
//или несколькими пробелами.Найти количество групп с пятью символами.

//#include <iostream>
//using namespace std;
//void main() {
//	setlocale(0, "rus");
//	const int N = 100;
//	char s1[N];
//	int i = 0, i1 = 0, i2 = 0, n, k = 0, len = 0;
//	cout << "Введите строку: ";
//	gets_s(s1);
//	puts(s1);
//	while (s1[i] != '\0') {
//		len += 1;
//		i++;
//	}/*
//	cout << len << endl;*/
//	for (int i = 0; s1[i] != '\0'; i++) {
//		if (s1[i] == ' ') {
//			i2 = i - 1;/*
//			cout << i2 << endl;*/
//			if ( i2 - i1 == 4) {
//				k += 1;
//			}
//			i1 = i + 1;
//		}
//	}/*
//	cout << i1 << endl;*/
//	if (len - i1 == 5) {
//		k++;
//	}
//	cout << k;
//}

