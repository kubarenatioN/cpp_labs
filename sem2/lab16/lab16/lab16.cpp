#include <iostream>
#include <ctime>
#include <new>
using namespace std;

void Heapify(int A[], int pos, int n) {
	int t, tm;
	while (2 * pos + 1 < n) {//Пока у элемента с A[pos] не будет хотя бы одного потомка
		t = 2 * pos + 1;
		if (2 * pos + 2 < n && A[2 * pos + 2] >= A[t]) {
			//Если есть правый потомок и он >= левого потомка
			t = 2 * pos + 2;//То индекс наибольшего элемента в поддереве из A[pos] и 
							//двух потомков равен индексу правого потомка		
		}
		if (A[pos] < A[t]) {//Если корень меньше одного из потомков
			tm = A[pos];	//Свапаем
			A[pos] = A[t];
			A[t] = tm;
			pos = t;		//И pos становится индексом того потомка,
							//С кем свапнулись
		}
		else break;			//Если соблюдается правило кучи в поддереве из A[pos] и его
							//Двух потомков, то пропускаем
	}
}

void PiramSort(int A[], int n) {
	int temp;
	for (int i = n - 1; i >= 0; i--) {
		Heapify(A, i, n);//Восстановление кучи
	}
	while (n > 0) {
		temp = A[0];
		A[0] = A[n - 1];
		A[n - 1] = temp;
		n--;
		Heapify(A, 0, n);
	}
}

void mergeSort(int *A, int start, int end) {//Посылаем массив, начало(0) и конец(размер массива)
	if (end - start < 2) {
		return;
	}
	if (end - start == 2) {//На глубине рекурсии попадаем сюда и выходим рекурсивно
		if (A[start] > A[start + 1]) {
			swap(A[start], A[start + 1]);
		}
		return;
	}//Если >2 элементов
	mergeSort(A, start, start + (end - start) / 2);//Вызываем рекурсивно функцию для левой и
	mergeSort(A, start + (end - start) / 2, end);//правой частей массива
	int *B = new int[end];//Вспомогательный массив
	int s1 = start;//Начало первой половины
	int e1 = start + (end - start) / 2;//Конец первой половины(середина)
	int s2 = e1;
	int Bsize = 0;//Кол-во элементов в массиве B
	while (Bsize < end - start) {//Пока не заполнится
		if (s1 >= e1 || (s2 < end && A[s2] <= A[s1])) {//Если минимальный во второй половине
			B[Bsize] = A[s2];//Он записывается
			Bsize++;
			++s2;
		}
		else {//В противном случае записывается минимальный из первой части массива
			B[Bsize] = A[s1];
			Bsize++;
			++s1;
		}
	}
	for (int i = start; i < end; ++i) {
		A[i] = B[i - start];//Перезаписываем в исходный массив данные
	}
}

void main() {
	setlocale(0, "rus");
	srand(time(0));
	int *A, *B, *C, mA, mB = 0;
	int time_s, time_e;
	cout << "Введите размер массива A: ";
	cin >> mA;
	A = new int[mA];
	B = new int[mA];
	C = new int[mA];
	for (int i = 0; i < mA; i++) {
		*(A + i) = rand() % 100;
	}
	cout << "Массив A:\n";
	/*for (int i = 0; i < mA; i++) {
		cout << A[i] << " ";
	}*/
	cout << '\n';
	time_s = clock();
	for (int i = 0; i < mA; i++) {
		if (A[i] % 2 == 0) {
			B[mB] = A[i];
			mB++;
		}
	}
	time_e = clock();
	mB = 0;
	for (int i = 0; i < mA; i++) {
		if (A[i] % 2 == 0) {
			C[mB] = A[i];
			mB++;
		}
	}
	cout << "Массив B:\n";
	/*for (int i = 0; i < mB; i++) {
		cout << B[i] << " ";
	}*/
	cout << endl;
	cout << endl << "Времени на фильтрацию: " << time_e - time_s << endl;

	time_s = clock();
	PiramSort(B, mB);
	time_e = clock();
	cout << "Пирамидальная сортировка: \n";
	/*for (int i = 0; i < mB; i++) {
		cout << B[i] << " ";
	}*/
	cout << endl << "Пирамидальная сортировка: " << time_e - time_s << endl;
	for (int i = 0; i < mB; i++) {//Делаем B снова не отсортированным
		B[i] = C[i];
	}
	cout << endl;
		
	time_s = clock();
	mergeSort(B, 0, mB);
	time_e = clock();

	cout << "Сортировка слиянием: \n";
	/*for (int i = 0; i < mB; i++) {
		cout << B[i] << " ";
	}*/
	cout << endl << "Сортировка слиянием: " << time_e - time_s << endl;
	delete A;
	delete B;
	delete C;
}