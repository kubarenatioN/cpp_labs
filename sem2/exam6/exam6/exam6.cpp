#include <iostream>
using namespace std;

int Tsize = 10;

struct Node {
	int key;
	char str[20];
	Node *next;
	Node *prev;
};

int hashFn(int key, int m, int p) {
	return (key + p) % m;
}

void Insert(void **table, Node *elem) {
	int j = hashFn(elem->key, Tsize, 0);
	if (table[j] == NULL) {
		elem->next = NULL;
		elem->prev = NULL;
		table[j] = elem;
	}
	else {
		elem->prev = NULL;
		elem->next = ((Node*)table[j]);
		((Node*)table[j])->prev = elem;
		table[j] = elem;
	}
}

void Print(void **table) {
	for (int i = 0; i < Tsize; i++) {
		if (table[i] != NULL) {
			Node *temp = new Node;
			temp = ((Node*)table[i]);
			while (temp) {
				cout << "[" << temp->key << "-" << temp->str << "]" << " --> ";
				temp = temp->next;
			}
			cout << "NULL" << endl;
		}
	}
}

Node *Search(void **table, int key) {
	Node *temp = NULL;
	for (int i = 0; i < Tsize; i++) {
		if (table[i] != NULL) {
			temp = ((Node*)table[i]);
			while (temp) {
				if (temp->key == key) {
					return temp;
				}
				temp = temp->next;
			}
		}
	}
	return temp;
}

int SearchIndex(void **table, int key) {
	Node *temp = NULL;
	int indx = -1;
	for (int i = 0; i < Tsize; i++) {
		if (table[i] != NULL) {
			temp = ((Node*)table[i]);
			while (temp) {
				if (temp->key == key) {
					return indx = i;
				}
				temp = temp->next;
			}
		}
	}
	return indx;
}

void Del(void **table, int key) {
	Node *temp = Search(table, key);
	int index = SearchIndex(table, key);
	if (temp != NULL) {
		if (temp->prev == NULL && temp->next == NULL) {
			table[index] = NULL;
		}
		else if (temp->prev == NULL) {
			temp->next->prev = NULL;
			table[index] = temp->next;
		}
		else if (temp->next == NULL) {
			temp->prev->next = NULL;
		}
		else {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
		delete temp;
	}
	else {
		cout << "Ничего не удалено" << endl;
	}
}

void main() {
	setlocale(0, "rus");

	void **table = new void*[Tsize];
	for (int i = 0; i < Tsize; i++) {
		table[i] = NULL;
	}
	int choice, key;
	do
	{
		cout << "1 - Добавить данные\n";
		cout << "2 - Вывод\n";
		cout << "3 - Поиск\n";
		cout << "4 - Удаление\n";
		cout << "0 - Выход\n";
		cin >> choice;
		switch (choice) {
		case 1:
		{
			Node *elem = new Node;
			cout << "Введите ключ ";
			cin >> elem->key;
			cout << "Введите строку ";
			cin >> elem->str;
			Insert(table, elem);
			break;
		}
		case 2:
		{
			Print(table);
			break;
		}
		case 3:
		{
			cout << "Введите ключ для поиска ";
			cin >> key;
			Node *res = Search(table, key);
			if (res) {
				cout << "Найден элемент: " << "[" << res->key << "-" << res->str << "]" << endl;
			}
			else {
				cout << "Ничего не найдено\n";
			}
			break;
		}
		case 4:
		{
			cout << "Введите ключ для удаления ";
			cin >> key;
			Del(table, key);
			break;
		}
		}
	} while (choice != 0);
}