#include <vector>
#include <string>

/*
��¥ : 2024. 2. 24
�̸� : �輺��
���� : x ������ ����
	���ڿ� myString�� �־��� ��,
	myString�� ���� "x"�� �������� ������ �� ������ ���ڿ�
	������ ���̸� ������� ������ �迭�� return �ϴ� solution �Լ��� ����
*/

using namespace std;

vector<int> solution(string _myString)
{

	vector<int> answer;

	int len = 0;

	for (const char c : _myString)
	{

		if (c == 'x')
		{

			answer.push_back(len);
			len = 0;
		}
		else len++;
	}

	answer.push_back(len);
	return answer;
}