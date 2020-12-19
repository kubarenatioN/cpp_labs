//Заменить последний символ каждого слова в строке на символ вопроса
#include <iostream>
using namespace std;
void main() {
	setlocale(0, "rus");
	const int N = 100;
	char s[N];
	int len = 0, i = 0, i1 = 0, i2 = 0;
	cout << "Введите строку:" << endl;
	gets_s(s);
	while (s[i] != '\0') {
		len += 1;
		i++;
	}
	for (int i = 0; i < len; i++) {
		if (s[i] == ' ') {
			i2 = i - 1;
			s[i2] = '?';
		}
		i1 = i + 1;
	}
	s[len-1] = '?';
	for (int i = 0; i < len; i++) {
		cout << s[i];
	}
}
