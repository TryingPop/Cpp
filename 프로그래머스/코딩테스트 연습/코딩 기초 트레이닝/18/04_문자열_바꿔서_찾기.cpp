#include <string>
#include <vector>

/*
��¥ : 2024. 2. 24
�̸� : �輺��
���� : ���ڿ� �ٲ㼭 ã��
	���� "A"�� "B"�� �̷���� ���ڿ� myString��
	pat�� �־�����

	myString�� "A"�� "B"�� "B"�� "A"�� �ٲ� ���ڿ���
	�����ϴ� �κ� ���ڿ� �� pat�� ������
	1�� �ƴϸ� 0�� return �ϴ� solution �Լ� ����
*/

using namespace std;

int solution(string _myString, string _pat)
{

	int answer = 0;

	string temp;
	temp.reserve(_myString.length());

	for (const char c : _myString)
	{

		if (c == 'A') temp.push_back('B');
		else temp.push_back('A');
	}

	answer = temp.find(_pat) != string::npos;
	return answer;
}