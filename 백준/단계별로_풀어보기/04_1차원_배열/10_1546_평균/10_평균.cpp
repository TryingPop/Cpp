/*
��¥ : 2024. 8. 5
�̸� : �輺��
���� : ���
	������ȣ : 1546��

	����, ��Ģ���� ������
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define max(A, B)	A < B ? B : A
using namespace std;

int main(void)
{

	int n, num, m = 0, sum = 0;
	FAST_IO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> num;
		sum += num;
		m = max(num, m);
	}

	cout << 100 * sum / (1.0 * n * m);
	return 0;
}