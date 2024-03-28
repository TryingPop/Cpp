#include <string>

/*
��¥ : 2024. 3. 28
�̸� : �輺��
���� : k�� ����
	1���� 13������ ������ 1�� 1, 10, 11, 12, 13
	�̷��� �� 6�� ����

	���� i, j , k�� �Ű������� �־��� ��,
	i���� j���� k�� �� �� �����ϴ���
	return �ϴ� solution �Լ� ����

	i, j�� 10�� ������ �ڿ����̰�, i < j
	k�� 9 ������ ���̾ƴ� ����
*/

using namespace std;

int solution(int _i, int _j, int _k)
{

	int answer = 0;
	string numStr;
	numStr.reserve(6);
	for (int i = _i; i <= _j; i++)
	{

		numStr = to_string(i);
		for (const char c : numStr)
		{

			if (c - '0' == _k) answer++;
		}
	}

	return answer;
}