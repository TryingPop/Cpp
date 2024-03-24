#include <string>

/*
��¥ : 2024. 3. 24
�̸� : �輺��
���� : ������ ���� 3
	3x ���������� 3�� ����� ���� 3��
	���� ���ڸ� ������� �ʴ´�

	���� n�� �Ű������� �־��� ��,
	n�� 3x �������� ����ϴ� ���ڷ� �ٲ�
	return �ϴ� soltuion �Լ��� ����
*/

using namespace std;

int solution(int _n)
{

	int answer = 0;

	int idx = 0;
	for (int i = 1; i <= 1'000; i++)
	{

		// 3�� ��� ����
		if (!(i % 3)) continue;
		string iStr = to_string(i);

		bool isBreak = false;
		for (const char c : iStr)
		{

			// 3�� �����ϴ� �� ����
			if (c != '3') continue;
			isBreak = true;
			break;
		}

		if (isBreak) continue;
		idx++;

		if (idx != _n) continue;
		answer = i;
		break;
	}

	return answer;
}