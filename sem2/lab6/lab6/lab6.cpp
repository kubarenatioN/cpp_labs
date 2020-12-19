#include <iostream>
using namespace std;

//Справочник автомобилей.Марка автомобиля, цвет, заводской номер,
//дата выпуска, тип кузова(се - дан, универсал и т.п.),
//дата последнего техосмотра, владелец.
//Выбор транспортных средств по номеру.
//Дату выпуска реализовать с помощью битового поля, марку  с помощью перечисления.

int choice, num = 0;

enum carMark {
	Audi = 1,
	Ford,
	Opel,
	Tesla
};

struct carList {
	carMark mark;
	char color[20];
	char factoryNumber[10];
	unsigned short date:12;
	char type[20];
	char lastReviewDate[10];
	char owner[50];
};

carList cars[20];

void input() {
	int ch, a, k, mrk;
	cout << "1 - Ввод одного поля;" << endl;
	cout << "2 - Ввод нескольких полей;" << endl;
	cin >> ch;
	switch (ch) {
	case 1:
		cout << "Марка: " << endl;
		cout << "Audi -> 1" << endl;
		cout << "Ford -> 2" << endl;
		cout << "Opel -> 3" << endl;
		cout << "Tesla -> 4" << endl;
		cin >> mrk;
		switch (mrk) {
		case 1:
			cars[num].mark = Audi;
			break;
		case 2:
			cars[num].mark = Ford;
			break;
		case 3:
			cars[num].mark = Opel;
			break;
		case 4:
			cars[num].mark = Tesla;
			break;
		default:
			cout << "Ошибка" << endl;
			break;
		}
		cout << "Цвет: "; cin >> cars[num].color;
		cout << "Заводской номер: "; cin >> cars[num].factoryNumber;
		cout << "Дата выпуска: "; cin >> a;
		cars[num].date = a;
		cout << "Тип кузова: "; cin >> cars[num].type;
		cout << "Дата техосмотра: "; cin >> cars[num].lastReviewDate;
		cout << "Владелец: "; cin >> cars[num].owner;
		num++;
		break;
	case 2:
		cout << "Сколько полей необходимо ввести?" << endl; cin >> k;
		for (int i = 0; i < k; i++) {
			cout << "Марка: " << endl;
			cout << "Audi -> 1" << endl;
			cout << "Ford -> 2" << endl;
			cout << "Opel -> 3" << endl;
			cout << "Tesla -> 4" << endl;
			cin >> mrk;
			switch (mrk) {
			case 1:
				cars[num].mark = Audi;
				break;
			case 2:
				cars[num].mark = Ford;
				break;
			case 3:
				cars[num].mark = Opel;
				break;
			case 4:
				cars[num].mark = Tesla;
				break;
			default:
				cout << "Ошибка" << endl;
				break;
			}
			cout << "Цвет: "; cin >> cars[num].color;
			cout << "Заводской номер: "; cin >> cars[num].factoryNumber;
			cout << "Дата выпуска: "; cin >> a;
			cars[num].date = a;
			cout << "Тип кузова: "; cin >> cars[num].type;
			cout << "Дата техосмотра: "; cin >> cars[num].lastReviewDate;
			cout << "Владелец: "; cin >> cars[num].owner;
			num++;
		}
		break;
	}
	cout << "Выберите действие:" << endl;
}

void output() {
	int ch, n;
	cout << "1 - Вывод одного поля;" << endl;
	cout << "2 - Вывод всех полей;" << endl;
	cin >> ch;
	switch (ch) {
	case 1:
		cout << "Номер поля: "; cin >> n;
		cout << endl;
		cout << "Марка: ";
		switch (cars[n - 1].mark) {
		case 1:
			cout << "Audi" << endl;
			break;
		case 2:
			cout << "Ford" << endl;
			break;
		case 3:
			cout << "Opel" << endl;
			break;
		case 4:
			cout << "Tesla" << endl;
			break;
		}
		cout << "Цвет: " << cars[n - 1].color << endl;
		cout << "Заводской номер: " << cars[n - 1].factoryNumber << endl;
		cout << "Дата выпуска: " << cars[n - 1].date << endl;
		cout << "Тип кузова: " << cars[n - 1].type << endl;
		cout << "Дата техосмотра: " << cars[n - 1].lastReviewDate << endl;
		cout << "Владелец: " << cars[n - 1].owner << endl;
		break;
	case 2:
		for (int i = 0; i < num; i++) {
			cout << endl;
			cout << "Марка: ";
			switch (cars[i].mark) {
			case 1:
				cout << "Audi" << endl;
				break;
			case 2:
				cout << "Ford" << endl;
				break;
			case 3:
				cout << "Opel" << endl;
				break;
			case 4:
				cout << "Tesla" << endl;
				break;
			}
			cout << "Цвет: " << cars[i].color << endl;
			cout << "Заводской номер: " << cars[i].factoryNumber << endl;
			cout << "Дата выпуска: " << cars[i].date << endl;
			cout << "Тип кузова: " << cars[i].type << endl;
			cout << "Дата техосмотра: " << cars[i].lastReviewDate << endl;
			cout << "Владелец: " << cars[i].owner << endl;
		}
		break;
	}
	cout << "Выберите действие:" << endl;
}

void del() {
	int ch, n;
	cout << "1 - Удаление одного поля;" << endl;
	cout << "2 - Удаление всех полей;" << endl;
	cin >> ch;
	switch (ch) {
	case 1:
		cout << "Номер поля: "; cin >> n;
		for (int i = n - 1; i < num; i++) {
			cars[i] = cars[i + 1];
		}
		num--;
		break; 
	case 2:
		while (num != 0) {
			for (int i = 0; i < num; i++) {
				cars[i] = cars[i + 1];
			}
			num--;
		}
		break;
	}
	cout << "Выберите действие:" << endl;
}

void search() {
	char str[10];
	bool flag = true;
	cout << "Введите номер транспортного средства: "; cin >> str;
	for (int i = 0; i < num; i++) {
		if (strcmp(cars[i].factoryNumber, str) == 0) {
			cout << endl;
			cout << "Марка: ";
			switch (cars[i].mark) {
			case 1:
				cout << "Audi" << endl;
				break;
			case 2:
				cout << "Ford" << endl;
				break;
			case 3:
				cout << "Opel" << endl;
				break;
			case 4:
				cout << "Tesla" << endl;
				break;
			}
			cout << "Цвет: " << cars[i].color << endl;
			cout << "Заводской номер: " << cars[i].factoryNumber << endl;
			cout << "Дата выпуска: " << cars[i].date << endl;
			cout << "Тип кузова: " << cars[i].type << endl;
			cout << "Дата техосмотра: " << cars[i].lastReviewDate << endl;
			cout << "Владелец: " << cars[i].owner << endl;
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << endl << "Ничего не найдено." << endl;
	}
	cout << "Выберите действие:" << endl;
}

void main() {
	setlocale(0, "rus");
	cout << "Выберите действие:" << endl;
	do {
		cout << endl << "1 - Ввод данных;" << endl;
		cout << "2 - Вывод данных;" << endl;
		cout << "3 - Удаление данных;" << endl;
		cout << "4 - Поиск данных;" << endl;
		cout << "0 - Выход." << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 3:
			del();
			break;
		case 4:
			search();
			break;
		}
	} while (choice != 0);
}