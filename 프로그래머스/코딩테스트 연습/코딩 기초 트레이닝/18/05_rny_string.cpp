#include <string>
#include <vector>

/*
��¥ : 2024. 2. 24
�̸� : �輺��
���� : rny_string
	m�� rn�� ����� ����ϰ� ���� ���� Ȱ����
	���ڿ��� �峭�� ģ��

	���ڿ� rny_string�� �־��� ��,
	rny_string�� ��� m�� rn���� �ٲ� ���ڿ���
	return�ϴ� solution �Լ��� �ۼ�
*/

using namespace std;

string solution(string _rny_string)
{

	string answer;

	string rn = "rn";
	answer.reserve(_rny_string.length());

	for (const char c : _rny_string)
	{

		if (c == 'm') answer.append(rn);
		else answer.push_back(c);
	}

	return answer;
}