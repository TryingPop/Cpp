#include <string>

/*
��¥ : 2024. 2. 14
�̸� : �輺��
���� : 9�� ���� ������
	���� �ƴ� ������ 9�� ���� �������� �� �ڸ� ������ ���� 9�� ���� �������� ��ġ�Ѵ�
	�̸� �̿��� ���� �ƴ� ������ ���ڿ� number�� �־��� ��, �� ������ 9�� ���� ��������
	return �ϴ� �Լ� �����
*/

using namespace std;

int solution(string _number)
{

	int answer = 0;

	for (const char c : _number) 
	{

		answer += c - '0';
		answer = 8 < answer ? answer - 9 : answer;
	}

	return answer;
}