#include <string>
#include <vector>

/*
��¥ : 2024. 2. 23
�̸� : �輺��
���� : �������� �����ϱ� 1
	�ܾ ���� �� ���� ���еǾ� �ִ� ���ڿ� my_string��
	�Ű������� �־��� ��,
	my_string�� ���� �ܾ �տ������� ������� ���� ���ڿ� �迭��
	return �ϴ� solution �Լ��� �ۼ�
*/

using namespace std;

vector<string> solution(string _my_string)
{

	vector<string> answer;

	string temp;
	for (const char c : _my_string)
	{

		if (c == ' ') 
		{

			answer.push_back(temp);
			temp.clear();
		}
		else 
		{

			temp.push_back(c);
		}
	}

	answer.push_back(temp);

	return answer;
}