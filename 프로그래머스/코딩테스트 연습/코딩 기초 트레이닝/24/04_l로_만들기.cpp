#include <string>

/*
��¥ : 2024. 3. 1
�̸� : �輺��
���� : l�� �ٲٱ�
	���ĺ� �ҹ��ڷ� �̷���� ���ڿ� myString
	���ĺ� �������� l���� �ռ��� ��� ���ڸ�
	l�� �ٲ� ���ڿ��� return�ϴ� solution �Լ� ����
*/

using namespace std;

string solution(string _myString)
{

	string answer = "";
	answer.reserve(_myString.length());

	for (const char c : _myString)
	{

		if (c < 'l') answer.push_back('l');
		else answer.push_back(c);
	}

	return answer;
}