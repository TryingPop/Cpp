#include <vector>
#include <string>

/*
��¥ : 2024. 2. 20
�̸� : �輺��
���� : �� �� ���
	���� �ؾ� �� ���� ��� ���ڿ� �迭 todo_list��
	������ ���� ���� ���ƴ����� ��Ÿ���� bool �迭 finished�� �Ű������� �־��� ��,
	todo_list���� ���� ��ġ�� ���� �ϵ��� ������� ���� ���ڿ� �迭��
	return �ϴ� solution �Լ� ����
*/
using namespace std;

vector<string> solution(vector<string> _todo_list, vector<bool> _finished) 
{

	vector<string> answer;

	for (int i = 0; i < _todo_list.size(); i++)
	{

		if (!_finished[i]) answer.push_back(_todo_list[i]);
	}
	return answer;
}