#include <iostream>
#include <ctime>
using namespace std;

struct Tree {
	int key;
	Tree *left;
	Tree *right;
};

void Add(Tree **root, int key) {
	if (*root == NULL) {
		*root = new Tree;
		(*root)->key = key;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else {
		if (key > (*root)->key) {
			Add(&(*root)->right, key);
		}
		else if (key <= (*root)->key) {
			Add(&(*root)->left, key);
		}
	}
}

void Print(Tree *root, int level) {
	if (root->right != NULL) {
		Print(root->right, level + 1);
	}
	for (int i = 0; i < level; i++) {
		cout << "   ";
	}
	cout << root->key << endl;
	if (root->left != NULL) {
		Print(root->left, level + 1);
	}
}

int Search(Tree *root, int key) {
	int res = -1;
	if (root != NULL) {
		if (key > root->key) {
			Search(root->right, key);
		}
		else if (key < root->key) {
			Search(root->left, key);
		}
		else {
			res = root->key;
			return res;
		}
	}
	else {
		return res;
	}
}

void main() {
	setlocale(0, "rus");
	srand(time(0));
	int key;
	Tree *root = NULL;

	for (int i = 0; i < 8; i++) {
		Add(&root, rand() % 100 + 1);
	}
	Print(root, 0);
	cout << "Поиск элемента с ключом "; cin >> key;
	if (Search(root, key) != -1) {
		cout << "Найден элемент с ключом " << Search(root, key) << endl;
	}
	else {
		cout << "Такого ключа нет\n";
	}
}