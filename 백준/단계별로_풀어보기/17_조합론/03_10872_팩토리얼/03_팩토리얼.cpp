/*
��¥ : 2024. 9. 3
�̸� : �輺��
���� : ���丮��
	������ȣ : 10872��

	����, ���� ������
*/

#include <iostream>

using namespace std;

inline int Factorial(int _n)
{

	if (_n <= 0) return 1;
	return _n * Factorial(_n - 1);
}

int main(void)
{

	int n;
	cin >> n;
	cout << Factorial(n);
	return 0;
}