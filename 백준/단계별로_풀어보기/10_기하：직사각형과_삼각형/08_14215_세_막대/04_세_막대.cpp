/*
��¥ : 2024. 8. 17
�̸� : �輺��
���� : �� ����
	������ȣ : 14215��

	����, ����, ������ ������
*/

#include <iostream>

#define min(a, b)	(((a) < (b)) ? (a) : (b))
using namespace std;

int main(void)
{

	int a, b, c;
	cin >> a >> b >> c;

	if (b <= a && c <= a) a = min(a, b + c - 1);
	else if (a <= b && c <= b) b = min(b, a + c - 1);
	else c = min(c, a + b - 1);

	cout << a + b + c;
	return 0;
}