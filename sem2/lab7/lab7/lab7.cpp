#include <iostream>
#include <fstream>
using namespace std;

bool flag = true;
int menuChoice;
int numOfNodes = 0;

struct Node {
	int value;
	Node *next;
};

void Summ(Node *beg) {
	int summa = 0;
	Node *p = beg;
	while (p) {
		if (p->value < -9 && p->value > -100) {
			summa += p->value;
		}
		p = p->next;
	}
	cout << "Сумма отрицательных двухзначных: " << summa << endl;
}

void Del_node(Node **beg, Node **end) {
	int ch, n;
	float val;
	Node *cur, *prev, *temp;
	cout << "Удалять по:\n";
	cout << "1 - Порядковому номеру;\n";
	cout << "2 - По значению;\n";
	cin >> ch;
	switch (ch) {
	case 1:
		cout << "Введите номер удаляемого элемента: "; cin >> n;
		if (n < numOfNodes + 1) {
			if (n == 1) {
				temp = *beg;
				*beg = (*beg)->next;
				delete temp;
				numOfNodes--;
			}
			else if (n == numOfNodes) {
				prev = *beg;
				cur = (*beg)->next;
				for (int i = 0; i < n - 2; i++) {
					prev = cur;
					cur = cur->next;
				}
				if (cur != NULL) {
					*end = prev;
					(*end)->next = NULL;
					temp = prev->next;
					delete temp;
					numOfNodes--;
				}
			}
			else {
				prev = *beg;
				cur = (*beg)->next;
				for (int i = 0; i < n - 2; i++) {
					prev = cur;
					cur = cur->next;
				}
				if (cur != NULL) {
					temp = cur;
					prev->next = cur->next;
					delete temp;
					numOfNodes--;
				}
			}
		}
		else {
			cout << "Слишком большое значение.\n";
		}
		break;
	case 2:
		cout << "Введите удаляемое значение: "; cin >> val;
		if (val == (*beg)->value) {
			temp = *beg;
			*beg = (*beg)->next;
			delete temp;
			numOfNodes--;
		}
		else if (val == (*end)->value) {
			prev = *beg;
			cur = (*beg)->next;
			for (int i = 0; i < numOfNodes - 2; i++) {
				prev = cur;
				cur = cur->next;
			}
			*end = prev;
			(*end)->next = NULL;
			temp = prev->next;
			delete temp;
			numOfNodes--;
		}
		else {
			prev = *beg;
			cur = (*beg)->next;
			while (cur != NULL && cur->value != val) {
				prev = cur;
				cur = cur->next;
			}
			if (cur != NULL) {
				temp = cur;
				prev->next = cur->next;
				delete temp;
				numOfNodes--;
			}
			else {
				cout << "Такого элемента нет в списке.\n";
			}
		}
		break;
	default:
		cout << "Error\n";
		break;
	}
}

void Add_node(Node **end, Node **beg) {
	int n = 0, val;
	cout << "Сколько элементов списка добавить? ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Введите значение: "; cin >> val;
		Node *t = new Node;
		t->value = val;
		t->next = NULL;
		(*end)->next = t;
		(*end) = (*end)->next;
		numOfNodes++;
	}
	if (flag) {
		(*beg) = (*beg)->next;
		flag = false;
	}
}

void Print_node(Node *beg) {
	Node *p;
	p = beg;
	if (numOfNodes>0) {
		while (p) {
			cout << p->value << " --> ";
			p = p->next;
		}
	}
	cout << "NULL" << endl;
}

void Find_node(Node *beg) {
	bool flag = true;
	int number = 0;
	float val;
	cout << "Введите значение: "; cin >> val;
	Node *p;
	p = beg;
	while (p) {
		number++;
		if (p->value == val) {
			cout << "Значение: " << p->value << endl;
			cout << "Порядковый номер: " << number << endl;
			flag = false;
			break;
		}
		p = p->next;
	}
	if (flag) {
		cout << "Ничего не найдено.\n";
	}
}

void Input_node(Node *beg, ofstream &f) {
	Node *p = beg;
	while (p) {
		f << p->value << '\n';
		p = p->next;
	}
}

void Output_node(Node **end, Node **beg, ifstream &f) {
	float val;
	char buffer[20];
	while (!f.eof()) {
		f.getline(buffer, sizeof(buffer));
		//cout << buffer << endl;
		val = atof(buffer);
		//cout << val << endl;
		Node *t = new Node;
		t->value = val;
		t->next = NULL;
		(*end)->next = t;
		(*end) = (*end)->next;
		
		numOfNodes++;
	}
	if (flag) {
		Node *temp;
		temp = *beg;
		*beg = (*beg)->next;
		delete temp;
		flag = false;
	}
	/*for (int i = 0; i < n; i++) {
		Node *t = new Node;
		t->value = val;
		t->next = NULL;
		(*end)->next = t;
		(*end) = (*end)->next;
		numOfNodes++;
	}*/
}

void Menu() {
	cout << "\n-------------------\n";
	cout << "Выберите действие:\n";
	cout << "1 - Добавить элементы списка;\n";
	cout << "2 - Удалить элемент списка;\n";
	cout << "3 - Найти элемент списка;\n";
	cout << "4 - Вывести элементы списка в консоль;\n";
	cout << "5 - Записать элементы списка в файл;\n";
	cout << "6 - Считать элементы списка из файла;\n";
	cout << "7 - Сумма отрицательных двухзначных элементов;\n";
	cout << "0 - Выход.\n";
	cout << "-------------------\n";
}

void main() {
	setlocale(0, "rus");

	ofstream inFile;
	ifstream fromFile;

	Node *begin = new Node;
	Node *end = begin;

	do {
		Menu();
		cin >> menuChoice;
		switch (menuChoice) {
		case 1:
			Add_node(&end, &begin);
			break;
		case 2:
			Del_node(&begin, &end);
			break;
		case 3:
			Find_node(begin);
			break;
		case 4:
			Print_node(begin);
			break;
		case 5:
			inFile.open("file.txt");
			Input_node(begin, inFile);
			inFile.close();
			break;
		case 6:
			fromFile.open("file.txt");
			Output_node(&end, &begin, fromFile);
			fromFile.close();
			break;
		case 7:
			Summ(begin);
			break;
		default:
			break;
		}
	} while (menuChoice != 0);
	
}