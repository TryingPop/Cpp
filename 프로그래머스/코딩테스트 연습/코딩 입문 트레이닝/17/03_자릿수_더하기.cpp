#include <string>

/*
��¥ : 2024. 3. 19
�̸� : �輺��
���� : �ڸ��� ���ϱ�
	���� n�� �Ű������� �־��� ��
	n�� �� �ڸ� ������ ����
	return �ϵ��� solution �Լ��� ����
*/

using namespace std;

int solution(int _n)
{

	int answer = 0;
	string numStr = to_string(_n);

	for (const char c : numStr)
	{

		answer += c - '0';
	}

	return answer;
}