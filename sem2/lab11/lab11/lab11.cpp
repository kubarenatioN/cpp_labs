#include <iostream>
using namespace std;

int A(int m, int n) {
	if (m == 0 && n > -1) {
		return n + 1;
	}
	else if (m > 0 && n == 0) {
		return A(m - 1, 1);
	}
	else if (m > 0 && n > 0) {
		return A(m - 1, A(m, n - 1));
	}
}

void main() {
	setlocale(0, "rus");
	int n, m;
	cout << "Введите m: ";  cin >> m;
	cout << "Введите n: ";  cin >> n;
	cout << A(m, n);
}