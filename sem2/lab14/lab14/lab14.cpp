#include <iostream>
#include <ctime>
using namespace std;

struct hashNode {
	int key;
	char *string;
	hashNode Node(int k, char *str) {
		key = k;
		string = str;
	}
};

int hashFn1(int key, int m, int i) {
	return (i + key) % m;
}
int hashFn2(int hash1, int m, int i) {
	return (hash1 + 5 * i + 3 * i*i) % m;
}

static void *DEL = (void *)-1;

struct Hash {
	void **data;
	/*Hash(int, int(*)(void *));*/
	Hash(int size, int(*getkey)(void *)) {
		N = 0;
		this->m = size;
		this->getKey = getkey;
		this->data = new void *[size];
		for (int i = 0; i < size; i++) {
			data[i] = NULL;
		}
	}
	int m;
	int N;
	int(*getKey)(void *);
	bool Insert(void *d) {
		bool b = false;
		if (N < m) {
			for (int i = 0,  j = hashFn1(getKey(d), m, 0);
				i < m && !b; j = hashFn2(getKey(d), m, ++i)) {
				if (data[j] == NULL || data[j] == DEL) {
					data[j] = d;
					N++;
					b = true;
				}
			}
		}
		return b;
	}
	int searchInd(int key) {
		int t = -1;
		bool b = false;
		if (N != 0) {
			for (int i = 0, j = hashFn1(key, m, 0);
				data[j] != NULL && i < m && !b; j = hashFn1(key, m, ++i)) {
				if (data[j] != DEL) {
					if (getKey(data[j]) == key) {
						t = j;
						b = true;
					}
				}
			}
		}
		return t;
	}
	void *search(int key) {
		int t = searchInd(key);
		return (t >= 0) ? data[t] : NULL;
	}
	void *delKey(int key) {
		int i = searchInd(key);
		void *t = data[i];
		if (t != NULL) {
			data[i] = DEL;
			N--;
		}
		return t;
	}
	bool del(void *d) {
		return delKey(getKey(d)) != NULL;
	}
	void scan() {
		for (int i = 0; i < this->m; i++) {
			cout << i + 1 << ". ";
			if (this->data[i] == NULL) {
				cout << "NULL" << endl;
			}
			else if (this->data[i] == DEL) {
				cout << "DEL" << endl;
			}
			else {
				cout << ((hashNode*)this->data[i])->string << endl;
			}
		}
	}
};

Hash Create(int m, int(*getkey)(void*)) {
	return *(new Hash(m, getkey));
}

int key(void *d) {
	hashNode *temp = (hashNode*)d;
	return temp->key;
}

void main() {
	setlocale(0, "rus");
	int size, choice, k;
	double time;
	cout << "Введите размер хеш-таблицы ";
	cin >> size;
	Hash Table = Create(size, key);
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
			Table.scan();
			break;
		}
		case 2: {
			hashNode *temp = new hashNode;
			char *str = new char[20];
			cout << "Введите ключ" << endl;
			cin >> k;
			temp->key = k;
			cout << "Введите строку" << endl;
			cin >> str;
			temp->string = str;
			if (Table.N == Table.m) {
				cout << "Таблица заполнена" << endl;
			}
			else {
				Table.Insert(temp);
			}
			break;
		}
		case 3: {
			cout << "Введите ключ ";
			cin >> k;
			Table.delKey(k);
			break;
		}
		case 4: {
			cout << "Введите ключ ";
			cin >> k;
			double start_time = clock();
			if (Table.search(k) == NULL) {
				cout << "Такого элемента нет" << endl;
			}
			else {
				cout << ((hashNode*)Table.search(k))->key
					<< " -- " << ((hashNode*)Table.search(k))->string << endl;
			}
			double end_time = clock();
			cout << "Время: " << end_time - start_time << endl;
			break;
		}
		}
	} while (choice!=0);
	time = clock();
	cout << time << endl;
}