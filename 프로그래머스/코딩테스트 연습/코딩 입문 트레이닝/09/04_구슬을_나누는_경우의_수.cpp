#include <vector>

/*
��¥ : 2024. 3. 11
�̸� : �輺��
���� : ������ ������ ����� ��
	���� �ִ� ������ ���� balls�� ������ ������ ���� share��
	�Ű������� �־��� ��,
	balls���� ���� �� share���� ������ ���� ������ ��� ����� ����
	return �ϴ� solution �Լ� ����
*/

using namespace std;

int combi(int _n, int _r)
{

	if (_n < 2 || _r <= 0 || _r >= _n) return 1;

	int answer;
	answer = combi(_n - 1, _r - 1) + combi(_n - 1, _r);
	return answer;
}

int solution(int _balls, int _share)
{

	int answer;
	
	// �Ľ�Į �ﰢ���� ����� ����
	// 1ȸ������ �ϱ⿡�� �Ը� �ʹ� ũ��
	// 1ȸ�� ���� ��� ���� ���� ����Լ� �����ϴ°� �� �δ�
	vector<vector<int>> pascal = vector<vector<int>>(31);

	pascal[0] = vector<int>(1, 1);
	pascal[1] = vector<int>(2, 1);

	for (int i = 2; i <= 30; i++)
	{

		pascal[i] = vector<int>(i + 1, 1);
		for (int j = 1; j < i; j++)
		{

			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
		}
	}

	answer = pascal[_balls][_share];
	return answer;
}