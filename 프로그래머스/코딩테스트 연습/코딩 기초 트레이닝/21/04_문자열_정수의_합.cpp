#include <string>

/*
��¥ : 2024. 2. 27
�̸� : �輺��
���� : ���ڿ� ������ ��
	�� �ڸ� ������ �̷���� ���ڿ�
	num_str�� �־�����

	�� �ڸ����� ���� retun �ϵ��� solution �Լ��� ����
*/

using namespace std;

int solution(string _num_str)
{

	int answer = 0;

	for (const char c : _num_str)
	{

		answer += c - '0';
	}

	return answer;
}