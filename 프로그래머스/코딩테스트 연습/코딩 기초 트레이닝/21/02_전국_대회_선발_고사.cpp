#include <vector>
#include <algorithm>

/*
��¥ : 2024. 2. 27
�̸� : �輺��
���� : ���� ��ȸ ���� ���
	�� �л����� ���� ��� ����� ���� ���� �迭 rank��
	���� ��ȸ ���� ���� ���ΰ� ��� bool �迭 attendance�� �־�����
	0������ n - 1������ n���� �л� �� ���� ��ȸ ���� �����ϰ� 
	����� ���� 3���� ����

	������ȸ���� ���ߵ� �л� ��ȣ���� ����� ���� �������
	���� a, b, c�� �� ��, 10'000 * a + 100 * b + c��
	return�ϴ� solution �Լ� ����
*/

using namespace std;

int comp(pair<int, int> _calc1, pair<int, int> _calc2)
{

	return _calc1.first < _calc2.first;
}

int solution(vector<int> _rank, vector<bool> _attendance)
{

	int answer = 0;
	vector<pair<int, int>> temp;
	temp.reserve(_rank.size());

	for (int i = 0; i < _attendance.size(); i++) 
	{

		if (_attendance[i]) temp.push_back({ _rank[i], i });
	}

	sort(temp.begin(), temp.end(), comp);

	answer = 10'000 * temp[0].second + 100 * temp[1].second + temp[2].second;
	return answer;
}