#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//void main() {
//	setlocale(0, "rus");
//	int N, K, lines = 0, consonants = 0;
//	ifstream file1;//чтение из файла
//	ofstream file2;//запись в файл
//	file1.open("FILE1.txt");
//	string str;
//	char ch, pre;
//	cout << "Введите N: ";
//	cin >> N;
//	cout << "Введите K: ";
//	cin >> K;
//	while (!file1.eof()) {
//		file1.get(ch);
//		pre = ch;
//		if (ch == '\n') {
//			lines++;
//		}
//	}
//	if (pre != '\n' && pre != EOF) {
//		lines++;
//	}
//	file1.close();
//	file1.open("FILE1.txt");
//	file2.open("FILE2.txt");
//	for (int i = 0; i < N-1; i++) {
//		getline(file1, str);
//	}
//	for (int i = 0; i < K-N+1; i++) {
//		getline(file1, str);
//		file2 << str + '\n';
//	}
//	file1.close();
//	file2.close();
//	ifstream file3;
//	file3.open("FILE2.txt");
//	while (!file3.eof()) {
//		file3.get(ch);
//		if (ch != 'a' && ch != 'e' && ch != 'y' && ch != 'u' && ch != 'i'
//			&& ch != 'o' && ch != ' ' && ch != '\n' && ch != ',' && ch != '!' && ch != '?' && ch != ':') {
//			consonants++;
//		}
//	}
//	file3.close();
//	cout << "Количество согласных букв в файле FILE2.txt: " << consonants;
//}

void combs(ifstream &file, char *containingStr) {
	file.open("file.txt");
	int i = 0, index = 0;
	char ch;
	char word[20] = "";
	while (!file.eof()) {//until it will not be end of file
		ch = ' ';//refresh ch's property
		file.get(ch);//getting a symbol
		if (ch != ' ') {//if the symbol is not 'space' add it to the string
			word[i] = ch;
			i++;//grow counter
		}
		else {
			if (i % 2 == 0) {
				for (int j = 0; j < strlen(word); j++) {
					containingStr[index] = word[j];
					index++;
				}
				containingStr[index] = ' ';
				index++;
				i = 0;//refresh counter
				for (int j = 0; j < strlen(word); j++) {
					word[j] = ' ';//emptying string
				}
			}
			else {
				for (int j = 0; j < strlen(word); j++) {
					word[j] = ' ';//emptying string
				}
				i = 0;
			}
		}
	}
	containingStr[index] = '\0';
}

void entering(ofstream &file, char enteringStr[50]) {
	file.open("file.txt");
	file << enteringStr;
	file.close();
}

void main() {
	setlocale(0, "rus");
	char str[50], container[50];
	cout << "Введите строку символов, состоящую из групп цифр и нулей:\n";
	gets_s(str);
	ofstream outfile;
	ifstream infile;

	entering(outfile, str);
	combs(infile, container);
	cout << container;
}