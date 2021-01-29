#include<iostream>
#include <stdlib.h>

using namespace std;

static int length;
void display(int*);
int* insertelem(int*, int);
int* deleteelem(int*, int);
int* transposeelems(int*);

int main() {

	cout << "数组长度：";
	cin >> length;
	int* p = new int[length] { 0 };

	srand((unsigned)time(NULL));
	for (int i = 0; i < length / 2; ++i)
		p[i] = (rand() % (100 - 0 + 1)) + 0;
	display(p);

	int index;
	cout << "插入位置：";
	cin >> index;
	p = insertelem(p, index);
	display(p);

	cout << "删除位置：";
	cin >> index;
	p = deleteelem(p, index);
	display(p);

	cout << "转置数据：\n";
	p = transposeelems(p);
	display(p);
	
	delete[]p;
	return 0;
}

void display(int* b) {
	for (int i = 0; i < length; ++i)
		cout << b[i] << " ";
	cout << endl;
}
int* insertelem(int* b, int index) {
	int* temp = new int[length];
	for (int i = 0; i < length; i++)
		temp[i] = b[i];

	length += 1;
	b = new int[length]{ 0 };
	for (int i = 0; i <= length; i++) {
		if (i < (index - 1))
			b[i] = temp[i];
		if (i >= index)
			b[i] = temp[i - 1];
	}
	delete [] temp;

	return b;
}
int* deleteelem(int* b, int index) {
	int* temp = new int[length];
	for (int i = 0; i < length; i++)
		temp[i] = b[i];
	display(temp);
	length -= 1;
	b = new int[length]{ 0 };
	for (int i = 0; i < (length - 1); i++) {
		if (i < (index - 1))
			b[i] = temp[i];
		if (i >= (index - 1))
			b[i] = temp[i + 1];
	}
	delete[] temp;

	return b;
}
int* transposeelems(int* b) {
	int a;
	for (int i = 0; i < length / 2; ++i) {
		a = b[i];
		b[i] = b[length - 1 - i];
		b[length - 1 - i] = a;
	}
	return b;
}