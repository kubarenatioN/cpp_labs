#include <iostream>
using namespace std;

struct Route {//Структура маршрута
	int passNum;//key
	char *clientName;
	Route(int k, char *arr) {
		passNum = k;
		clientName = arr;
	}
};

struct Node {//Структура узла списка
	Node *prev;
	Node *next;
	void *data;
	Node(Node *Prev, void *Data, Node *Next) {
		prev = Prev;
		data = Data;
		next = Next;
	}
	Node *getNext() {
		return next;
	};
	Node *getPrev() {
		return prev;
	};
};

static Node *NIL = NULL;

struct List {//Структура списка элементов с одинаковым ключом
	Node *head = NULL;
	Node *getFirst() {
		return head;
	};
	Node *search(void *data) {
		Node *temp = head;
		while (
			temp != NULL && 
			(((Route*)temp->data)->passNum != ((Route*)data)->passNum)) {

			temp = temp->next;
		}
		return temp;
	}
	void insert(void *data) {
		if (head == NULL) {//Если ячейка пуста, т.е. списка нет
			head = new Node(NULL, data, head);
		}
		else {//Если есть список
			head = head->prev = new Node(NULL, data, head);
		}
	}
	void deleteByElement(Node *node) {
		if (node != NULL) {
			if (node->next != NULL) {
				node->next->prev= node->prev;
			}
			if (node->prev != NULL) {
				node->prev->next = node->next;
			}
			else {
				head = node->next;
			}
			delete node;
		}
		cout << "Элемент удален" << endl;
	}
	void deleteByData(void *data) {
		return deleteByElement(search(data));
	}
	void scan() {
		Node *temp = head;
		while (temp != NULL) {
			cout << "[ " << ((Route*)temp->data)->passNum << " -- " << ((Route*)temp->data)->clientName << " ] ";
			temp = temp->next;
		}
	}
};
List createList() {
	return *(new List);
}

struct HashTable {//Сама таблица, где хранятся головы списков
	int size;
	int (*hashFn)(void*);//Указатель на хеш-функцию
	List *hashList;//Массив списков
	HashTable(int s, int(*f)(void*)) {
		size = s;
		hashFn = f;
		hashList = new List [size];
	};
	unsigned char Rand8[256];
	int hashFunction(void *data){//Хеш-функция исключающего ИЛИ
		int h;
		char *str = (char*)data;
		unsigned char h1, h2;
		if (*str == 0) return 0;
		h1 = *str;
		h2 = *str + 1;
		str++;
		while (*str) {
			h1 = Rand8[h1 ^ *str];
			h2 = Rand8[h2 ^ *str];
			str++;
		}
		h = ((int)h1 << 8) | (int)h2;
		return h % size;
	}
	void Insert(void *data) {
		return hashList[hashFunction(data)].insert(data);//В массив голов списков добавляем данные
	}
	Node *Search(void *data) {
		return hashList[hashFunction(data)].search(data);
	}
	void DeleteByData(void *data) {
		return hashList[hashFunction(data)].deleteByData(data);
	}
	void Scan() {
		for (int i = 0; i < size; i++) {
			hashList[i].scan();
			cout << '\n';
		}
	}
};
HashTable createHashTable(int size, int(*f)(void*)) {
	return *(new HashTable(size, f));
}

int hashKey(void *data) {
	Route *buf = (Route*)data;
	return buf->passNum;
}

void routePrint(Node *temp) {
	cout << "[ " << ((Route*)temp->data)->passNum << " -- " << ((Route*)temp->data)->clientName << " ] ";
}

void main() {
	setlocale(0, "rus");
	int choice, size, rNum;
	cout << "Введите размер таблицы "; cin >> size;
	HashTable Table = createHashTable(size, hashKey);
	do
	{
		cout << "1 - Вывод таблицы" << endl;
		cout << "2 - Добавление" << endl;
		cout << "3 - Удаление" << endl;
		cout << "4 - Поиск" << endl;
		cout << "0 - Выход" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			Table.Scan();
			break;
		}
		case 2: {
			Route *temp;
			char *str = new char[20];
			cout << "Введите номер паспорта " << endl; cin >> rNum;
			cout << "Введите имя " << endl; cin >> str;
			temp = new Route(rNum, str);
			Table.Insert(temp);
			break;
		}
		case 3: {
			cout << "Введите номер паспорта ";
			cin >> rNum;
			Table.DeleteByData(&rNum);
			break;
		}
		case 4: {
			cout << "Введите ключ ";
			cin >> rNum;
			//double start_time = clock();
			if (Table.Search(&rNum) == NULL) {
				cout << "Такого элемента нет" << endl;
			}
			else {
				cout << "Найден элемент";
				routePrint(Table.Search(&rNum));
				cout << endl;
			}
			//double end_time = clock();
			//cout << "Время: " << end_time - start_time << endl;
			break;
		}
		}
	} while (choice != 0);
}
