//9. Изменить хеш-функцию в проекте на модульную

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

int hashFn1(int key, int m, int i) {//Модульная хеш-функция
	return (i + key) % m;
}
int hashFn2(int hash1, int m, int i) {//Вторая хеш-функция для разрешения коллизии
	return (hash1 + 5 * i + 3 * i*i) % m;
}

static void *DEL = (void *)-1;

struct Hash {
	void **data;//Данные любого типа (т.к. void **)
	Hash(int size, int(*getkey)(void *)) {//Конструктор Хэш-Таблицы
		N = 0;//Кол-во заполненных ячеек
		this->m = size;//Макс. размер
		this->getKey = getkey;//Функция получения ключа
		this->data = new void *[size];//Динамическая память под данные
		for (int i = 0; i < size; i++) {
			data[i] = NULL;
		}
	}
	int m;
	int N;
	int(*getKey)(void *);
	bool Insert(void *d) {//Добавление
		bool b = false;
		if (N < m) {//Если есть место
			for (int i = 0, j = hashFn1(getKey(d), m, 0);		//Ищем место в таблице; j = индекс ячейки в таблице,
				i < m && !b; j = hashFn2(getKey(d), m, ++i)) {	//вычисляется по функции hashFn1
				if (data[j] == NULL || data[j] == DEL) {		//Если нашли место и оно пустое, заполняем данными
					data[j] = d;
					N++;
					b = true;
				}
			}
		}
		return b;
	}
	int searchInd(int key) {//Поиск ключа
		int t = -1;
		bool b = false;
		if (N != 0) {//Если есть данные в таблице
			for (int i = 0, j = hashFn1(key, m, 0);				//Ищем адрес ячейки по ключу
				data[j] != NULL && i < m && !b; j = hashFn2(key, m, ++i)) {
				if (data[j] != DEL) {//Если данные не удалены
					if (getKey(data[j]) == key) {//Если ключи совпадают
						t = j;	//Индекс искомого
						b = true;
					}
				}
			}
		}
		return t;
	}
	void *search(int key) {//Поиск данных
		int t = searchInd(key);//Если данные найдены, возвращается индекс, по нему выводятся данные
		return (t >= 0) ? data[t] : NULL;//Если данные не найдены, выводится NULL
	}
	void *delKey(int key) {
		int i = searchInd(key);//Если данные есть, возвращается индекс
		void *t = data[i];
		if (t != NULL) {
			data[i] = DEL;//Удаляем данные
			N--;//Уменьшаем размер таблицы
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

Hash Create(int m, int(*getkey)(void*)) {//Создание хеш-таблицы
	return *(new Hash(m, getkey));//Выделение памяти
}

int key(void *d) {//Функция получения ключа
	hashNode *temp = (hashNode*)d;
	return temp->key;
}

void main() {
	setlocale(0, "rus");
	int size, choice, k;
	cout << "Введите размер хеш-таблицы ";
	cin >> size;
	Hash Table = Create(size, key);//Инициализация таблицы
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
	} while (choice != 0);
}