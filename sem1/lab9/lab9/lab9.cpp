#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void main() {
	setlocale(0, "rus");
	float x, a = 1, b = 3, e = 1E-4;
	do {
		x = (a + b) / 2;
		if ((pow(x, 3) + x - 3)*(pow(a, 3) + a - 3) < 0) {
			b = x;
		}
		else {
			a = x;
		}
	} while (abs(a - b) > 2 * e);
	cout <<"x = "<< setprecision(6) << x;
	/*float x, s, S, s1 = 0, s2 = 0, h, n = 200, x1, x2, a = 1, b = 3;
	h = (b - a) / 2 / n;
	s = (b - a) / 6 * (pow(a, 3) - 3 + 4*(pow((a + b) / 2, 3) - 3) + pow(b, 3) - 3);
	cout << s;*/

	/*x1 = a + 2*h;
	x2 = a + 2 * h;
	for (int i = 1; i < n; i++) {
		s1 = s1 + pow(x1, 3) - 3;
		x1 = x1 + 2 * h;
	}
	for (int i = 1; i < n ; i++) {
		s2 = s2 + pow(x2, 3) - 3;
		x2 = x2 + 2 * h;
	}
	s = pow(a, 3) - 3 + 4 * s1 + 2 * s2 + pow(b, 3) - 3;
	S = h * s / 3;
	cout << S;*/
}

