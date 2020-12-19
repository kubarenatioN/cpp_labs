#include <iostream>
using namespace std;

struct Stack {
	int val;//key
	Stack *next;
};

void Push(Stack **begin, Stack **end, int value) {
	Stack *temp = new Stack;
	temp->val = value;
	if (*begin == NULL) {
		temp->next = NULL;
		*begin = temp;
		*end = temp;
	}
	else {
		temp->next = *end;
		*end = temp;
	}
}

void Pop(Stack **end, int n) {
	Stack *temp;
	if (n == 0) return;
	for (int i = 0; i < n; i++) {
		cout << (*end)->val << ", ";
		temp = *end;
		*end = (*end)->next;
		delete temp;
	}
	cout << "удалены\n";
}

void Print(Stack *end) {
	while (end) {
		cout << end->val << " --> ";
		end = end->next;
	}
	cout << "NULL" << endl;
}

void main() {
	setlocale(0, "rus");
	Stack *begin = NULL;
	Stack *end = begin;
	int val, n;

	while (1) {
		cout << "Введите данные: ";
		cin >> val;
		if (!(val > 0)) {
			break;
		}
		Push(&begin, &end, val);
	}
	Print(end);
	while (1) {
		cout << "Сколько элементов извлечь: ";
		cin >> n;
		if (n < 0) {
			break;
		}
		Pop(&end, n);
	}
	Print(end);
}