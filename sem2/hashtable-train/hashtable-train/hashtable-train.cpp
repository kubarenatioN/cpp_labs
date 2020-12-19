#include <iostream>
#include <ctime>
using namespace std;

int tsize = 20, N = 0;
static void *DEL = (void*)-1;
struct Table {
	int key;
	char str[20];
};

int hashFn1(int key, int m, int p) {
	return (key + p) % m;
}

int hashFn2(int hash1, int m, int p) {
	return (hash1 + 5 * p + 3 * p*p) % m;
}

void Insert(void **table, Table *temp) {
	bool inserted = false;
	for (int i = 0, j = hashFn1(temp->key, tsize, 0);
		i != tsize && !inserted; j = hashFn2(j, tsize, ++i)) {
		if (table[j] == NULL || table[j] == DEL) {
			table[j] = temp;
			inserted = true;
			N++;
		}
	}
}

void Print(void **table) {
	for (int i = 0; i < tsize; i++) {
		if (table[i] == NULL) {
			cout << i << ". NULL" << endl;
		}
		else if (table[i] == DEL) {
			cout << i << ". DEL" << endl;
		}
		else {
			cout << i << ". " << ((Table*)table[i])->key << " " << ((Table*)table[i])->str << endl;
		}
	}
}

void main() {
	setlocale(0, "rus");
	srand(time(0));
	void **table = new void *[tsize];
	for (int i = 0; i < tsize; i++) {
		table[i] = NULL;
	}
	for (int i = 0; i < 5; i++) {
		Table *temp = new Table;
		cout << "Введите строку ";
		cin >> temp->str;
		temp->key = rand() % 100 + 1;
		Insert(table, temp);
	}
	Print(table);
}