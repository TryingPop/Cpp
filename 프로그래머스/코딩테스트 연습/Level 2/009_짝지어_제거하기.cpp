/*
��¥ : 2024. 6. 16
�̸� : �輺��
���� : ¦���� �����ϱ�
	���ĺ� �ҹ��ڷ� �̷���� ���ڿ��� �־�����
	���ڿ����� ���� ���ĺ��� 2�� �پ� �ִ� ¦�� ã�´�
	�״����� �� ���� ������ �� �յڷ� ���ڿ��� �̾���δ�
	�� ������ �ݺ��ؼ� ���ڿ��� ��� �����Ѵٸ� ¦���� �����ϱⰡ ����ȴ�

	���ڿ� s�� �־����� ��,
	¦���� �����ϱ⸦ ���������� ������ �� ������ 1��
	������ 0�� return �ϴ� solution �Լ� ����


	parameter
	baabaa


	return
	1
*/

#include <string>

using namespace std;

int solution(string _s)
{

	int answer = 1;
	int len = 0;

	// Stack
	for (const char c : _s)
	{

		if (len == 0)
		{

			_s[len++] = c;
			continue;
		}

		if (c == _s[len - 1]) len--;
		else _s[len++] = c;
	}

	if (len) answer = 0;

	return answer;
}