/*Вычислить s = n + d, где n = 2(1)4, d = 3(2)9.*/

#include <iostream>
using namespace std;
void main() {
	setlocale(0, "rus");
	float s, n, d;
	for (n = 2; n < 5; n++) {
		cout << "n = " << n << endl;
		d = 3;
		while (d < 10) {
			s = n + d;
			cout << s << endl;
			d += 2;
		}
		cout << "" << endl;
	}
}