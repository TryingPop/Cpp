/*
��¥ : 2024. 8. 9
�̸� : �輺��
���� : ŷ, ��, ��, ���, ����Ʈ, ��
	������ȣ : 3003��

	����, ����, ��Ģ���� ������
*/

#include <iostream>
#include <vector>

#define EMPTY ' '
using namespace std;

int main(void)
{

	int n;
	vector<int> correct = { 1, 1, 2, 2, 2, 8 };

	for (int i = 0; i < 6; i++)
	{

		cin >> n;
		cout << correct[i] - n << EMPTY;
	}

	return 0;
}