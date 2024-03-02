#include <vector>

/*
��¥ : 2024. 3. 2
�̸� : �輺��
���� : ������ ���������� ��ġ�ϱ�
	���� ���� n�� �Ű������� �־�����

	n * n �迭�� 1���� n^2���� ������
	�ε��� [0][0]���� �ð����
	���������� ��ġ�� ������ �迭�� 
	return�ϴ� solution �Լ� ����
*/

using namespace std;

vector<vector<int>> solution(int _n)
{

	// n * n ũ�⿡ 0���� �ʱ�ȭ
	vector<vector<int>> answer(_n, vector<int>(_n, 0));

	// ���� �����»�
	vector<pair<int, int>> dir{ { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

	int cur = 1;
	int curDir = 0;
	int curX = -1, curY = 0;

	// ���� �׸���
	while (cur <= _n * _n) 
	{

		int nextX = curX + dir[curDir].first;
		int nextY = curY + dir[curDir].second;

		if (nextX < 0 || nextX >= _n || nextY < 0 || nextY >= _n 
			|| answer[nextY][nextX]) 
		{

			// �տ� ���ڰ� �ְų� �������� ��� ���� ����
			curDir = curDir == 3 ? 0 : curDir + 1;
			continue;
		}

		answer[nextY][nextX] = cur++;
		curX = nextX;
		curY = nextY;
	}

	return answer;
}