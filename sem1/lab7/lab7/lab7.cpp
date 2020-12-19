#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "rus");
	int i;
	for (i = 100; i < 1000; i++) {
		if (i / 100 != (i % 100) / 10 && i / 100 != i % 10 && (i % 100) / 10 != i % 10) {
			cout << i << endl;
		}
	}
}