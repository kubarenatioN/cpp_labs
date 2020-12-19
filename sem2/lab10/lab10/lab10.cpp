#include <iostream>
#include <fstream>
using namespace std;

struct Person {
	char name[30];
	int age;
	Person *prev;
	Person *next;
};

Person *CreatePerson() {
	Person *temp = new Person;
	cout << "Введите имя: ";
	cin >> temp->name;
	cout << "Введите возраст: "; cin >> temp->age;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void Add(Person *temp, Person **b, Person **e) {
	if (*e == NULL) {
		*e = temp;
		*b = temp;
	}
	else {
		(*e)->next = temp;
		temp->prev = *e;
		*e = temp;
	}
}

void Print(Person *b) {
	Person *temp = b;
	while (temp) {
		cout << temp->name << endl;
		cout << temp->age << endl << endl;
		temp = temp->next;
	}
}

void Find(Person *b) {
	Person *temp = b;
	bool flag = true;
	int ch, age;
	char name[30];
	cout << "Искать по:" << endl;
	cout << "1 - Имени;\n";
	cout << "2 - Возрасту;\n";
	cin >> ch;
	switch (ch) {
	case 1:
		cout << "Введите имя: "; cin >> name;
		while (temp) {
			if (strcmp(temp->name, name) == 0) {
				cout << temp->name << endl;
				cout << temp->age << endl;
				flag = false;
			}
			temp = temp->next;
		}
		if (flag) {
			cout << "Ничего не найдено.\n";
			break;
		}
		break;
	case 2:
		cout << "Введите возраст: "; cin >> age;
		while (temp) {
			if (temp->age == age) {
				cout << temp->name << endl;
				cout << temp->age << endl;
				flag = false;
			}
			temp = temp->next;
		}
		if (flag) {
			cout << "Ничего не найдено.\n";
			break;
		}
		break;
	}	
}

void Delete(Person **b, Person **e) {
	Person *temp = *b;
	bool flag = true;
	int ch, age;
	char name[30];
	cout << "Удалять по:" << endl;
	cout << "1 - Имени;\n";
	cout << "2 - Возрасту;\n";
	cin >> ch;
	switch (ch) {
	case 1:
		cout << "Введите имя: "; cin >> name;
		while (temp) {
			if (strcmp(temp->name, name) == 0) {
				flag = false;
				if (temp == *b) {
					*b = (*b)->next;
					if (*b) {
						(*b)->prev = NULL;
					}
					else {
						*e = NULL;
					}
					temp = temp->next;
					delete temp->prev;
				}
				else {
					temp->prev->next = temp->next;
					if (temp != *e) {
						temp->next->prev = temp->prev;
					}
					else {
						*e = temp->prev;
					}
					temp = temp->next;
					delete temp->prev;
				}
				cout << "Элемент удален.\n";
				//break;
			}
			else {
				temp = temp->next;
			}
		}
		if (flag) {
			cout << "Ничего не удалено.\n";
			//break;
		}
		//else {
			/*if (temp == *b) {
				*b = (*b)->next;
				if (*b) {
					(*b)->prev = NULL;
				}
				else {
					*e = NULL;
				}
				delete temp;
			}
			else {
				temp->prev->next = temp->next;
				if (temp != *e) {
					temp->next->prev = temp->prev;
				}
				else {
					*e = temp->prev;
				}
				delete temp;
			}
			cout << "Элемент удален.\n";*/
		//}
		break;
	case 2:
		cout << "Введите возраст: "; cin >> age;
		while (temp) {
			if (temp->age == age) {
				flag = false;
				//break;
				if (temp == *b) {
					*b = (*b)->next;
					if (*b) {
						(*b)->prev = NULL;
					}
					else {
						*e = NULL;
					}
					temp = temp->next;
					delete temp->prev;
				}
				else {
					temp->prev->next = temp->next;
					if (temp != *e) {
						temp->next->prev = temp->prev;
					}
					else {
						*e = temp->prev;
					}
					temp = temp->next;
					delete temp->prev;
				}
				cout << "Элемент удален.\n";
			}
			else {
				temp = temp->next;
			}
		}
		if (flag) {
			cout << "Ничего не удалено.\n";
			break;
		}
		else {
			/*if (temp == *b) {
				*b = (*b)->next;
				if (*b) {
					(*b)->prev = NULL;
				}
				else {
					*e = NULL;
				}
				delete temp;
			}
			else {
				temp->prev->next = temp->next;
				if (temp != *e) {
					temp->next->prev = temp->prev;
				}
				else {
					*e = temp->prev;
				}
				delete temp;
			}
			cout << "Элемент удален.\n";*/
		}
		break;
	}
}

void Input(Person *b, ofstream &f) {
	Person *temp = b;
	while (temp) {
		f << temp->name << '\n';
		f << temp->age << '\n';
		f << '\n';
		temp = temp->next;
	}
}

void Output(Person **e, Person **b, ifstream &f) {
	char buffer[30];
	while (!f.eof()) {
		f.getline(buffer, sizeof(buffer));
		if (strcmp(buffer, "") == 0) {
			continue;
		}
		else {
			Person *temp = new Person;
			temp->next = NULL;
			temp->prev = NULL;
			strcpy_s(temp->name, buffer);
			f.getline(buffer, sizeof(buffer));
			temp->age = atoi(buffer);
			Add(temp, b, e);
		}
	}
}

void Min(Person *b) {
	Person *temp = b;
	char name[30];
	strcpy_s(name, temp->name);
	int min = temp->age;
	while (temp->next) {
		if (temp->next->age < min) {
			min = temp->next->age;
			strcpy_s(name, temp->next->name);
		}
		temp = temp->next;
	}
	cout << "Наименьший по возрасту элемент списка :\n";
	cout << name << endl;
	cout << min << endl;
}

void Menu() {
	cout << "-------------------\n";
	cout << "Выберите действие:\n";
	cout << "1 - Добавить элемент в список;\n";
	cout << "2 - Вывести список;\n";
	cout << "3 - Найти элемент списка;\n";
	cout << "4 - Удалить элемент списка;\n";
	cout << "5 - Запись в файл;\n";
	cout << "6 - Чтение из файла;\n";
	cout << "7 - Найти минимальный;\n";
	cout << "0 - Выход.\n";
	cout << "-------------------\n";
}

void main() {
	setlocale(0, "rus");
	int choice;
	Person *begin, *end;
	begin = NULL;
	end = begin;
	ofstream inFile;
	ifstream fromFile;
	do {
		Menu();
		cin >> choice;
		switch (choice) {
		case 1:
			Add(CreatePerson(), &begin, &end);
			break;
		case 2:
			Print(begin);
			break;
		case 3:
			Find(begin);
			break;
		case 4:
			Delete(&begin, &end);
			break;
		case 5:
			inFile.open("file.txt");
			Input(begin, inFile);
			inFile.close();
			break;
		case 6:
			fromFile.open("file.txt");
			Output(&end, &begin, fromFile);
			fromFile.close();
			break;
		case 7:
			Min(begin);
			break;
		}
	} while (choice != 0);
}