#include <vector>

/*
��¥ : 2024. 3. 12
�̸� : �輺��
���� : 2�������� �����
	���� �迭 num_list�� ���� n�� �Ű������� �־��� ��,
	num_list�� 2���� �迭�� �ٲ� return �ϴ� solution �Լ� ����

	num_list�� ����� l�̶� �ϸ� num_list�� �տ��� ���� n���� ����
	l / n * n �������� 2���� �迭�� ������ �Ѵ�

	������� num_list = { 1, 2, 3, 4, 5, 6 } �̰�, n = 3�̸�
	{ { 1, 2, 3 }, { 4, 5, 6 } }�� �迭�� �����
*/

using namespace std;

vector<vector<int>> solution(vector<int> _num_list, int _n)
{

	// ũ�� ����
	vector<vector<int>> answer(_num_list.size() / _n, vector<int>(_n));

	int idx1 = 0;
	int idx2 = 0;
	for (const int i : _num_list)
	{

		answer[idx1][idx2] = i;
		idx2++;
		if (idx2 == _n)
		{

			idx1++;
			idx2 = 0;
		}
	}

	return answer;
}