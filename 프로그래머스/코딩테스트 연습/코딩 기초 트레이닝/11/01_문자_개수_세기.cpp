#include <string>
#include <vector>
#define ALPHABET 26

/*
��¥ : 2024. 2. 17
�̸� : �輺��
���� : ���� ���� ����
	���ĺ� ��ҹ��ڷθ� �̷���� ���ڿ� my_string�� �־��� ��, 
	my_string���� 'A'�� ����, my_string���� 'B'�� ����,...
	, my_string���� 'Z'�� ����, my_string���� 'a'�� ����,
	my_string���� 'b'�� ����, ..., my_string���� 'z'�� ������
	������� ���� ���� 52 ���� �迭�� return �ϴ� solution �Լ� ����
*/

using namespace std;

vector<int> solution(string _my_string)
{

	// vector<int> answer(ALPHABET * 2, 0);
	vector<int> answer;
	answer.assign(ALPHABET * 2, 0);

	for (const char c : _my_string)
	{

		int idx;
		if (c > 'Z') idx = c - 'a' + ALPHABET;
		else c - 'A';

		answer[idx]++;
	}

	return answer;
}