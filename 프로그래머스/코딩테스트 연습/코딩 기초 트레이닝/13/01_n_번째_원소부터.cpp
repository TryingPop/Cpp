#include<vector>

/*
��¥ : 2024. 2. 19
�̸� : �輺��
���� : n ��° ���Һ���
	���� ����Ʈ num_list�� ���� n�� �־��� ��,
	n��° ���Һ��� ������ ���ұ����� ��� ���Ҹ� ���� ����Ʈ��
	return �ϵ��� solution �Լ��� �ϼ�
*/
using namespace std;

vector<int> solution(vector<int> _num_list, int _n)
{

	vector<int> answer;

	answer.assign(_num_list.begin() + _n - 1, _num_list.end());
	/*
	for (int i = n - 1; i < _num_list.size(); i++)
	{

		answer.push_back(_num_list[i]);
	}
	*/
	return answer;
}