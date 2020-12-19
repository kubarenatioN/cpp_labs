#include <iostream>
#include <iomanip>
#include "Heap.h"
using namespace std;

struct Tree {
	int x;
	void print();
};

struct Heap {
	int size;
	int maxSize;
	int *data;
	Heap(int maxsize) {
		size = 0;
		data = new int [maxSize = maxsize];
	};
	int left(int x) {
		return (2 * x + 1 >= size) ? -1 : (2 * x + 1);
	}
	int right(int x) {
		return (2 * x + 2 >= size) ? -1 : (2 * x + 2);
	}
	int parent(int x) {
		return (x + 1) / 2 - 1;
	}
	bool isFull() {
		return size >= maxSize;
	}
	bool isEmpty() {
		return size <= 0;
	}
	bool isLess(int x1, int x2) {
		return x1 < x2;
	}
	bool isMore(int x1, int x2) {
		return x1 > x2;
	}
	bool isEqual(int x1, int x2) {
		return x1 == x2;
	}
	void swap(int i, int j) {
		int temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
	void heapify(int x) {
		int l = left(x);
		int r = right(x);
		int irl = x;
		if (l > 0) {
			if (isMore(data[l], data[x])) {
				irl = l;
			}
			if (r > 0 && isMore(data[r], data[irl])) {
				irl = r;
			}
			if (irl != x) {
				swap(x, irl);
				heapify(irl);
			}
		}
	}
	void insert(int *x) {//?
		int i;
		if (!isFull()) {
			data[i = ++size - 1] = *x;
			while (i > 0 && isLess(data[parent(i)], data[i])) {
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void *extractMax() {
		int *rc = NULL;
		if (!isEmpty()) {
			rc = &data[0];
			data[0] = data[size - 1];
			size--;
			heapify(0);
		}
		return rc;
	}
	void *extractMin() {
		int *rc = NULL, index = 0;
		if (!isEmpty()) {
			int min = data[0];
			for (int i = 1; i < size; i++) {
				if (data[i] < min) {
					min = data[i];
					index = i;
				}
			}
			if (index == 0) {
				rc = &data[0];
				size--;
			}
			else if (index == size - 1) {
				rc = &data[index];
				size--;
			}
			else {
				rc = &data[index];
				data[index] = data[size - 1];
				size--;
			}
			heapify(0);
		}
		return rc;
	}
	void *extractI() {
		int *rc = NULL;
		int index;
		cout << "Введите индекс "; cin >> index;
		if (!isEmpty()) {
			if (index < size) {
				rc = &data[index];
				data[index] = data[size - 1];
				size--;
				heapify(0);
			}
			else {
				cout << "Слишком большое значение.\n";
			}
		}
		return rc;
	}
	void scan(int i) {
		int space = 20;
		cout << '\n';
		if (size == 0) {
			cout << "Куча пуста.";
		}
		for (int u = 0, y = 0; u < size; u++) {
			cout << setw(space + 10) << setfill(' ');
			cout << data[u];
			if (u == y) {
				cout << '\n';
				if (y == 0) {
					y = 2;
				}
				else {
					y += y * 2;
				}
			}
			space /= 2;
		}
		cout << endl;
	}
	void unionHeap(int *temp, int size) {
		while (size != 0) {
			this->insert(temp);
			this->heapify(0);
			size--;
			temp++;
		}
	}
};
Heap Create(int maxsize) {
	return *(new Heap(maxsize));
}

void Tree::print() {
	cout << x;
}

int main(int argc, char *argv[]) {
	setlocale(0, "rus");
	int k, choice, ch;
	Heap h1 = Create(30);
	Heap h2 = Create(30);
	do {
		cout << "1 - Работа с кучей 1" << endl;
		cout << "2 - Работа с кучей 2" << endl;
		cout << "3 - Объединить кучи" << endl;
		cout << "0 - Выход" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1: {
			do
			{
				cout << "1 - Вывод на экран" << endl;
				cout << "2 - Добавить элемент" << endl;
				cout << "3 - Удалить максимальный" << endl;
				cout << "4 - Удалить минимальный" << endl;
				cout << "5 - Удалить i-тый" << endl;
				cout << "0 - Назад" << endl;
				cin >> choice;
				switch (choice) {
				case 1: {
					h1.scan(0);
				}
						break;
				case 2: {
					Tree *Node1 = new Tree;
					cout << "введите ключ" << endl;
					cin >> k;
					Node1->x = k;
					h1.insert(&k);
				}
						break;
				case 3: {
					h1.extractMax();
				}
						break;
				case 4: {
					h1.extractMin();
				}
						break;
				case 5: {
					h1.extractI();
				}
					break;
				}
			} while (choice != 0);
			break;
		}

		case 2: {
			do
			{
				cout << "1 - Вывод на экран" << endl;
				cout << "2 - Добавить элемент" << endl;
				cout << "3 - Удалить максимальный" << endl;
				cout << "4 - Удалить минимальный" << endl;
				cout << "0 - Назад" << endl;
				cin >> choice;
				switch (choice) {
				case 1: {
					h2.scan(0);
				}
						break;
				case 2: {
					Tree *Node2 = new Tree;
					cout << "введите ключ" << endl;
					cin >> k;
					Node2->x = k;
					h2.insert(&k);
				}
						break;
				case 3: {
					h2.extractMax();
				}
						break;
				case 4: {
					h2.extractMin();
				}
						break;
				case 5: {
					h2.extractI();
				}
						break;
				}
			} while (choice != 0);
			break;
		}

		case 3: {
			h1.unionHeap(h2.data, h2.size);
		}

		}
	} while (ch != 0);
}
