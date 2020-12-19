#include <iostream>
#include <iomanip>
using namespace std;
void main()
{
	setlocale(0, "rus");
	/*int n = 5, i;
	float d = 12.5E-4, a, h = 0;
	for (i = 1; i < (n + 1); i++) {
		cout << "Введите a" << i << " ";
		cin >> a;
		h = h + pow(a, 2);
	}
	h += d;
	cout << "h = " << setprecision(10) << h;*/
	/*float x, z, y, max = 0, s = 0;
	int n = 5, i;
	for (i = 1; i < (n + 1); i++) {
		cout << "Введите x" << i << " ";
		cin >> x;
		if (x > max) {
			max = x;
		}
		s += pow(x, 2);
	}
	z = max;
	y = z * s;
	cout << "max = " << z << endl;
	cout << "s = " << s << endl;
	cout << "y = " << y;*/
	float t = 0.45, x, q = 0;
	for (int i = 1; i < 7; i++) {
		cout << "Введите x" << i << ": "; cin >> x;
		q = q + (x + 1) / x;
	}
	q = q + t;
	cout << "q = " << q;
}