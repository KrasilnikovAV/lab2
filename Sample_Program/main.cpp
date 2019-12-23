#pragma once
#include <iostream>
#include "../TMatrix/TMatrix.h"

using namespace std;

int main()
{
	TMatrix<int> a(5), b(5), c(5);

	setlocale(LC_ALL, "Russian");
	cout << "������������ �������� ��������� ����������� ������" << endl;

	for (int i = 0; i < 5; i++) {
		for (int j = i; j < 5; j++)
		{
			a[i][j] = i * 10 + j;
			b[i][j] = (i * 10 + j) * 100;
		}
	}

	c = a + b;
	cout << "Matrix a = " << endl << a << endl;
	cout << "Matrix b = " << endl << b << endl;
	cout << "Matrix c = a + b" << endl << c << endl;
}