#include <vector>
#include <algorithm>

/*
��¥ : 2024. 3. 26
�̸� : �輺��
���� : ��� �ű��
	���� ������ ���� ������ ��� ������ ��������
	�л����� ����� �ű���� �Ѵ�

	���� ������ ���� 2���� ���� �迭 score��
	�־��� ��, ���� ������ ���� ������ ����� ��������
	�ű� ����� ���� �迭�� return �ϵ��� solution �Լ� ����
*/

using namespace std;

int comp(pair<int, int>& _f, pair<int, int>& _b)
{

	// first ���� �������� ����
	return _b.first < _f.first;
}

vector<int> solution(vector<vector<int>> _score)
{

	vector<int> answer(_score.size(), 0);

	vector<pair<int, int>> temp;
	temp.reserve(_score.size());

	for (int i = 0; i < _score.size(); i++)
	{

		pair<int, int> c;
		c.first = _score[i][0] + _score[i][1];
		c.second = i;
	}

	sort(temp.begin(), temp.end(), comp);

	int before = -1;
	int rank = 0;
	int add = 1;

	// ��ŷ �ֱ�
	for (pair<int, int>& p : temp)
	{

		if (before != p.first)
		{

			rank += add;
			before = p.first;
			add = 1;
		}
		else add++;

		answer[p.second] = rank;
	}

	return answer;
}