#include <iostream>
using namespace std;

double expr(double x) {
	return pow(x, 2) + 2 * x - 3;
}

double C(double a, double b) {
	return (a + b) / 2;
}

double dicho(double (*expr)(double), double a, double b, double e) {
	double c;
	if ((b - a) >= 2 * e) {
		c = C(a, b);
		if (expr(a) * expr(c) <= 0) {
			return dicho(expr, a, c, e);
		}
		else {
			return dicho(expr, c, b, e);
		}
	}
	return a;
}

void main() {
	setlocale(0, "rus");
	double a, b;
	double e = 0.001;
	cout << "Введите начало отрезка определения: "; cin >> a;
	cout << "Введите конец отрезка определения: "; cin >> b;

	cout << dicho(expr, a, b, e);
}