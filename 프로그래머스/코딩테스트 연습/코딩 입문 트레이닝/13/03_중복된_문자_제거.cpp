#include <string>
#include <vector>

/*
��¥ : 2024. 3. 15
�̸� : �輺��
���� : �ߺ��� ���� ����
	���ڿ� my_string�� �Ű������� �־�����
	my_string���� �ߺ��� ���ڸ� �����ϰ� �ϳ���
	���ڸ� ���� ���ڿ��� return �ϵ���
	solution �Լ� ����

	my_string�� �빮��, �ҹ���, �������� �̷�����ִ�
	�׸��� �빮�ڿ� �ҹ��ڸ� �����ϴ�
	���鵵 �ϳ��� ���ڷ� �����Ѵ�
	�ߺ��� ���� �� ���� �տ� �ִ� ���ڸ� �����
*/

using namespace std;

string solution(string _my_string)
{

	string answer = "";
	answer.reserve(_my_string.length());

	// 0 ~ 25 : �ҹ��� ���ĺ�
	// 26 ~ 51 : �빮�� ���ĺ�
	// 52 : ����
	vector<bool> use(53, false);

	for (const char c : _my_string)
	{

		int idx;
		if ('a' <= c && c <= 'z') idx = c - 'a';
		else if ('A' <= c && c <= 'Z') idx = c - 'A' + 26;
		// ����
		else idx = 52;

		if (use[idx]) continue;
		use[idx] = true;
		answer.push_back(c);
	}

	return answer;
}