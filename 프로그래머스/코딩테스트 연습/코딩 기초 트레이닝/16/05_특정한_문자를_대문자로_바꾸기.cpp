#include<string>
#include<vector>
#include<algorithm>

/*
��¥ : 2024. 2. 22
�̸� : �輺��
���� : Ư���� ���ڸ� �빮�ڷ� �ٲٱ�
	���ҹ��ڷ� �̷���� ���ڿ� my_string
	���ҹ��� 1���ڷ� �̷���� ���ڿ� alp��
	�Ű������� �־��� ��
	my_string���� alp�� �ش��ϴ� ��� ���ڸ� �빮�ڷ� �ٲ� ���ڿ��� 
	return�ϴ� solution �Լ��� �ۼ�
*/
using namespace std;

string solution(string _my_string, string _alp)
{

	string answer = _my_string;

	for (int i = 0; i < _my_string.length(); i++)
	{

		if (answer[i] == _alp[0]) answer[i] += 'A' - 'a';
	}

	return answer;
}