#include <vector>
#include <string>
#include <algorithm>

/*
��¥ : 2024. 2. 24
�̸� : �輺��
���� : ���ڿ� �߶� �����ϱ�
	���ڿ� myString�� �־�����
	"x"�� �������� �ش� ���ڿ��� �߶� �迭�� ���� ��
	���������� ������ �迭��
	return �ϴ� solution �Լ��� ����

	��, �� ���ڿ��� ��ȯ�� �迭�� ���� �ʴ´�
*/

using namespace std;

vector<string> solution(string _myString)
{

	vector<string> answer;

	string temp;
	for (const char c : _myString)
	{

		if (c == 'x')
		{

			if (!temp.empty())
			{

				answer.push_back(temp);
				temp.clear();
			}
		}
		else temp.push_back(c);
	}

	if (!temp.empty()) answer.push_back(temp);

	sort(answer.begin(), answer.end());
	return answer;
}