#include <iostream>
#include <stddef.h>
using namespace std;

int Size = 10;
int N = 0;

struct Cell {
	int key;
	char data[20];
};

static void *DEL = (void*)-1;

int hashFn1(int key, int m, int p) {
	return (p + key) % m;
}

int hashFn2(int hash1, int m, int p) {
	return (hash1 + 5 * p + 3 * p*p) % m;
}

void Insert(Cell *elem, void **table) {
	bool inserted = false;
	for (int i = 0, j = hashFn1(elem->key, Size, 0);
		i != Size && !inserted; j = hashFn2(j, Size, ++i)) {
		if (table[j] == NULL || table[j] == DEL) {
			table[j] = elem;
			N++;
			inserted = true;
		}
	}
}

void Print(void **table) {
	for (int i = 0; i < Size; i++) {
		cout << i + 1 << ". ";
		if (table[i] == NULL) {
			cout << "NULL\n";
		}
		else if (table[i] == DEL) {
			cout << "DEL\n";
		}
		else {
			cout << ((Cell*)table[i])->key << " [" << ((Cell*)table[i])->data << "]" << endl;
		}
	}
}

void Search(void **table, int key) {
	int isfind = false;
	for (int i = 0, j = hashFn1(key, Size, 0);
		table[j] != NULL && i != Size && !isfind; j = hashFn2(j, Size, ++i)) {
		if (table[j] != DEL && ((Cell*)table[j])->key == key) {
			isfind = true;
			cout << "Найден элемент " << ((Cell*)table[j])->key << " [" << ((Cell*)table[j])->data << "]" << endl;
		}
	}
	if (!isfind) {
		cout << "Такого элемента нет\n";
	}
}

void Del(void **table, int key) {
	int isfind = false;
	for (int i = 0, j = hashFn1(key, Size, 0);
		table[j] != NULL && i != Size && !isfind; j = hashFn2(j, Size, ++i)) {
		if (table[j] != DEL && ((Cell*)table[j])->key == key) {
			isfind = true;
			cout << "Удален элемент " << ((Cell*)table[j])->key << " [" << ((Cell*)table[j])->data << "]" << endl;
			table[j] = DEL;
			N--;
		}
	}
	if (!isfind) {
		cout << "Такого элемента нет\n";
	}
}

void main() {
	setlocale(0, "rus");
	int choice, key;
	void **table = new void*[Size];
	for (int i = 0; i < Size; i++) {
		table[i] = NULL;
	}
	do
	{
		cout << "1 - Добавить элемент\n";
		cout << "2 - Вывод\n";
		cout << "3 - Найти элемент\n";
		cout << "4 - Удалить элемент\n";
		cout << "0 - Выход\n";
		cin >> choice;
		switch (choice) {
		case 1: {
			Cell *elem = new Cell;
			cout << "Введите ключ ";
			cin >> elem->key;
			cout << "Введите строку ";
			cin >> elem->data;
			if (N == Size) {
				cout << "Таблица заполнена" << endl;
			}
			else {
				Insert(elem, table);
			}
			if (N * 100 / Size >= 80) {
				int newSize = Size * 2;
				void **table2 = new void*[newSize];
				for (int i = 0; i < newSize; i++) {
					table2[i] = NULL;
				}
				for (int i = 0; i < Size; i++) {
					table2[i] = table[i];
				}
				Size = newSize;
				table = table2;
			}
			break;
		}
		case 2: {
			Print(table);
			break;
		}
		case 3:
			cout << "Введите ключ для поиска ";
			cin >> key;
			Search(table, key);
			break;
		case 4:
			cout << "Введите ключ для удаления ";
			cin >> key;
			Del(table, key);
			break;
		}
	} while (choice != 0);
}