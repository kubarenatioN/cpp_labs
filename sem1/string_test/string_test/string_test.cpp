//#include <iostream>
//#include <ctime>
//#include <windows.h>
//using namespace std;
//Дана строка.Все русские буквы привести к верхнему регистру, латинские заменить символом « ? ».
//Вывести результат на экран.
//char stroka(char *S) {
//	cout << "Введите строку: ";
//	cin.getline(S, 51);
//	cout << S;
//
//	for (int i = 0; i < 51; i++) {
//		if (*(S + i) >= 'а' && *(S + i) <= 'я') {
//			*(S + i) = *(S + i) - 'a' + 'A';
//		}
//		else if ((*(S + i) >= 'a' && *(S + i) <= 'z') || (*(S + i) >= 'A' && *(S + i) <= 'Z')) {
//			*(S + i) = '?';
//		}
//	}
//	cout << endl;
//	cout << S;
//	return 0;
//}
//
//void main() {
//	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
//	SetConsoleOutputCP(1251);
//	char *S;
//	S = new char[51];
//	stroka(S);
//}

#include <iostream>
#include <ctime>
using namespace std;
void main() {
	setlocale(0, "rus");
	char *S;
	int len = 0;
	S = new char[51];
	cout << "Введите строку: ";
	cin.getline(S, 51);
	while (*(S+len) != '\0') {
		len += 1;
	}
	for (int i = 0; i < len; i++) {
		if (*(S + i) == 'l') {
			for (int j = i; j < len; j++) {
				*(S + j) = *(S + j + 1);
			}
			len -= 1;
			i = 0;
		}
	}
	cout << S;
}
