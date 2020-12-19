#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

double expr1 (double x) {
	return (2 - pow(x, 2) + x);
}
double expr2 (double x) {
	return (pow(sin(x), 2) + 0.2);
}
void counter(double (*expr)(double), double a, double b, double e) {
	double x;
	do {
		x = (a + b) / 2;
		if (expr(x) * expr(a) < 0) {
			b = x;
		}
		else {
			a = x;
		}
	} while (abs(a - b) > e);
	cout << x;
}

void summ(int n, int *s, int first, ...) {
	*s = 0;
	int *p = &first;
	for (int i = 0; i < n - 1; i += 3) {
		*s += *(p + 1 + i)*(*(p + i) - *(p + 2 + i));
	}
}
void main() {
	setlocale(0, "rus");
	int choice;
	cout << "Задача номер (1 / 2) ... ";
	cin >> choice;
	int sum;
	double a, b, e = 0.001;
	switch (choice) {
	case 2:
		summ(7, &sum, 2, 5, 1, 3, 7, 1);
		cout << sum << endl;
		summ(4, &sum, 2, 5, 1);
		cout << sum << endl;
		summ(10, &sum, 2, 5, 1, 3, 7, 1, 5, 3, 2);
		cout << sum << endl;
		break;
	case 1:
		cout << "Введите a: ";
		cin >> a;
		cout << "Введите b: ";
		cin >> b;
		cout << "Корень первого выражения: " << endl;
		counter(expr1, a, b, e);
		cout << endl << "Корень второго выражения: " << endl;
		counter(expr2, a, b, e);
		break;
	default:
		break;
	}
}