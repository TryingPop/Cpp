/*
��¥ : 2024. 8. 1
�̸� : �輺��
���� : ������
	������ȣ : 25304��

	����, ����, ��Ģ���� ������
*/

#include <iostream>

#define fastio cin.tie(NULL);	\
			cout.tie(NULL);		\
			ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int n, sum = 0;
	int len, p, k;
	cin >> n >> len;

	for (int i = 0; i < len; i++)
	{

		cin >> p >> k;
		sum += p * k;
	}

	if (sum == n) cout << "Yes";
	else cout << "No";

	return 0;
}