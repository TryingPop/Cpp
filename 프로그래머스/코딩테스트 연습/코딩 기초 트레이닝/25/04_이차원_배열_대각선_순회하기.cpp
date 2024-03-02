#include <vector>

/*
��¥ : 2024. 3. 2
�̸� : �輺��
���� : ������ �迭 �밢�� ��ȸ�ϱ�
	2���� ���� �迭 board�� k�� �־�����

	i + j <= k�� �����ϴ� ��� i, j�� ����
	board[i][j]�� ���� return�ϴ� solution �Լ� ����

	��� board[i]�� ũ��� ����
*/

using namespace std;

int solution(vector<vector<int>> _board, int _k)
{

	int answer = 0;

	int r = _board.size();
	int c = _board[0].size();

	for (int i = 0; i < r; i++)
	{

		for (int j = 0; j < c; j++)
		{

			if (i + j > _k) break;
			answer += _board[i][j];
		}
	}

	return answer;
}