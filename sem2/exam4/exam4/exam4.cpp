#include <iostream>
#include <ctime>
using namespace std;

struct Tree {
	int key;
	Tree *left;
	Tree *right;
};

void addNode(Tree **root, int val) {
	if (*root == NULL) {
		*root = new Tree;
		(*root)->key = val;
		(*root)->left = (*root)->right = NULL;
	}
	else if (val > (*root)->key) {
		addNode(&(*root)->right, val);
	}
	else {
		addNode(&(*root)->left, val);
	}
}

void Print(Tree *root, int level) {
	if (root) {
		Print(root->right, level + 1);
		for (int i = 0; i < level; i++) {
			cout << "   ";
		}
		cout << root->key << ' ' << endl;
		Print(root->left, level + 1);
	}
} 

void Search(Tree *root, int key) {
	if (root != NULL) {
		if (key > root->key) {
			Search(root->right, key);
		}
		else if (key < root->key) {
			Search(root->left, key);
		}
		else {
			cout << "Найден узел с ключом " << root->key << endl;
		}
	}
	else {
		cout << "Такого узла нет." << endl;
	}
}


void main() {
	setlocale(0, "rus");
	srand(time(0));
	int value, skey;
	Tree *root = NULL;

	for (int i = 0; i<8; i++) {
		addNode(&root, rand() % 100 + 1);
	}
	Print(root, 0);
	cout << "Введите ключ для поиска: ";
	cin >> skey;
	
	Search(root, skey);

	cout << '\n';

}