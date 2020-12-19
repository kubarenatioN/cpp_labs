//#include <iostream>
//using namespace std;
//void main() {
//	setlocale(0, "rus");
//	char tmp[33];
//	int A, /*maskA = 1, cutA,*/ B = 1, n = 0;
//	cout << "Введите число А: ";
//	cin >> A;
//	_itoa_s(A, tmp, 2);
//	cout << "А в двоичной системе счисления: " << endl;
//	cout << tmp;
//	A = A >> 2;
//	/*maskA = maskA << 11;
//	maskA = maskA - 1;
//	_itoa_s(maskA, tmp, 2);
//	cout << endl;
//	cout << "maskА: " << endl;
//	cout << tmp;
//	cutA = A & maskA;
//	_itoa_s(cutA, tmp, 2);
//	cout << endl;
//	cout << "cutА: " << endl;
//	cout << tmp;*/
//	for (int i = 0; i < 11; i++) {
//		if ((A & B) == 0) {
//			n += 1;
//		}
//		A = A >> 1;
//	}
//	cout << endl << "Количество нулей с 3 по 13 включительно равно " << n << endl;
//}
#include <iostream>
using namespace std;
void main() {
	setlocale(0, "rus");
	char tmp[33];
	int A, B, n, p, m, q, maskA = 1, maskB = 1, Ainv, Binv, cutA, cutB;
	cout << "Введите число А: "; cin >> A;
	cout << "Введите число B: "; cin >> B;
	cout << "Введите n: "; cin >> n;
	cout << "Введите p: "; cin >> p;
	cout << "Введите q: "; cin >> q;
	_itoa_s(A, tmp, 2);
	cout << "А в двоичной системе счисления: " << endl;
	cout << tmp << endl;
	maskA = maskA << n;
	maskA = maskA - 1;
	maskA = maskA << p-n;
	_itoa_s(maskA, tmp, 2);
	//cout << "Маска А: " << endl;
	//cout << tmp << endl;
	cutA = (A & maskA) >> p - n;
	/*_itoa_s(cutA, tmp, 2);
	cout << "Вырезанная часть А: " << endl;
	cout << tmp << endl;*/
	Ainv = A ^ maskA;
	_itoa_s(Ainv, tmp, 2);
	cout << "Инвертированное А: " << endl;
	cout << tmp << endl;
	_itoa_s(B, tmp, 2);
	cout << "B в двоичной системе счисления: " << endl;
	cout << tmp << endl;
	maskB = maskB << n;
	maskB = maskB - 1;
	maskB = maskB << q; 
	//q-n
	maskB = ~maskB;
	_itoa_s(maskB, tmp, 2);
	//cout << "Маска B: " << endl;
	//cout << tmp << endl;
	cutB = B & maskB;
	_itoa_s(cutB, tmp, 2);
	//cout << "Очищенные биты в B: " << endl;
	//cout << tmp << endl;
	Binv = (cutA << q) | cutB;
	_itoa_s(Binv, tmp, 2);
	cout << "Измененное B: " << endl;
	cout << tmp << endl;
}