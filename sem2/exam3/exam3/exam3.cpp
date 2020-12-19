#include <iostream>
using namespace std;

struct Q {
	int data;
	char str[20];
	Q *next;
};

void Push(Q **begin, Q **end, int val, char *str) {
	Q *temp = new Q;
	temp->data = val;
	strcpy_s(temp->str, str);
	temp->next = NULL;
	if (*begin == NULL) {
		*begin = temp;
		*end = temp;
	}
	else {
		(*end)->next = temp;
		*end = temp;
	}
}

void Print(Q *begin) {
	while(begin) {
		cout << begin->data << " -- " << begin->str << endl;
		begin = begin->next;
	}
}

void Del(Q **begin) {
	Q *cur = (*begin)->next;
	Q *prev = *begin;
	while (cur) {
		Q *buf = cur;
		cur = cur->next;
		prev->next = cur;
		delete buf;
		cur = cur->next;
		prev = prev->next;
	}
}

void main() {
	setlocale(0, "rus");
	int value, n;
	char str[20];

	Q *begin = NULL;
	Q *end = begin;

	while (1) {
		cout << "Введите число: ";
		cin >> value;
		if (value <= 0) {
			break;
		}
		cout << "Введите строку: ";
		cin >> str;
		Push(&begin, &end, value, str);
	}
	Print(begin);

	Del(&begin);

	Print(begin);
}