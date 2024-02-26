#include <vector>

/*
��¥ : 2024. 2. 26
�̸� : �輺��
���� : �迭 ���ϱ�
	�� �迭�� ���̰� �ٸ��ٸ�, �迭�� ���̰� �� ���� �� ũ��
	�� �迭�� ���̰� ���ٸ�, ��� ������ ���� ���Ͽ� �� ū���� ũ��
	���ٸ� ����

	arr1, arr2�� �־��� ��, arr1�� ũ�ٸ� 1, arr2�� ũ�� 2, ���� ��� 0��
	return �ϴ� solution �Լ� ����
*/

using namespace std;

int solution(vector<int> _arr1, vector<int> _arr2)
{

	int answer;

	if (_arr1.size() != _arr2.size())
	{

		answer = _arr1.size() > _arr2.size() ? 1 : -1;
	}
	else 
	{

		int sum1 = 0;
		int sum2 = 0;

		for (int i = 0; i < _arr1.size(); i++)
		{

			sum1 += _arr1[i];
			sum2 += _arr2[i];
		}

		if (sum1 > sum2) answer = 1;
		else if (sum1 < sum2) answer = -1;
		else answer = 0;
	}
	return answer;
}