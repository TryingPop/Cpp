#include <string>
// #include <vector>
// #include <algorithm>

/*
��¥ : 2024. 2. 16
�̸� : �輺��
���� : ���ڿ� ������
	���ڿ� my_string�� ���� s, e�� �Ű������� �־��� ��,
	my_string���� �ε��� s���� �ε��� e������ ������ ���ڿ���
	return �ϴ� solution �Լ� �ۼ��ϱ�
*/

using namespace std;

string solution(string _my_string, int _s, int _e)
{

	string answer;
	answer.reserve(_my_string.length());
	
	for (int i = 0; i < _s; i++)
	{

		answer.push_back(_my_string[i]);
	}

	for (int i = _e; i >= _s; i--)
	{

		answer.push_back(_my_string[i]);
	}

	for (int i = _e + 1; i < _my_string.length(); i++)
	{

		answer.push_back(_my_string[i]);
	}

	// for (int i = _s, int j = _e; i < j; i++, j--) { }
	// reverse(answer.begin() + _s, answer.begin() + _e + 1);
	return answer;
}