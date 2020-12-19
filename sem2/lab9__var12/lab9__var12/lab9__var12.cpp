#include <iostream>
#include <fstream>

using namespace std;

int maxQSize, //Максимальный размер очереди 
	currentQSize = 0;//Текущий размер очереди, в начале равен 0

struct Element {
	char symbol;
	Element *next;
};

void Push(Element **h, Element **t) {
	int n, count = 0, flag = 0;
	char s;
	Element *p = *h;
	cout << "Сколько элементов вы хотите добавить? "; cin >> n;
	if (currentQSize + n < maxQSize + 1) {//Если есть место в очереди
		for (int i = 0; i < n; i++) {//Проходим цикл
			cout << "Введите значение: "; cin >> s;//Вводим символ
			Element *temp = new Element;//Создаем временный узел списка
			temp->symbol = s;//Заполняем его символом
			temp->next = NULL;//Следующий после temp будет NULL
			if (*h == NULL) {//Если изначально очередь пуста
				*h = *t = temp;//То и голова и хвост указывают на данный узел temp
			}
			else {
				(*t)->next = temp;//Следующий после хвоста будет temp
				*t = temp;//Теперь хвост указывает на temp
			}
			currentQSize++;//Увеличиваем текущий размер очереди
			if (flag) {//flag позволяет пропустить одну итерацию цикла, чтобы заполнить символом голову
				if (s == (*h)->symbol) {//Если вводимый символ совпадает с символом в голове очереди
					while (*h != NULL) {//То проходим цикл
						p = p->next;//Сдвигаем указатели, т.е. идем по очереди от головы к хвосту
						count++;//Увеличиваем размер счетчика, т.е. считаем размер очереди
						Element *temp;
						temp = (*h);//Временная переменная указывает на голову очереди
						*h = (*h)->next;//Голову переопределяем на следующий после головы элемент
						cout << temp->symbol << endl;//Выводим значение temp(это же голова)
						delete temp;//Очищаем память
						currentQSize--;//Уменьшаем размер очереди на 1
					}
					cout << "Размер очереди равен: " << count << endl;//Выводим размер очереди
					break;
				}
			}
			flag = 1;
		}
	}
	else {
		cout << "Размер превышен.\n";
	}
}

void Pop(Element **h) {
	int n;
	cout << "Сколько элементов очереди вывести? "; cin >> n;
	if (n < currentQSize + 1) {//Если хотим достать не больше чем уже есть в очереди
		for (int i = 0; i < n; i++) {//То проходим цикл и выводим и удаляем из очереди
			Element *temp;
			temp = (*h);//Временная переменная указывает на голову очереди
			*h = (*h)->next;//Голову переопределяем на следующий после головы элемент
			cout << temp->symbol << endl;//Выводим значение temp(это же голова)
			delete temp;//Очищаем память
			currentQSize--;//Уменьшаем размер очереди на 1
		}
	}
	else {
		cout << "Слишком большое значение.\n";
	}
}

void Delete(Element **h) {
	if (currentQSize > 0) {
		while (*h != NULL) {
			Element *temp;//Временная переменная
			temp = new Element;//Выделяем под нее память
			temp = *h;//Даем ей тот же адрес на который указывает h
			*h = (*h)->next;//Переопределем голову на следующий элемент
			delete temp;//Очищаем память
			currentQSize--;
		}
		cout << "Очередь очищена" << endl;
	}
	else {
		cout << "Очередь пуста.\n";
	}
}

void GetDimension(Element *h) {
	Element *p = h;
	int count = 0;
	if (p != NULL) {//Если очередь не пуста
		while (p != NULL) {//Пока она не очистится
			p = p->next;//Сдвигаем указатели, т.е. идем по очереди от головы к хвосту
			count++;//Увеличиваем размер счетчика
		}
		cout << "В очереди " << count << " элементов\n";
	}
	else {
		cout << "Очередь пуста.\n";
	}
}

void Menu() {
	cout << "\n-------------------\n";
	cout << "Выберите действие:\n";
	cout << "1 - Добавить элементы в очередь;\n";
	cout << "2 - Вывести элементы из очереди;\n";
	cout << "3 - Удалить очередь;\n";
	cout << "4 - Определить размер очереди;\n";
	cout << "0 - Выход.\n";
	cout << "-------------------\n";
}

void main() {
	setlocale(0, "rus");
	int choice; //Выбор пользователя
	cout << "Введите размер очереди: "; cin >> maxQSize;
	Element *head, *tail;
	head = NULL;//Голова в начале указывает на NULL
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
		}
	} while (choice != 0);
}