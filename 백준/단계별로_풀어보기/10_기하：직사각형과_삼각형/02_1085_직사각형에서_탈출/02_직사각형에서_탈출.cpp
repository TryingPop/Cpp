/*
��¥ : 2024. 8. 16
�̸� : �輺��
���� : ���簢������ Ż��
	������ȣ : 1085��

	����, ������ ������
*/

#include <iostream>

#define min(X, Y)	(((X) < (Y)) ? (X) : (Y))
#define abs(X)		(((X) < 0) ? -(X) : (X))
using namespace std;

int main(void)
{

	int w, h, x, y;
	cin >> x >> y >> w >> h;
	cout << min(min(x, abs(w - x)), min(y, abs(h - y)));
}