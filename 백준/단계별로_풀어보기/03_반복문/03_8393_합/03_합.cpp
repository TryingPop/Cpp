/*
��¥ : 2024. 8. 1
�̸� : �輺��
���� : ��
	������ȣ : 8393��

	����, ���� ������
*/

#include <iostream>

#define fastio cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int n;

	fastio;
	cin >> n;

	cout << (n * n + n) / 2;

	return 0;
}