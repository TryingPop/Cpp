#include <string>

/*
��¥ : 2024. 3. 14
�̸� : �輺��
���� : �����ִ� ������ ���� 1
	���ڿ� my_string�� �Ű������� �־��� ��,
	my_string ���� ��� �ڿ������� ����
	return �ϴ� solution �Լ� ����
*/

using namespace std;

int solution(string _my_string)
{

	int answer = 0;

	for (const char c : _my_string)
	{

		if (c < '0' || c > '9') continue;
		answer += c - '0';
	}

	return answer;
}