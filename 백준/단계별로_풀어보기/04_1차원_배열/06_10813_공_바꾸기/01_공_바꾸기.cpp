/*
��¥ : 2024. 8. 5
�̸� : �輺��
���� : �� �ٲٱ�
	������ȣ : 10813��

	����, �ùķ��̼� ������
*/

#include <iostream>
#include <utility>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define EMPTY ' '

using namespace std;

int arr[101];

int main(void)
{

	int n, m, f, t;
	FAST_IO;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{

		arr[i] = i;
	}

	for (int i = 0; i < m; i++)
	{

		cin >> f >> t;
		swap(arr[f], arr[t]);
	}

	for (int i = 1; i <= n; i++)
	{

		cout << arr[i] << EMPTY;
	}

	return 0;
}