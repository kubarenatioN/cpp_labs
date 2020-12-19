#include <iostream>
using namespace std;
void main() {
	setlocale(0, "rus");
	int a, a2;
	char b, b2, str[] = "abcdefgh";
	printf("Введите номер клетки слона: ");
	scanf_s("%d", &a);

	printf("Введите букву клетки слона: ");
	scanf_s("%c", &b);

	printf("Введите номер клетки фигуры: ");
	scanf_s("%d", &a2);

	printf("Введите букву клетки фигуры: ");
	scanf_s("%c", &b2);
	if (a < 1 || a > 8 ) {
		printf("Ошибка.");
	}
	if (a2 < 1 || a2 > 8) {
		printf("Ошибка.");
	}
	if (b != str[0] && b != str[1] && b != str[2] && b != str[3] && b != str[4] && b != str[5] && b != str[6] && b != str[7]) {
		printf("Ошибка");
	}
	if (b2 != str[0] && b2 != str[1] && b2 != str[2] && b2 != str[3] && b2 != str[4] && b2 != str[5] && b2 != str[6] && b2 != str[7]) {
		printf("Ошибка");
	}
	else {
		printf("Все верно");
	}

	/*setlocale(0, "rus");
	int a, b, c, s = 0;
	printf("a = ");
	scanf_s("%d", &a);
	printf("b = ");
	scanf_s("%d", &b);
	printf("c = ");
	scanf_s("%d", &c);
	a % 5 == 0 ? s += a : s += 0;
	b % 5 == 0 ? s += b : s += 0;
	c % 5 == 0 ? s += c : s += 0;
	s == 0 ? printf("Error") : printf("Сумма: %d.", s);*/
}