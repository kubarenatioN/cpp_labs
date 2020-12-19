#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

//Даны два файла вещественных чисел с именами fA и fB,
//содержащие элементы прямоугольных матриц M1 и M2 по строкам,
//причем начальный элемент каждого файла содержит количество столбцов соответствующей матрицы.
//Создать файл той же структуры с именем fC, содержащий сумму M1 + M2

//void main() {
//	setlocale(0, "rus");
//	FILE *f;
//	char c, str[50], numberStr[10];
//	int m, n = 0, k = 0, number, index = 0;
//	int reserveA[20], reserveB[20], A[10][10], B[10][10], C[10][10];
//	fopen_s(&f, "fA.txt", "r");//opening file fA.txt
//	c = fgetc(f);//getting number of columns
//	m = c - '0';//converting it to integer
//
//	while (c = fgetc(f) != EOF) {
//		if (c = fgetc(f) != ' ') {
//			n++;
//		}
//	}//counting number of rows
//	n /= m;//number of rows
//	fseek(f, 2, SEEK_SET);//place cursor after 1st number
//	fgets(str, sizeof(str), f);//getting row with digits
//		for (int p = 0, j = 0; p < strlen(str) + 1, j < m*n; p++) {
//			if (str[p] == ' ' || str[p] == '\0') {
//				int a = 0;
//				for (index; index < p; index++) {
//					numberStr[a] = str[index];
//					a++;
//				}
//				index = p + 1;
//				number = atoi(numberStr);
//				reserveA[j] = number;
//				j++;
//			}
//	}//containing reserve with A elements
//	fclose(f);
//	index = 0;
//	fopen_s(&f, "fB.txt", "r");//opening file fB.txt
//	fseek(f, 2, SEEK_SET);//place cursor after 1st number
//	fgets(str, sizeof(str), f);//getting row with digits
//	for (int p = 0, j = 0; p < strlen(str) + 1, j < m*n; p++) {
//		if (str[p] == ' ' || str[p] == '\0') {
//			int a = 0;
//			for (index; index < p; index++) {
//				numberStr[a] = str[index];
//				a++;
//			}
//			index = p + 1;
//			number = atoi(numberStr);
//			reserveB[j] = number;
//			j++;
//		}
//	}//containing reserve with B elements
//	fclose(f);
//	/*for (int i = 0; i < m*n; i++) {
//			cout << reserve[i] << "  ";
//	}
//	cout << endl;*/
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			A[i][j] = reserveA[k];
//			k++;
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << A[i][j] << "  ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	k = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			B[i][j] = reserveB[k];
//			k++;
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << B[i][j] << "  ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			C[i][j] = A[i][j] + B[i][j];
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << C[i][j] << "  ";
//		}
//		cout << endl;
//	}
//}

//Создать текстовый файл F1 не менее, чем из 6 строк, и записать в него информацию.
//Скопировать в файл F2 только те строки из F1, которые начинаются с буквы «А».


void main() {
	setlocale(0, "rus");
	FILE *f, *f2;
	char str[50], s, prev;	//в str будут записываться строки для переноса в F2,
							/*s - символ,
							prev нужен чтобы сохранить последний символ перебора*/
	int len = 0, rows=0;/*len - количество символов,
						чтобы устанавливать позицию в начало каждой строки,
						rows - количество строк*/

	fopen_s(&f, "F1.txt", "r");
	while ((s = fgetc(f)) != EOF) {
		prev = s;
		if (s == '\n') {//если встречаем перенос строки увеличиваем rows,
			rows++;
		}
	}
	if (prev != EOF && prev != '\n') {	/*если последний символ перебора не конец файла и не перенос строки,
										увеличиваем rows еще один раз*/
		rows++;
	}
	fclose(f);
	fopen_s(&f, "F1.txt", "r");
	fopen_s(&f2, "F2.txt", "w");
	for (int i = 0; i < rows; i++) {/*проходим по всем строкам,
									прибавляем к len кол-во символов каждой строки,
									чтобы потом перевести позицию
									на начало следующей строки*/
		fgets(str, sizeof(str), f);
		len += strlen(str) + 1;
		if (str[0] == 'a' || str[0] == 'A') {	/*если первый символ строки а или А,
												то записываем всю строку в f2*/
			fputs(str, f2);
		}
		fseek(f, len, SEEK_SET);
	}
	fclose(f);
	fclose(f2);
}


