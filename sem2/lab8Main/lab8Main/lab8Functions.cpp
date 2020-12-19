//#include "stdafx.h"
#include <iostream>
#include "lab8Header.h"
using namespace std;

void Push(Element **begin, int val) {
	Element *temp = new Element;
	temp->value = val;
	temp->next = *begin;
	*begin = temp;
}

void Pop(Element **begin) {
	Element *temp = *begin;
	cout << temp->value << endl;
	*begin = (*begin)->next;
	delete temp;
}

void Clear(Element **begin) {
	Element *temp;
	while (*begin) {
		temp = *begin;
		*begin = (*begin)->next;
		delete temp;
		numOfElements--;
	}
	cout << "���� ������.\n";
}

void Input(Element *begin, ofstream &f) {
	Element *p = begin;
	if (numOfElements > 0) {
		while (p) {
			f << '\n' << p->value;
			p = p->next;
		}
	}
	else {
		cout << "������ ����������. ���� ����.\n";
	}
}

void Output(Element **begin, ifstream &f) {
	char buffer[10];
	int val;
	f.getline(buffer, sizeof(buffer));
	while (!f.eof()) {
		Element *temp = new Element;
		f.getline(buffer, sizeof(buffer));
		val = atoi(buffer);
		temp->value = val;
		temp->next = *begin;
		*begin = temp;
		numOfElements++;
	}
}

void Count(Element *begin) {
	Element *prev, *cur, *next;
	int amount = 0;
	if (numOfElements > 2) {
		prev = begin;
		cur = begin->next;
		next = cur->next;
		while (next != NULL) {
			if (prev->value == next->value) {
				amount++;
			}
			prev = cur;
			cur = next;
			next = next->next;
		}
		cout << "���������� ��������� � ����������� ��������: " << amount << endl;
	}
	else {
		cout << "������������ ���������.\n";
	}
}

void Menu() {
	cout << "\n-------------------\n";
	cout << "�������� ��������:\n";
	cout << "1 - �������� �������� �����;\n";
	cout << "2 - ������� �������� �����;\n";
	cout << "3 - �������� ����;\n";
	cout << "4 - �������� �������� ����� � ����;\n";
	cout << "5 - ������� �������� ����� �� �����;\n";
	cout << "6 - ���������� ���-�� ������ �������;\n";
	cout << "0 - �����.\n";
	cout << "-------------------\n";
}