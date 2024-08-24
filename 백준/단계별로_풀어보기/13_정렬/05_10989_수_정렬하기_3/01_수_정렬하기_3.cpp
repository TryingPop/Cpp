/*
��¥ : 2024. 8. 24
�̸� : �輺��
���� : �� �����ϱ� 3
	������ȣ : 10989��

	���� ������
*/

#include <iostream>
#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define endl	'\n'

using namespace std;

int main(void)
{

	int n, temp;
	vector<int> cnt(10'001, 0);

	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		cnt[temp]++;
	}

	for (int i = 0; i < cnt.size(); i++)
	{

		if (!cnt[i]) continue;

		for (int j = 0; j < cnt[i]; j++)
		{

			cout << i << endl;
		}
	}

	return 0;
}