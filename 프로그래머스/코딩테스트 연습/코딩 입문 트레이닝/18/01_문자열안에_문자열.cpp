#include<string>

/*
��¥ : 2024. 3. 20
�̸� : �輺��
���� : ���ڿ��ȿ� ���ڿ�
	���ڿ� str1, str2�� �Ű������� �־��� ��,
	str1 �ȿ� str2�� �ִٸ� 1�� ���ٸ� 2��
	return �ϴ� solution �Լ� ����
*/

using namespace std;

int solution(string _str1, string _str2) 
{

	int answer = 0;
	answer = _str1.find(_str2) != string::npos ? 1 : 2;
	return answer;
}