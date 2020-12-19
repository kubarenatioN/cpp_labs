#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main() {
	string A[50];//массив строк
	int n = 0;//его размер
	string symbol;
	ifstream fromFile;//для чтения
	ofstream inFile;//для ввода
	
	fromFile.open("A.txt");//открываем файлы
	inFile.open("B.txt");
	
	while (!fromFile.eof()) {//пока не дойдем до конца файла А
		getline(fromFile, symbol);//считываем построчно в symbol числа
		A[n] = symbol;//добавляем каждое число в массив
		n++;
	}
	for (int i = 0; i < 5; i++) {
		inFile << A[i] << '\n';
	}
	for (int i = 10; i < 15; i++) {//через цикл от 0 до половины длины массива
		inFile << A[i] << '\n';
	}
	for (int i = 5; i < 10; i++) {//через цикл от 0 до половины длины массива
		inFile << A[i] << '\n';
	}
	for (int i = 15; i < 20; i++) {//через цикл от 0 до половины длины массива
		inFile << A[i] << '\n';
	}
}