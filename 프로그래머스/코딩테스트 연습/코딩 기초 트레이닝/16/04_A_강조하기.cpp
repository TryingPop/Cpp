#include <string>
#include <vector>
#include <algorithm>

/*
��¥ : 2024. 2. 22
�̸� : �輺��
���� : A �����ϱ�
	���ڿ� myString�� �־�����
	myString���� ���ĺ� 'a'�� �����ϸ� ���� 'A'�� ��ȯ�ϰ�
	'A'�� �ƴ� ��ҹ��� ���ĺ��� �ҹ��� ���ĺ����� ��ȯ�Ͽ�
	return�ϴ� solution �Լ� ����
*/

using namespace std;

string solution(string _myString)
{

	string answer = _myString;

	transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
	for (int i = 0; i < answer.length(); i++)
	{

		if (answer[i] == 'a') answer[i] = 'A';
	}

	return answer;
}