#include <string>

/*
��¥ : 2024. 3. 23
�̸� : �輺��
���� : ���� �ִ� ������ ����_2
	���ڿ� my_string�� �Ű������� �־�����
	my_string�� �ҹ���, �빮��, �ڿ����θ�
	�����Ǿ� �ִ�

	my_string ���� �ڿ������� ���� 
	return �ϵ��� solution �Լ��� �ϼ�
*/

using namespace std;

int solution(string _my_string)
{

	int answer = 0;
	int num = 0;

	for (const char c : _my_string)
	{

		if (c < '0' || '9' < c) 
		{

			// ���� �ƴ� ���ڰ� �� ���
			answer += num;
			num = 0;
			continue;
		}

		// ���� ���޾� �Է� ���� ���
		num = 10 * num + c - '0';
	}

	// ���� �ִ� ����
	if (num) answer += num;
	return answer;
}