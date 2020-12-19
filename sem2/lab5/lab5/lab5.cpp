#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale>
#include <windows.h>
using namespace std;

//Склад.Наименование товара, цена, количество,
//процент торговой надбавки(5, 10, 15, 20, 35, 30).Выбор по цене.

struct Stock {
	char goodsName[30];
	float price;
	int amount;
	float percent;
};

Stock MyStock[10];
//struct Stock emptyRow;

int choice;
int num = 0;

void input() {
	if (num < 10) {
		cout << "Наименование товара: ";
		cin >> MyStock[num].goodsName;
		cout << "Цена: ";
		cin >> MyStock[num].price;
		cout << "Количество: ";
		cin >> MyStock[num].amount;
		cout << "Процент торговой надбавки: ";
		cin >> MyStock[num].percent;
		num++;
	}
	else {
		cout << "Введено максимальное количество записей";
	}
	cout << endl << "Выберите действие:" << endl;
}

void output() {
	int numOfRows, n;
	cout << "1 - Вывод определенной записи" << endl;
	cout << "2 - Вывод всех записей" << endl;
	cin >> numOfRows;
	switch (numOfRows) {
	case 1:
		cout << "Номер выводимой записи: "; cin >> n;
		cout << "Наименование товара: " << MyStock[n - 1].goodsName << endl;
		cout << "Цена: " << MyStock[n - 1].price << endl;
		cout << "Количество: " << MyStock[n - 1].amount << endl;
		cout << "Процент торговой надбавки: " << MyStock[n - 1].percent << endl;
		break;
	case 2:
		for (int i = 0; i < num; i++) {
			cout << endl << "Наименование товара: " << MyStock[i].goodsName << endl;
			cout << "Цена: " << MyStock[i].price << endl;
			cout << "Количество: " << MyStock[i].amount << endl;
			cout << "Процент торговой надбавки: " << MyStock[i].percent << endl;
		}
		break;
	default:
		cout << "Ошибка." << endl;
		break;
	}
	cout << endl << "Выберите действие:" << endl;
}

void del() {
	int n;
	cout << "Введите номер записи, которую надо удалить. Чтобы удалить все записи введите 000: " << endl;
	cin >> n;
	if (n == 000) {
		while(num!=0){
			for (int i = 0; i < num; i++) {
				MyStock[i] = MyStock[i+1];
			}
			num--;
		}
	}
	else if (n < 11) {
		for (int i = (n - 1); i < num; i++) {
			MyStock[i] = MyStock[i + 1];
		}
		num--;
	}
	else {
		cout << "Ошибка";
	}
	cout << endl << "Выберите действие:" << endl;
}

void find() {
	char name[20];
	bool flag = true;
	cout << "Введите наименование товара: ";
	cin >> name;
	for (int i = 0; i < num; i++) {
		if (strcmp(name, MyStock[i].goodsName) == 0) {
			cout << "Наименование товара: " << MyStock[i].goodsName << endl;
			cout << "Цена: " << MyStock[i].price << endl;
			cout << "Количество: " << MyStock[i].amount << endl;
			cout << "Процент торговой надбавки: " << MyStock[i].percent << endl;
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << "Такой записи нет" << endl;
	}
	cout << endl << "Выберите действие:" << endl;
}

void inFile() {
	int numOfRows, n;
	ofstream file;
	file.open("F1.txt");
	cout << "1 - Запись определенного поля" << endl;
	cout << "2 - Запись всех полей" << endl;
	cin >> numOfRows;
	switch (numOfRows) {
	case 1:
		cout << "Номер записываемого поля: "; cin >> n;
		file << "Наименование товара: " << MyStock[n - 1].goodsName << '\n';
		file << "Цена: " << MyStock[n - 1].price << '\n';
		file << "Количество: " << MyStock[n - 1].amount << '\n';
		file << "Процент торговой надбавки: " << MyStock[n - 1].percent << '\n';
		break;
	case 2:
		for (int i = 0; i < num; i++) {
			file << '\n' << "Наименование товара: " << MyStock[i].goodsName << '\n';
			file << "Цена: " << MyStock[i].price << '\n';
			file << "Количество: " << MyStock[i].amount << '\n';
			file << "Процент торговой надбавки: " << MyStock[i].percent << '\n';
		}
		break;
	default:
		cout << "Ошибка." << endl;
		break;
	}

	cout << endl << "Выберите действие:" << endl;
}

void outFile() {
	ifstream file;
	int numOfRows, n, k = 0, start;
	char buffer[50], s;
	cout << "1 - Чтение определенной записи" << endl;
	cout << "2 - Чтение всех записей" << endl;
	cin >> numOfRows;
	switch (numOfRows) {
	case 1:
		cout << "Номер читаемой записи: "; cin >> n;
		start = (n - 1) * 5;
		file.open("F1.txt");
		for (int i = 0; i < num * 5 + 1; i++) {
			file.getline(buffer, sizeof(buffer));
			if (i > start && i < start + 6) {
				cout << buffer << endl;
			}
		}
		file.close();
		break;
	case 2:
		file.open("F1.txt");
		for (int i = 0; i < num * 5 + 1; i++) {
			file.getline(buffer, sizeof(buffer));
			cout << buffer << endl;
		}
		file.close();
		break;
	default:
		cout << "Ошибка." << endl;
		break;
	}
	cout << endl << "Выберите действие:" << endl;
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Выберите действие:" << endl;
	do {
		cout << "1 - Ввести данные." << endl;
		cout << "2 - Вывести данные в консоль." << endl;
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