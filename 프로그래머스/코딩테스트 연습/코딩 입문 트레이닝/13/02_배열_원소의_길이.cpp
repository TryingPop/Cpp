#include <vector>
#include <string>

/*
��¥ : 2024. 3. 15
�̸� : �輺��
���� : �迭 ������ ����
	���ڿ� �迭 strlist�� �Ű������� �־�����
	strlist �� ������ ���̸� ���� �迭��
	return �ϴ� solution �Լ� ����
*/

using namespace std;

vector<int> solution(vector<string> _strlist)
{

	vector<int> answer;
	answer.reserve(_strlist.size());

	for (const string str : _strlist)
	{

		answer.push_back(str.length());
	}

	return answer;
}