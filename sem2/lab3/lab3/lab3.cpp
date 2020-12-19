#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>
using namespace std;

//void main() {
//	setlocale(0, "rus");
//	char str[50], number[15];
//	FILE *f;
//	fopen_s(&f, "task1.txt", "r");
//	fgets(str, 30, f);
//	fclose(f);
//	puts(str);
//	int index = 0, k = 0, q;
//	float A[100];
//	for (int i = 0; i < strlen(str) + 1; i++) {
//		if (str[i] == ' ' || str[i] == '\0') {
//			int a = 0;
//			for (index; index < i; index++) {
//				number[a] = str[index];
//				//cout << number[a];
//				a++;
//			}
//			index = i + 1;
//			A[k] = atof(number);
//			k++;
//		}
//	}
//	for (int i = 0; i < k; i++) {
//		cout << setw(4) << A[i];
//	}
//	cout << endl << "Введите число ";
//	cin >> q;
//	int difference = 9999, order = 0;
//	for (int i = 0; i < k; i++) {
//		if (abs(*(A + i) - q) < difference) {
//			difference = abs(*(A + i) - q);
//			order = i;
//		}
//	}
//	cout << "Наиболее близкое к введенному: " << *(A + order);
//}

void main() {
	setlocale(0, "rus");
	char str[50], str1[50];
	int endlines = 0, ch, pre;
	int len = 0;
	FILE *f, *f2;
	fopen_s(&f, "task2.txt", "r");
	while ((ch = fgetc(f)) != EOF) {
		pre = ch;
		if (ch == '\n') {
			endlines++;
		}
	}
	if (pre != EOF && pre != '\n') {
		endlines++;
	}
	fclose(f);
	fopen_s(&f, "task2.txt", "r");
	fopen_s(&f2, "task2in.txt", "w");
	for (int i = 0; i < endlines; i++) {
		fgets(str, 50, f);
		len += strlen(str) + 1;
		if (i % 2 == 1 || i == 1) {
			fputs(str, f2);
		}
		fseek(f, len, SEEK_SET);
	}
	fclose(f2);
	fclose(f);
}