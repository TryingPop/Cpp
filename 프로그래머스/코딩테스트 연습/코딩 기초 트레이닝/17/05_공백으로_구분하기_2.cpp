#include <string>
#include <vector>

/*
��¥ : 2024. 2. 23
�̸� : �輺��
���� : �������� �����ϱ� 2
	�ܾ ���� �� �� �̻����� ���еǾ� �ִ� ���ڿ� my_string�� �Ű������� �־��� ��,
	my_string�� ���� �ܾ �տ������� ������� ���� ���ڿ� �迭��
	return�ϴ� solution �Լ��� �ۼ�
*/

using namespace std;

vector<string> solution(string _my_string)
{

	vector<string> answer;

	string temp;
	char before = '\0';
	
	for (const char c : _my_string)
	{

		if (c != ' ')
		{

			if (before == ' ' && !temp.empty()) 
			{

				answer.push_back(temp);
				temp.clear();
			}

			temp.push_back(c);
		}

		before = c;
	}

	if (!temp.empty()) answer.push_back(temp);
	return answer;
}