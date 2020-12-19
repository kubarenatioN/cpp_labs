#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int num = 0;
int choice;

union emp {
	char name[30];
	char specialization[30];
	char position[20];
	char date[20];
};

emp employee[10];

void input(ofstream &f) {
	int ch, n;
	cout << "1 - Ввести одно поле" << endl;
	cout << "2 - Ввести несколько полей" << endl;
	cin >> ch;
	switch (ch) {
	case 1:
		if (num < 10) {

			cout << "Имя: ";
			cin >> employee[num].name;
			f << "Имя: " << employee[num].name << '\n';

			cout << "Специальность: ";
			cin >> employee[num].specialization;
			f << "Специальность: " << employee[num].specialization << '\n';

			cout << "Должность: ";
			cin >> employee[num].position;
			f << "Должность: " << employee[num].position << '\n';

			cout << "Дата найма: ";
			cin >> employee[num].date;
			f << "Дата найма: " << employee[num].date << '\n' << '\n';

			num++;
		}
		else {
			cout << "Введено максимальное количество данных" << endl;
		}
		break;
	case 2:
		cout << "Сколько полей вы хотите ввести? "; cin >> n;
		if (n < 10 - num + 1) {
			for (int i = 0; i < n; i++) {
				cout << "Имя: ";
				cin >> employee[i].name;
				f << "Имя: " << employee[i].name << '\n';

				cout << "Специальность: ";
				cin >> employee[i].specialization;
				f << "Специальность: " << employee[i].specialization << '\n';

				cout << "Должность: ";
				cin >> employee[i].position;
				f << "Должность: " << employee[i].position << '\n';

				cout << "Дата найма: ";
				cin >> employee[i].date;
				f << "Дата найма: " << employee[i].date << '\n' << '\n';

				num++;
			}
		}
		else {
			cout << "Превышено максимальное количество вводимых данных." << endl;
		}
		break;
	default:
		cout << "Error" << endl;
		break;
	}
	cout << "Выберите действие: " << endl;
}

void output(ifstream &f) {
	int numOfRows, n, startLine;
	char buffer[50];
	cout << "Сколько полей вывести?\n";
	cout << "1 - Вывод определенного поля(<11);\n";
	cout << "2 - Вывод всех полей;\n";
	cin >> numOfRows;
	switch (numOfRows) {
	case 1:
		cout << "Номер выводимого поля: "; cin >> n;
		startLine = (n - 1) * 5;
		if (n < 11) {
			for (int i = 0; i < num * 5 + 1; i++) {
				f.getline(buffer, sizeof(buffer));
				if (i > startLine - 1 && i < startLine + 5) {
					cout << buffer << endl;
				}
			}
		}
		else {
			cout << "Error\n";
		}
		break;
	case 2:
		for (int i = 0; i < num * 5; i++) {
			f.getline(buffer, sizeof(buffer));
			cout << buffer << endl;
		}
		break;
	default:
		cout << "ERROR\n";
	}
}

void find(ifstream &f) {
	char pos[30], buffer[30];
	int index = 2;
	cout << "Введите название должности: " << endl;
	cin >> pos;
	for (int i = 0; i < num * 5 + 1; i++) {
		f.getline(buffer, sizeof(buffer));
		if (i == index) {
			int len = 0;
			while (buffer[len] != '\0') {
				len++;
			}
			for (int j = 0; j < 11; j++) {
				for (int k = 0; k < len; k++) {
					buffer[k] = buffer[k + 1];
				}
				len--;
			}
			if (strcmp(buffer, pos) == 0) {
				f.seekg(0);
				for (int t = 0; t < num * 5 + 1; t++) {
					f.getline(buffer, sizeof(buffer));
					if (t > index - 3 && t < index + 3) {
						cout << buffer << endl;
					}
					if (t == index + 3) {
						break;
					}
				}
				index += 5;
				f.seekg(0);
				i = -1;
			}
			else {
				index += 5;
				f.seekg(0);
				i = -1;
			}
		}
	}
}

void main() {
	setlocale(0, "rus");
	ofstream inFile;

	ifstream fromFile;

	cout << "Что делать?" << endl;
	do {
		cout << "---------------\n";
		cout << "1 - Ввод данных" << endl;
		cout << "2 - Вывод данных" << endl;
		cout << "3 - Поиск данных" << endl;
		cout << "0 - Выход" << endl;
		cout << "---------------\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			inFile.open("File.txt", ios_base::app);
			input(inFile);
			inFile.close();
			break;
		case 2:
			fromFile.open("File.txt");
			output(fromFile);
			fromFile.close();
			break;
		case 3:
			fromFile.open("File.txt");
			find(fromFile);
			fromFile.close();
			break;
		default:
			break;
		}
	} while (choice != 0);

	inFile.open("File.txt");
	inFile.close();
}