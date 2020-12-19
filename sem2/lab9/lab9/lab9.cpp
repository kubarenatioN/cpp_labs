#include <iostream>
#include <fstream>

using namespace std;

int queueDimension, currentDimension = 0;

struct Element {
	int value;
	Element *next;
};

void Push(Element **h, Element **t) {
	int val, ch, n;
	cout << "1 - Добавить один элемент очереди;\n";
	cout << "2 - Добавить несколько элементов очереди;\n";
	cin >> ch;
	switch (ch) {
	case 1:
		if (currentDimension < queueDimension) {
			cout << "Введите значение: "; cin >> val;
			Element *temp = new Element;
			temp->value = val;
			temp->next = NULL;
			if (*h == NULL) {
				*h = *t = temp;
			}
			else {
				(*t)->next = temp;
				*t = temp;
			}
			currentDimension++;
		}
		else {
			cout << "Размер превышен.\n";
		}
		break;
	case 2:
		cout << "Сколько элементов вы хотите добавить? "; cin >> n;
		if (currentDimension + n < queueDimension + 1) {
			for (int i = 0; i < n; i++) {
				cout << "Введите значение: "; cin >> val;
				Element *temp = new Element;
				temp->value = val;
				temp->next = NULL;
				if (*h == NULL) {
					*h = *t = temp;
				}
				else {
					(*t)->next = temp;
					*t = temp;
				}
				currentDimension++;
			}
		}
		else {
			cout << "Размер превышен.\n";
		}
		break;
	}
}

void Pop(Element **h) {
	int n;
	cout << "Сколько элементов очереди достать? "; cin >> n;
	if (n < currentDimension + 1) {
		for (int i = 0; i < n; i++) {
			Element *temp;
			temp = (*h);
			*h = (*h)->next;
			cout << temp->value << endl;
			delete temp;
			currentDimension--;
		}
	}
	else {
		cout << "Слишком большое значение.\n";
	}
}

void Delete(Element **h) {
	if (currentDimension > 0) {
		while (currentDimension != 0) {
			Element *temp;
			temp = new Element;
			temp = *h;
			*h = (*h)->next;
			delete temp;
			currentDimension--;
		}
	}
	else {
		cout << "Очередь очищена.\n";
	}
}

void GetDimension(Element *h) {
	Element *p = h;
	int count = 0;
	if (p != NULL) {
		while (p != NULL) {
			p = p->next;
			count++;
		}
		cout << "В очереди " << count << " элементов\n";
	}
	else {
		cout << "Очередь пуста.\n";
	}
}

void TillNull(Element *h) {
	Element *p = h;
	int count = 0, max;
	//while (p->value != 0) {
	while (p != NULL) {
		if (p->value == 0) {
			break;
		}
		else {
			cout << p->value << endl;
			p = p->next;
		}
	}
	if (p != NULL) {
		cout << p->value << endl;
		p = p->next;
	}
	/*cout << p->value << endl;
	p = p->next;*/
	while (p != NULL) {
		count++;
		p = p->next;
	}
	cout << "Размер оставшейся очереди равен " << count << endl;
	delete p;
	Element *q = h, *next;
	max = q->value;
	next = q->next;
	while (next != NULL) {
		if (next->value > max) {
			max = next->value;
		}
		next = next->next;
	}
	cout << "Максимальный элемент очереди: " << max << endl;
}

void Menu() {
	cout << "\n-------------------\n";
	cout << "Выберите действие:\n";
	cout << "1 - Добавить элементы очереди;\n";
	cout << "2 - Достать элементы очереди;\n";
	cout << "3 - Очистить очередь;\n";
	cout << "4 - Определить размер очереди;\n";
	cout << "5 - Функция варианта;\n";
	cout << "0 - Выход.\n";
	cout << "-------------------\n";
}

void main() {
	setlocale(0, "rus");
	int choice;
	cout << "Введите размер очереди: "; cin >> queueDimension;
	Element *head, *tail;
	head = NULL;
	do {
		Menu();
		cin >> choice;
		switch (choice) {
		case 1:
			Push(&head, &tail);
			break;
		case 2:
			Pop(&head);
			break;
		case 3:
			Delete(&head);
			break;
		case 4:
			GetDimension(head);
			break;
		case 5:
			TillNull(head);
			break;
		}
	} while (choice != 0);
}