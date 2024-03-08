#include <vector>
#define _ 1'001

/*
��¥ : 2024. 3. 8
�̸� : �輺��
���� : �ֺ� ���ϱ�
	���� �迭 array�� �Ű������� �־��� ��,
	�ֺ��� return �ϵ��� solution �Լ��� ����

	�ֺ��� �־��� �� �߿��� ���� ���� ������ ���� �ǹ�
	�ֺ��� ���� ���� -1�� ��ȯ

	array������ ������ 0�̻� 1000 �����̴�
*/

using namespace std;

int solution(vector<int> _array)
{

	// 1'000�� �ʰ��ϴ� �ƹ� ���� �־��ָ� �ȴ�
	int answer = _;
	vector<int> calc(1'001, 0);
	int max = 0;
	for (const int i : _array)
	{

		calc[i]++;
		if (max < calc[i]) max = calc[i];
	}


	for (int i = 0; i <= 1000; i++)
	{

		if (max == calc[i]) 
		{

			// ù �߰�
			if (answer == _) answer = i;
			else 
			{

				// �ߺ� �߰�
				answer = -1;
				break;
			}
		}
	}

	return answer;
}