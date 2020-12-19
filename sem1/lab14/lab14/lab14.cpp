//В предложении имеется слово из пяти букв.Найти это слово
//#include <iostream>
//using namespace std;
//void main() {
//	setlocale(0, "rus");
//	const int N = 100;
//	char s[N];
//	int i = 0, len = 0, i1 = 0, i2 = 0;
//	cout << "Введите предложение: " << endl;
//	gets_s(s);
//	while (s[i] != '\0') {
//		len += 1;
//		i++;
//	}
//	for (int i = 0; s[i] != '\0'; i++) {
//		if (s[i] == ' ') {
//			i2 = i - 1;
//			if (i2 - i1 == 4) {
//				for (int j = i1; j < i2 + 1; j++) {
//					cout << s[j];
//				}
//				cout << endl;
//			}
//			i1 = i + 1;
//		}
//	}
//	if (len - i1 == 5) {
//		for (int j = i1; j < len; j++) {
//			cout << s[j];
//		}
//	}
//}



//Заменить последний символ каждого слова в строке на символ вопроса
//#include <iostream>
//using namespace std;
//void main() {
//	setlocale(0, "rus");
//	const int N = 100;
//	char s[N];
//	int len = 0, i = 0, i1 = 0, i2 = 0;
//	cout << "Введите строку:" << endl;
//	gets_s(s);
//	while (s[i] != '\0') {
//		len += 1;
//		i++;
//	}
//	for (int i = 0; i < len; i++) {
//		if (s[i] == ' ') {
//			i2 = i - 1;
//			s[i2] = '?';
//		}
//		i1 = i + 1;
//	}
//	s[len-1] = '?';
//	for (int i = 0; i < len; i++) {
//		cout << s[i];
//	}
//}

//Удалить все пробелы в строке
//#include <iostream>
//using namespace std;
//void main() {
//	setlocale(0, "rus");
//	const int N = 100;
//	char s[N];
//	int len = 0, i = 0;
//	cout << "Введите строку:" << endl;
//	gets_s(s);
//	while (s[i] != '\0') {
//		len += 1;
//		i++;
//	}
//	for (int i = 0; i < len; i++) {
//		if (s[i] == ' ') {
//			for (int j = i; j < len; j++) {
//				s[j] = s[j + 1];
//			}
//			len--;
//		}
//	}
//	for (int i = 0; i < len; i++) {
//		cout << s[i];
//	}
//}

//Найти, сколько раз введенный с клавиатуры символ встречается в строке
//#include <iostream>
//using namespace std;
//void main() {
//	setlocale(0, "rus");
//	const int N = 100;
//	char s[N], symb;
//	int len = 0, i = 0, k = 0;
//	cout << "Введите строку:" << endl;
//	gets_s(s);
//	cout << "Введите символ:";
//	cin >> symb;
//	while (s[i] != '\0') {
//		len += 1;
//		i++;
//	}
//	for (int i = 0; i < len; i++) {
//		if (s[i] == symb) {
//			k++;
//		}
//	}
//	cout << k;
//}