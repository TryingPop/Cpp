#include <vector>
#include <string>

/*
��¥ : 2024. 2. 14
�̸� : �輺��
���� : ���� �̾� �ٿ� ���ڿ� �����
	���ڿ� my_string�� ���� �迭 index_list�� �־�����
	my_string�� index_list�� ���ҵ鿡 �ش��ϴ� �ε����� ���ڵ��� 
	������� �̾� ���� ���ڿ��� return �ϴ� solution �Լ� �ۼ��ϱ�
*/

using namespace std;

string soluion(string _my_string, vector<int> _index_list)
{

	string answer;

	answer.reserve(_index_list.size());

	for (const int idx : _index_list)
	{

		answer.push_back(_my_string[idx]);
	}

	return answer;
}