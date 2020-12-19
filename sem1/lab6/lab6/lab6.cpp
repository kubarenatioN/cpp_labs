#include <iostream>
#include <iomanip>
using namespace std;
void main()
{
	setlocale(0, "rus");
	float c = 2.1, r = 4E-4, j, h, y;
	int i;
	for (i = 0; i < 4; i++) {
		printf("Введите значение j: ");
		scanf_s("%f", &j);
		float m = 1;
		while (m < 2.1) {
			h = (10 * r - j) / (pow(c, 2) + exp(-m));
			y = (h * m - j * j) + pow(0.1 * c, 2);
			printf("m = %.1f\n", m);
			printf("h = %f\n", h);
			printf("y = %f\n", y);
			m += 0.5;
		}
	}
	
	/*int n, i, j;
	printf("Enter n: ");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%5d", i * j);
			if (i == 1) {
				cout << endl;
				cout << setw(10) << setfill('-') << '-' << endl;
			}
			printf("\n");
		}
	}*/
}

