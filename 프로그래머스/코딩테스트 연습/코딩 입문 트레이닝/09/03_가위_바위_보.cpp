#include <string>

/*
��¥ : 2024. 3. 11
�̸� : �輺��
���� : ���� ���� ��
	������ 2, ������ 0, ���� 5�� ǥ���ȴ�
	���� ���� ���� ������� ��Ÿ�� ���ڿ� rsp�� �Ű������� �־��� ��,
	rsp�� ����� ���� ���� ���� ��� �̱�� ��츦 ������� ��Ÿ��
	���ڿ��� return �ϴ� solution �Լ� ����
*/

using namespace std;

string solution(string _rsp)
{

	string answer;
	answer.reserve(_rsp.length());

	for (const char c : _rsp)
	{

		if (c == '2') answer.push_back('0');
		else if (c == '0') answer.push_back('5');
		else answer.push_back('2');
	}

	return answer;
}