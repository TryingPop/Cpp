#include <string>

/*
��¥ : 2024. 2. 28
�̸� : �輺��
���� : �κ� ���ڿ����� Ȯ���ϱ�
	���ڿ� my_string�� target�� �Ű������� �־��� ��,
	target�� ���ڿ� my_string�� �κ� ���ڿ��̶�� 1��,
	�ƴ϶�� 0�� return �ϴ� solution �Լ��� ����
*/

using namespace std;

int solution(string _my_string, string _target)
{

	int answer;

	answer = _my_string.find(_target) != string::npos;
	return answer;
}