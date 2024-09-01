/*
��¥ : 2024. 9. 1
�̸� : �輺��
���� : �似Ǫ�� ���� 0
	������ȣ : 11866��

	����, �ڷᱸ��, ť ������
*/

#include <iostream>
#include <queue>
#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{


	int n, k;
	vector<int> ret;
	queue<int> q;

	FAST_IO;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{

		q.push(i);
	}

	while (q.size())
	{

		for (int i = 1; i < k; i++)
		{

			int temp = q.front();
			q.pop();
			q.push(temp);
		}

		ret.push_back(q.front());
		q.pop();
	}

	cout << '<';
	cout << ret[0];
	for (int i = 1; i < n; i++)
	{

		cout << ',' << ' ' << ret[i];
	}
	cout << '>';
	return 0;
}