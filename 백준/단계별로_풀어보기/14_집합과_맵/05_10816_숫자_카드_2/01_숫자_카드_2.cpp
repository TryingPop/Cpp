/*
��¥ : 2024. 8. 27
�̸� : �輺��
���� : ���� ī�� 2
	������ȣ : 10816��

	�ڷᱸ��, ����, �̺� Ž��, �ؽ� ������
*/

#include <iostream>
#include <unordered_map>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define EMPTY ' '
using namespace std;

int main(void)
{

	int n, temp;
	unordered_map<int, int> my;

	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		my[temp]++;
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		cout << my[temp] << EMPTY;
	}

	return 0;
}