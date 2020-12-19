#include <iostream>
using namespace std;

struct List {
	int key;
	List *next;
};

void Add(List **begin, List **end, int k) {
	List *temp = new List;
	temp->key = k;
	temp->next = NULL;
	if (*end == NULL) {
		*end = temp;
		*begin = temp;
	}
	else {
		(*end)->next = temp;
		*end = (*end)->next;
	}
}

void Print(List *begin) {
	List *temp = begin;
	while (temp) {
		cout << temp->key << " --> ";
		temp = temp->next;
	}
	cout << "NULL";
}

void Del(List *begin, int num) {
	List *prev = begin;
	List *cur = begin->next;
	for (int i = 0; i < num - 2; i++) {
		cur = cur->next;
		prev = prev->next;
	}
	prev->next = cur->next;
	delete cur;
}

void main() {
	setlocale(0, "rus");
	int key;
	List *begin = new List;
	begin = NULL;
	List *end = begin;
	while (1) {
		cout << "Введите ключ: ";
		cin >> key;
		if (key <= 0) break;
		Add(&begin, &end, key);
	}

	Print(begin);
	cout << endl << "Удаление 3го узла: " << endl;
	Del(begin, 3);
	Print(begin);
}