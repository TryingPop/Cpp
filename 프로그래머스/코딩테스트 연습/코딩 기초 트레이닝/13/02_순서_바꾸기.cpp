#include <vector>

/*
��¥ : 2024. 2 19
�̸� : �輺��
���� : ���� �ٲٱ�
	���� ����Ʈ num_list�� ���� n�� �־��� ��,
	num_list�� n��° ���� ������ ���ҵ�� n��° ������ ���ҵ�� ����
	n��° ���� ������ ���ҵ��� n��°������ ���ҵ� �տ� ���� 
	����Ʈ�� return �ϴ� solution �Լ� ����
*/

using namespace std;

vector<int> solution(vector<int> _num_list, int _n)
{

	vector<int> answer;

	answer.reserve(_num_list.size());

	for (int i = _n; i < _num_list.size(); i++)
	{

		answer.push_back(_num_list[i]);
	}

	for (int i = 0; i < _n; i++)
	{

		answer.push_back(_num_list[i]);
	}

	// answer.assign(_num_list.begin() + _n, _num_list.end());
	// answer.insert(answer.end(), _num_list.begin(), _num_list.begin() + _n);
	return answer;
}