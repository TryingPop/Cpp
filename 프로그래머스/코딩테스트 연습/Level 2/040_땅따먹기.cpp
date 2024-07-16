/*
��¥ : 2024. 7. 16
�̸� : �輺��
���� : �����Ա�
	������ ���� N�� 4���� �̷���� �ִ�
	��� ĭ���� ������ �����ִ�

	1�� ���� ������ �� �྿ ������ ��,
	�� ���� 4ĭ �� �� ĭ�� �����鼭 �����;� �Ѵ�
	
	��, �����Ա� ���ӿ����� �� �྿ ������ ��
	���� ���� �����ؼ� ���� �� ���� Ư�� ��Ģ�� �ִ�

	������ ����� ��� �������� ��,
	���� �� �ִ� ������ �ִ밪�� 
	return �ϴ� solution �Լ� ����

	���� ���� N : 10�� ������ �ڿ���
	���� ������ 4��, ���� 2���� �迭�� �־�����

	������ 100 ������ �ڿ���


	prameter
	{ { 1, 2, 3, 5 }, { 5, 6, 7, 8 }, { 4, 3, 2, 1 } }


	return
	16

	
	sol
	5 -> 7 -> 4 ������ �������� �ȴ�
*/

#include <vector>

using namespace std;

int solution(vector<vector<int>> _land)
{

	int answer = 0;

	/*
	
	���� �ִ� ���� �޸��صΰ� Ǭ��
	�׸��� �ִ밪�� �ִ밡 �Ǵ� ��η� ������ ��쿡 �����Ѵ�
	O(row * col * col)
	*/
	int row = _land.size();
	int col = _land[0].size();

	vector<int> cur(col, 0);
	vector<int> next(col, 0);

	for (int r = 0; r < row; r++)
	{

		// �������� ����� �� �ִ밪 ã��
		for (int c = 0; c < col; c++)
		{

			for (int i = 0; i < col; i++)
			{

				if (i == c) continue;
				int chk = cur[c] + _land[r][c];
				if (next[i] < chk) next[i] = chk;
			}
		}

		// ������ ����� ����
		for (int c = 0; c < col; c++)
		{

			cur[c] = next[c];
			next[c] = 0;
		}
	}

	for (int i = 0; i < col; i++)
	{

		answer = answer < cur[i] ? cur[i] : answer;
	}

	return answer;
}