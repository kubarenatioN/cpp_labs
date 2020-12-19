#include <iostream>
#include <fstream>
using namespace std;

int menuChoice;
int numOfElements = 0;

struct Element {
	int value;
	Element *next;
};

void Push(Element **begin, int val) {
	Element *temp = new Element;
	temp->value = val;
	temp->next = *begin;
	*begin = temp;
}

void Pop(Element **begin) {
	Element *temp = *begin;
	cout << temp->value << endl;
	*begin = (*begin)->next;
	delete temp;
}

void Clear(Element **begin) {
	Element *temp;
	while (*begin) {
		temp = *begin;
		*begin = (*begin)->next;
		delete temp;
		numOfElements--;
	}
	cout << "Стек очищен.\n";
}

void Input(Element *begin, ofstream &f) {
	Element *p = begin;
	if (numOfElements > 0) {
		while (p) {
			f << '\n' << p->value;
			p = p->next;
		}
	}
	else {
		cout << "Нечего записывать. Стек пуст.\n";
	}
}

void Output(Element **begin, ifstream &f) {
	char buffer[10];
	int val;
	f.getline(buffer, sizeof(buffer));
	while (!f.eof()) {
		Element *temp = new Element;
		f.getline(buffer, sizeof(buffer));
		val = atoi(buffer);
		temp->value = val;
		temp->next = *begin;
		*begin = temp;
		numOfElements++;
	}
}

void Count(Element *begin) {
	Element *prev, *cur, *next;
	int amount = 0;
	if (numOfElements > 2) {
		prev = begin;
		cur = begin->next;
		next = cur->next;
		while (next != NULL) {
			if (prev->value == next->value) {
				amount++;
			}
			prev = cur;
			cur = next;
			next = next->next;
		}
		cout << "Количество элементов с одинаковыми соседями: " << amount << endl;
	}
	else {
		cout << "Недостаточно элементов.\n";
	}
}

void Menu() {
	cout << "\n-------------------\n";
	cout << "Выберите действие:\n";
	cout << "1 - Добавить элементы стека;\n";
	cout << "2 - Достать элементы стека;\n";
	cout << "3 - Очистить стек;\n";
	cout << "4 - Записать элементы стека в файл;\n";
	cout << "5 - Считать элементы стека из файла;\n";
	cout << "6 - Подсчитать кол-во равных соседей;\n";
	cout << "0 - Выход.\n";
	cout << "-------------------\n";
}

void main() {
	setlocale(0, "rus");
	int value, n;

	ofstream inFile;
	ifstream fromFile;

	Element *begin = NULL;
	Element *end = begin;
	do {
		Menu();
		cin >> menuChoice;
		switch (menuChoice) {
		case 1:
			cout << "Сколько элементов стека добавить? "; cin >> n;
			for (int i = 0; i < n; i++) {
				cout << "Значение: ";  cin >> value;
				Push(&begin, value);
				numOfElements++;
			}
			break;
		case 2:
			cout << "Сколько элементов стека достать? "; cin >> n;
			if (n < numOfElements + 1) {
				for (int i = 0; i < n; i++) {
					Pop(&begin);
					numOfElements--;
				}
			}
			else {
				cout << "Слишком большое значение.\n";
			}
			break;
		case 3:
			Clear(&begin);
			break;
		case 4:
			inFile.open("file.txt");
			Input(begin, inFile);
			inFile.close();
			break;
		case 5:
			fromFile.open("file.txt");
			Output(&begin, fromFile);
			fromFile.close();
			break;
		case 6:
			Count(begin);
			break;
		default:
			break;
		}
	} while (menuChoice != 0);
}