#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;
void main()
{
	setlocale(0, "rus");
	/*float x, y, z, d;

	printf("Введите x: ");
	scanf_s("%f", &x);
	printf("Введите y: ");
	scanf_s("%f", &y);
	printf("Введите z: ");
	scanf_s("%f", &z);

	if (x >= y) {
		
	}
	else {
		d = x;
		x = y;
		y = d;
	}
	if (y >= z) {

	}
	else {
		d = y;
		y = z;
		z = d;
	}
	if (x >= y) {

	}
	else {
		d = x;
		x = y;
		y = d;
	}

	printf("x = %.0f\n", x);
	printf("y = %.0f\n", y);
	printf("z = %.0f\n", z);

	float m, n, p, t = 0;
	printf("Введите значение m: ");
	scanf_s("%f", &m);
	printf("Введите значение n: ");
	scanf_s("%f", &n);
	printf("Введите значение p: ");
	scanf_s("%f", &p);
	m < 0 ? t++ : t;
	n < 0 ? t++ : t;
	p < 0 ? t++ : t;
	printf("Количество отрицательных чисел равно %.0f", t);*/
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int a, b, b2, b3, c, c2, c3, age, age2;
	char imya[15];
	printf("Здравствуйте! Я компьютер. Как Вас зовут? ");
	scanf_s("%s", &imya, 15);
	printf("Очень рад знакомству, %s!\n", imya);
	printf("Как Ваши дела?\n1 - Отлично\n2 - Нормально\n3 - Плохо\n");
	scanf_s("%d", &a);
	switch (a) {
		case 1: {
			printf("Это просто замечательно!");
			printf("Собираетесь в путешествие в этом году?\n1 - да\n2 - нет\n");
			scanf_s("%d", &b);
			switch (b) {
				case 1: {
					printf("Ого! И куда же???\n1 - Египет\n2 - Франция\n3 - Америка\n");
					scanf_s("%d", &c);
					switch (c) {
						case 1: {
							printf("Отличный выбор! Не забудьте посетить Египетские Пирамиды."); break;
						}
						case 2: {
							printf("Отличный выбор! Не забудьте посетить Эйфелеву Башню."); break;
						}
						case 3: {
							printf("Отличный выбор! Не забудьте посетить Статую Свободы."); break;
						}
					}
					break;
				}
				case 2: {
					printf("Очень жаль, надеюсь вы передумаете."); break;
				}
			}
		}
		break;
		case 2: {
			printf("Это хорошо!");
			printf("Собираетесь в путешествие в этом году?\n1 - да\n2 - нет\n");
			scanf_s("%d", &b2);
			switch (b2) {
				case 1: {
					printf("Ого! И куда же???\n1 - Египет\n2 - Франция\n3 - Америка\n");
					scanf_s("%d", &c2);
					switch (c2) {
						case 1: {
							printf("Отличный выбор! Не забудьте посетить Египетские Пирамиды."); break;
						}
						case 2: {
							printf("Отличный выбор! Не забудьте посетить Эйфелеву Башню."); break;
						}
						case 3: {
							printf("Отличный выбор! Не забудьте посетить Статую Свободы."); break;
						}
					}
					break;
				}
				case 2: {
					printf("Очень жаль, надеюсь вы передумаете."); break;
				}
			}
		}
		break;
		case 3: {
			printf("Не печальтесь.");
			printf("Думаю, Вам нужно отправиться в путешествие.\n1 - да\n2 - нет\n");
			scanf_s("%d", &b3);
			switch (b3) {
				case 1: {
					printf("Как Вам такие варианты?\n1 - Египет\n2 - Франция\n3 - Америка\n");
					scanf_s("%d", &c3);
					switch (c3) {
						case 1: {
							printf("Отличный выбор! Не забудьте посетить Египетские Пирамиды."); break;
						}
						case 2: {
							printf("Отличный выбор! Не забудьте посетить Эйфелеву Башню."); break;
						}
						case 3: {
							printf("Отличный выбор! Не забудьте посетить Статую Свободы."); break;
						}
					}
					break;
				}
				case 2: {
					printf("Очень жаль, надеюсь вы передумаете."); break;
				}
			}
		}
		break;
	}
	printf("\nА сколько Вам лет?\n");
	scanf_s("%d", &age);
	printf("Ого! Целых %d лет!", age);
	srand(time(NULL));
	age2 = rand() % 1000 + 1;
	printf("А мне всего лишь %d.", age2);
	printf("\nНу ладно, мне пора компилировать дальше. До свидания, %s!\n", imya);
}

