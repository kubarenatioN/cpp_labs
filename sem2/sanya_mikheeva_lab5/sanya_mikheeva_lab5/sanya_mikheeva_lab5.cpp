﻿#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale>
#include <windows.h>
using namespace std;

//Склад.Наименование товара, цена, количество,
//процент торговой надбавки(5, 10, 15, 20, 35, 30).Выбор по цене.

struct Country {//Стуруктура типа Country
	char name[30];
	char capital[30];
	int population;
	float area;
	char president[30];
};

Country CountryArr[10];//Массив структур типа Country

int choice;//Выбор пользователя
int num = 0;//Количество заполненных структур

void input() {//Ввод данных
	if (num < 10) {//Если есть место(не больше 10)
		cout << "Наименование государства: ";
		cin >> CountryArr[num].name;//Название государства
		cout << "Столица: ";
		cin >> CountryArr[num].capital;
		cout << "Население: ";
		cin >> CountryArr[num].population;
		cout << "Площадь: ";
		cin >> CountryArr[num].area;
		cout << "Фамилия президента: ";
		cin >> CountryArr[num].president;
		num++;
	}
	else {
		cout << "Введено максимальное количество записей";
	}
	cout << endl << "Выберите действие:" << endl;
}

void output() {//Вывод всех данных от 0 до num через цикл
	for (int i = 0; i < num; i++) {
		cout << endl << "Наименование государства: " << CountryArr[i].name << endl;
		cout << "Столица: " << CountryArr[i].capital << endl;
		cout << "Население: " << CountryArr[i].population << endl;
		cout << "Площадь: " << CountryArr[i].area << endl;
		cout << "Фамилия президента: " << CountryArr[i].president << endl;
	}
	cout << endl << "Выберите действие:" << endl;
}

void del() {
	int n;
	cout << "Введите номер записи, которую надо удалить. Чтобы удалить все записи введите 000: " << endl;
	cin >> n;
	if (n == 000) {
		while (num != 0) {
			for (int i = 0; i < num; i++) {
				CountryArr[i] = CountryArr[i + 1];
			}
			num--;
		}
	}
	else if (n < 11) {
		for (int i = (n - 1); i < num; i++) {
			CountryArr[i] = CountryArr[i + 1];
		}
		num--;
	}
	else {
		cout << "Ошибка";
	}
	cout << endl << "Выберите действие:" << endl;
}

void find() {
	char name[20];//Вводим в массив символов название государства
	bool flag = true;//Переменная логического типа, нужна для вывода сообщения о том что ничего не найдено
	cout << "Введите название государства: ";
	cin >> name;
	for (int i = 0; i < num; i++) {//Перебираем все структуры
		if (strcmp(name, CountryArr[i].name) == 0) {//Сравниваем строку с названием каждого государства если совпадают, функция возвращает 0
			cout << endl << "Наименование государства: " << CountryArr[i].name << endl;
			cout << "Столица: " << CountryArr[i].capital << endl;
			cout << "Население: " << CountryArr[i].population << endl;
			cout << "Площадь: " << CountryArr[i].area << endl;
			cout << "Фамилия президента: " << CountryArr[i].president << endl;
			flag = false;//Делаем переменную false чтобы не выводился блок if снизу
			break;
		}
	}
	if (flag) {
		cout << "Такой записи нет" << endl;
	}
	cout << endl << "Выберите действие:" << endl;
}

void inFile() {
	ofstream file;//Создаем дескриптор файла для записи
	file.open("file.txt");//Открываем файл
	for (int i = 0; i < num; i++) {//Перебираем каждую структуру и записываем ее в файл
		file << CountryArr[i].name << '\n';
		file << CountryArr[i].capital << '\n';
		file << CountryArr[i].population << '\n';
		file << CountryArr[i].area << '\n';
		file << CountryArr[i].president << '\n';
	}
	cout << endl << "Выберите действие:" << endl;
}

void outFile() {
	ifstream file;//Создаем дескриптор файла для чтения
	char buffer[100];//Буферная переменная для считывания строчек файла
	int rows = 0, number;//rows - количество строк файла, number - переменная для преобрзования строки в число
	file.open("file.txt");//Открываем файл file.txt
	while (!file.eof()) {//Пока не дойдем до конца файла
		file.getline(buffer, 100, '\n');//Считываем построчно файл
		rows++;//Для того чтобы найти общее количество строк
	}
	file.close();//Закрываем файл чтобы очистить позиционирование(установить в начале файла)
	file.open("file.txt");//Открываем файл снова
	for (int i = 0; i < rows/5; i++, num++) {//Через цикл от нуля до rows/5 т.е. до количества структур которые будут добавлены
		file.getline(buffer, 30);//Считываем строки файла 
		strcpy_s(CountryArr[num].name, buffer);//Заполняем ими поля структуры с помощью strcpy_s

		file.getline(buffer, 30);
		strcpy_s(CountryArr[num].capital, buffer);

		file.getline(buffer, 30);//Читаем строку которая содержит число - получаем строку
		number = atoi(buffer);//Преобразуем строку содержащую число в обычное число с помощью функции atoi(Array TO Integer)
		CountryArr[num].population = number;

		file.getline(buffer, 30);
		number = atoi(buffer);
		CountryArr[num].area = number;

		file.getline(buffer, 30);
		strcpy_s(CountryArr[num].president, buffer);
	}
	file.close();

	cout << endl << "Выберите действие:" << endl;
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Выберите действие:" << endl;
	do {
		cout << "1 - Ввести данные." << endl;
		cout << "2 - Вывести данные." << endl;
		cout << "3 - Удалить запись." << endl;
		cout << "4 - Поиск данных." << endl;
		cout << "5 - Записать данные в файл." << endl;
		cout << "6 - Прочитать данные из файла." << endl;
		cout << "0 - Выход." << endl;
		cin >> choice;
		switch (choice) {
		case 1: input(); break;
		case 2: output(); break;
		case 3: del(); break;
		case 5: inFile(); break;
		case 6: outFile(); break;
		case 4: find(); break;
		case 0: break;
		}
	} while (choice != 0);
}