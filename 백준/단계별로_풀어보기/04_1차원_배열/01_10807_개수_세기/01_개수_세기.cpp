/*
��¥ : 2024. 8. 4
�̸� : �輺��
���� : ���� ����
	������ȣ : 10807��

	���� ������
*/

#include <iostream>

#define FASTIO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define ADD 100
using namespace std;

int cnt[ADD * 2 + 1];

int main(void)
{

	int n, num, find;
	FASTIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> num;
		cnt[ADD + num]++;
	}

	cin >> find;

	cout << cnt[ADD + find];
	return 0;
}