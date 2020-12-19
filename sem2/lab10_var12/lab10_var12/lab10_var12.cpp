#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int value;
	Node *prev;
	Node *next;
};

Node *CreateNode() {
	Node *temp = new Node;
	cout << "Введите значение: "; cin >> temp->value;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void Add(Node *temp, Node **b, Node **e) {
	if (*e == NULL) {
		*e = temp;
		*b = temp;
	}
	else {
		(*e)->next = temp;
		temp->prev = *e;
		*e = temp;
	}
}

void Print(Node *b) {
	Node *temp = b;
	while (temp) {
		cout << temp->value << endl;
		temp = temp->next;
	}
}

void Find(Node *b) {
	Node *temp = b;
	bool flag = true;
	int val;
	cout << "Введите значение: "; cin >> val;
	while (temp) {
		if (temp->value == val) {
			cout << temp->value << endl;
			flag = false;
		}
		temp = temp->next;
	}
	if (flag) {
		cout << "Ничего не найдено.\n";
	}
}

void Delete(Node **b, Node **e) {
	Node *temp = *b;
	bool flag = true;
	int val;
	cout << "Введите значение: "; cin >> val;
	while (temp) {
		if (temp->value == val) {
			flag = false;
			if (temp == *b) {
				*b = (*b)->next;
				if (*b != NULL) {
					(*b)->prev = NULL;
				}
				else {
					*e = NULL;
				}
				temp = temp->next;
				delete temp->prev;
				break;
			}
			else {
				temp->prev->next = temp->next;
				if (temp != *e) {
					temp->next->prev = temp->prev;
				}
				else {
					*e = temp->prev;
				}
				temp = temp->next;
				delete temp->prev;
				break;
			}
			cout << "Элемент удален.\n";
		}
		else {
			temp = temp->next;
		}
	}
	if (flag) {
		cout << "Ничего не удалено.\n";
	}
}

void Input(Node *b, ofstream &f) {
	Node *temp = b;
	while (temp) {
		f << temp->value << '\n';
		temp = temp->next;
	}
}

void Output(Node **e, Node **b, ifstream &f) {
	char buffer[30];
	while (!f.eof()) {
		f.getline(buffer, sizeof(buffer));
		if (strcmp(buffer, "") == 0) {
			continue;
		}
		else {
			Node *temp = new Node;
			temp->next = NULL;
			temp->prev = NULL;
			temp->value = atoi(buffer);
			Add(temp, b, e);
		}
	}
}

void Menu() {
	cout << "-------------------\n";
	cout << "Выберите действие:\n";
	cout << "1 - Добавить элемент в список;\n";
	cout << "2 - Вывести список;\n";
	cout << "3 - Найти элемент списка;\n";
	cout << "4 - Удалить элемент списка;\n";
	cout << "5 - Запись в файл;\n";
	cout << "6 - Чтение из файла;\n";
	cout << "0 - Выход.\n";
	cout << "-------------------\n";
}

void main() {
	setlocale(0, "rus");
	int choice;
	Node *begin, *end;
	begin = NULL;
	end = begin;
	ofstream inFile;
	ifstream fromFile;
	do {
		Menu();
		cin >> choice;
		switch (choice) {
		case 1:
			Add(CreateNode(), &begin, &end);
			break;
		case 2:
			Print(begin);
			break;
		case 3:
			Find(begin);
			break;
		case 4:
			Delete(&begin, &end);
			break;
		case 5:
			inFile.open("file.txt");
			Input(begin, inFile);
			inFile.close();
			break;
		case 6:
			fromFile.open("file.txt");
			Output(&end, &begin, fromFile);
			fromFile.close();
			break;
		}
	} while (choice != 0);
}