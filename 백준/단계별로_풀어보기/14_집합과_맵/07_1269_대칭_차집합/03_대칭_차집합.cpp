/*
��¥ : 2024. 8. 28
�̸� : �輺��
���� : ��Ī ������
	������ȣ : 1269��

	�ڷᱸ��, �ؽ� ������
*/

#include <iostream>
#include <unordered_set>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int a, b, temp, ret;
	unordered_set<int> chk;
	FAST_IO;

	cin >> a >> b;
	ret = a + b;
	for (int i = 0; i < a; i++)
	{

		cin >> temp;
		chk.insert(temp);
	}

	for (int i = 0; i < b; i++)
	{

		cin >> temp;
		if (chk.count(temp)) ret -= 2;
	}

	cout << ret;
	return 0;
}