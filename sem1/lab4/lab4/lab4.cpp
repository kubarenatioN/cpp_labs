#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	setlocale(0, "rus");
	char c, probel;
	probel = ' ';
	cout << "Введите символ: "; cin >> c;
	cout << setw(16) << setfill(probel) << probel;
	cout << setw(5) << setfill(c) << c << endl;

	cout << setw(12) << setfill(probel) << probel;
	cout << setw(9) << setfill(c) << c << endl;

	cout << setw(9) << setfill(probel) << probel;
	cout << setw(12) << setfill(c) << c << endl;

	cout << setw(8) << setfill(probel) << probel;
	cout << setw(13) << setfill(c) << c << endl;

	cout << setw(7) << setfill(probel) << probel;
	cout << setw(14) << setfill(c) << c << endl;

	cout << setw(7) << setfill(probel) << probel;
	cout << setw(14) << setfill(c) << c << endl;

	cout << setw(7) << setfill(probel) << probel;
	cout << setw(14) << setfill(c) << c << endl;

	cout << setw(7) << setfill(probel) << probel;
	cout << setw(14) << setfill(c) << c << endl;

	cout << setw(8) << setfill(probel) << probel;
	cout << setw(13) << setfill(c) << c << endl;

	cout << setw(9) << setfill(probel) << probel;
	cout << setw(12) << setfill(c) << c << endl;

	cout << setw(12) << setfill(probel) << probel;
	cout << setw(9) << setfill(c) << c << endl;

	cout << setw(16) << setfill(probel) << probel;
	cout << setw(5) << setfill(c) << c << endl;

	float d, s;

	printf("Диагональ квадрата равна: ");
	scanf_s("%f", &d);
	
	s = pow(d, 2) / 2;

	printf("Площадь квадрата равна %.2f", s);
}
