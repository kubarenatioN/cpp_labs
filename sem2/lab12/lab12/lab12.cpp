#include <iostream>
#include <fstream>
using namespace std;

struct Tree {
	int key;
	Tree *left, *right; // указатели на левое и правое поддерево
};

Tree *root = NULL; //создаем указатель на корень

Tree *createNode(int key) { // Создание узла дерева
	Tree *temp = new Tree;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

Tree *insertNode(Tree *root, int key) {// Добавление элемента в дерево
	Tree *prev = NULL;
	int find = 0;
	while (root && !find) {
		prev = root;
		if (key == root->key) {
			find = 1;
		}
		else if (key < root->key) {
			root = root->left;
		}
		else {
			root = root->right;
		}
	}
	if (!find) {
		root = createNode(key);
		if (key < prev->key) {
			prev->left = root;
		}
		else {
			prev->right = root;
		}
	}
	return root;
}

Tree *makeTree(Tree *root, ifstream &f) { // Создание дерева
	int key;
	char buffer[10];
	f.getline(buffer, 10);
	key = atoi(buffer);

	if (root == NULL) {
		root = createNode(key);
	}
	while (!f.eof()) {
		f.getline(buffer, 10);
		key = atoi(buffer);
		insertNode(root, key);
	}
	return root;
}

Tree *searchNode(Tree *root, int key) {// Поиск по ключу
	Tree *temp = root;
	if (temp != NULL) {
		if (key < temp->key) {
			temp = searchNode(root->left, key);
		}
		else if (key > temp->key) {
			temp = searchNode(root->right, key);
		}
	}
	return temp;
}

Tree *deleteNode(Tree *root, int key) {// Удаление узла
	Tree *del, *prev_del, *replce, *prev_replce;
	del = root;
	prev_del = NULL;
	while (del != NULL && del->key != key) {//Пока не найдем значение или NULL
		prev_del = del;
		if (key < del->key) {
			del = del->left;//Идем влево
		}
		else {
			del = del->right;//Идем вправо
		}
	}
	if (del == NULL) {
		puts("\nТакого ключа нет");
		return root;
	}
	if (del->right == NULL) {//Если правый NULL
		replce = del->left;
	}
	else if (del->left == NULL) {
		replce = del->right;
	}
	else {//Ищем самый правый в левом поддереве
		prev_replce = del;
		replce = del->left;
		while (replce->right != NULL) {
			prev_replce = replce;
			replce = replce->right;
		}
		if (prev_replce == del) {
			replce->right = del->right;
		}
		else {
			replce->right = del->right;
			prev_replce->right = replce->left;
			replce->left = prev_replce;
		}
	}
	if (del == root) {
		root = replce;
	}
	else {//Поддерево replce присоединяется к родителю удаляемого узла
		if (del->key < prev_del->key) {
			prev_del->left = replce;//На левую ветвь
		}
		else {
			prev_del->right = replce;//На правую ветвь
		}
	}
	int temp = del->key;
	cout << "\nУдален элемент с ключом " << temp << endl;
	delete del;
	return root;
}

void view(Tree *temp, int level) {//Вывод дерева
	if (temp) {
		view(temp->right, level+1);
		for (int i = 0; i < level; i++) {
			cout << "   ";
		}
		int tm = temp->key;
		cout << tm << endl;
		view(temp->left, level+1);
	}
}

void Input(Tree *root, ofstream &f) {
	if (root) {
		Input(root->left, f);
		
		f << root->key << '\n';

		Input(root->right, f);
	}
}

void clearTree(Tree *temp) {
	if (temp) {
		clearTree(temp->left);
		clearTree(temp->right);
		delete temp;
		root = NULL;
	}
}

void main() {
	setlocale(0, "rus");
	int key, choice;
	Tree *rc;
	ifstream fromFile;
	ofstream inFile;
	do {
		cout << "1 - создание дерева из файла\n";
		cout << "2 - добавление элемента\n";
		cout << "3 - поиск по ключу\n";
		cout << "4 - удаление элемента\n";
		cout << "5 - вывод дерева\n";
		cout << "6 - записать дерево в файл\n";
		cout << "7 - очистка дерева\n";
		cout << "0 - выход\n";
		cin >> choice;
		cout << '\n';
		switch (choice) {
		case 1:
			fromFile.open("file.txt");
			root = makeTree(root, fromFile);
			fromFile.close();
			break;
		case 2:
			cout << "\nВведите ключ: "; cin >> key;
			insertNode(root, key);
			break;
		case 3:
			cout << "\nВведите ключ: "; cin >> key;
			rc = searchNode(root, key);
			if (rc) {
				cout << "Найденный ключ: " << rc->key << endl;
			}
			else {
				cout << "Такого элемента нет" << endl;
			}
			break;
		case 4:
			cout << "\nВведите удаляемый ключ: "; cin >> key;
			root = deleteNode(root, key);
			break;
		case 5:
			if (root == NULL) {
				cout << "Дерево пустое" << endl;
			}
			else if (root->key >= 0) {
				cout << "Дерево:" << endl;
				view(root, 0);
			}
			else {
				cout << "Дерево пустое\n";
			}
			break;
		case 6:
			inFile.open("file2.txt");
			Input(root, inFile);
			inFile.close();
			break;
		case 7:
			clearTree(root);
			break;
		}
	} while (choice != 0);
}