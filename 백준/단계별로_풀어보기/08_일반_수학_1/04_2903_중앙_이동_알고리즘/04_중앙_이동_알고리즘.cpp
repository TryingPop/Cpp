/*
��¥ : 2024. 8. 12
�̸� : �輺��
���� : �߾� �̵� �˰���
	������ȣ : 2903��

	���� ������
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int n, x;
	FAST_IO;

	cin >> n;
	x = 1 << n;
	x++;

	cout << x * x;
	return 0;
}