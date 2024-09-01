/*
��¥ : 2024. 9. 1
�̸� : �輺��
���� : ī��2
	������ȣ : 2164��

	�ڷᱸ��, ť ������
*/

#include <iostream>
#include <queue>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;



int main(void)
{

	int n;
	queue<int> q;

	FAST_IO;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{

		q.push(i);
	}

	while (q.size() > 1)
	{

		q.pop();
		int f = q.front();
		q.pop();
		q.push(f);
	}

	cout << q.front();
	return 0;
}