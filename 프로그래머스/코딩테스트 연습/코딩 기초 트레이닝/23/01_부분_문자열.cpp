#include <string>

/*
��¥ : 2024. 2. 29
�̸� : �輺��
���� : �κ� ���ڿ�
	���ڿ� str1, str2�� �־�����
	str1�� str2�� �κ� ���ڿ��̶�� 1��
	�κ� ���ڿ��� �ƴ϶�� 0��
	return �ϴ� solution �Լ��� ����

	���⼭ ���ϴ� �κ� ���ڿ��̶�
	a�� b�� �κй��ڿ��̶�� b = ? + a + ?
	�� ���·� ǥ�� ����
*/

using namespace std;

int solution(string _str1, string _str2)
{

	int answer = _str2.find(_str1) != string::npos;

	return answer;
}