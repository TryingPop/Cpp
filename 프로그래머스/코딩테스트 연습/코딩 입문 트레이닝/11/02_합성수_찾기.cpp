#include <vector>

/*
��¥ : 2024. 3. 13
�̸� : �輺��
���� : �ռ��� ã��
	����� ������ 3�� �̻��� ���� �ռ���
	�ڿ��� n�� �Ű������� �־��� ��,

	n������ �ռ����� ������
	return �ϴ� solution �Լ� ����
*/

using namespace std;

int solution(int _n)
{

	int answer = 0;

	vector<bool> temp(_n + 1, false);

	for (int i = 2; i <= _n; i++)
	{

		for (int j = i * 2; j <= _n; j += i)
		{

			temp[j] = true;
		}
	}

	for (int i = 2; i <= _n; i++)
	{

		if (temp[i]) answer++;
	}

	return answer;
}