#include <vector>

/*
��¥ : 2024. 2. 19
�̸� : �輺��
���� : n�� ���� ���ҵ�
	���� ����Ʈ num_list�� ���� n�� �־��� ��,
	num_list�� ù ��° ���Һ��� ������ ���ұ��� n�� ��������
	����Ǿ� �ִ� ���ҵ��� ���ʷ� ���� ����Ʈ�� return�ϵ��� solution �Լ��� �ϼ�
*/

using namespace std;

vector<int> solution(vector<int> _num_list, int _n)
{

	vector<int> answer;

	for (int i = 0; i < _num_list.size(); i += _n)
	{

		answer.push_back(_num_list[i]);
	}
	return answer;
}