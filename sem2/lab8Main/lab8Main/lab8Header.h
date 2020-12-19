#pragma once

int menuChoice;
int numOfElements = 0;

struct Element {
	int value;
	Element *next;
};

void Push(Element **begin, int val);

void Pop(Element **begin);

void Clear(Element **begin);

void Input(Element *begin, ofstream &f);

void Output(Element **begin, ifstream &f);

void Count(Element *begin);

void Menu();