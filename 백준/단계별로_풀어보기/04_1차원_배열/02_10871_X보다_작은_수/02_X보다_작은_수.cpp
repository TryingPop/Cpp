/*
��¥ : 2024. 8. 4
�̸� : �輺��
���� : X���� ���� ��
	������ȣ : 10871��

	���� ������
*/

#include <iostream>
#include <vector>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define EMPTY ' '
using namespace std;

int main(void)
{

	int n, k, num;
	vector<int> arr;

	FAST_IO;
	cin >> n >> k;

	arr.reserve(n);

	for (int i = 0; i < n; i++)
	{

		cin >> num;
		if (k <= num) continue;

		arr.push_back(num);
	}

	for (int num : arr)
	{

		cout << num << EMPTY;
	}

	return 0;
}