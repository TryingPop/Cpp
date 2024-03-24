#include <vector>

/*
��¥ : 2024. 3. 24
�̸� : �輺��
���� : ����
	�� �� ���� ��ǥ�� ���� ������ �迭
	dots�� ������ ���� �Ű������� �־�����,
	{ { x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 } }

	�־��� 4 ���� ���� �� ���� �̾��� ��,
	�� ������ ������ �Ǵ� ��찡 ������
	1�� ���ָ� 0�� return �ϴ�
	solution �Լ� ����
*/

using namespace std;

int solution(vector<vector<int>> _dots)
{

	int answer = 0;

	// �����ΰ� ã��
	for (int i = 1; i < 4; i++)
	{
		
		// ���� ������ Ǯ����
		// ���⸦ ��ʽ����� ���
		// �Ϲ����� ����� CCW �˰����� ���� �ɰ� ����
		int diffX1 = _dots[0][0] - _dots[i][0];
		int diffY1 = _dots[0][1] - _dots[i][1];

		int diffX2 = 0;
		int diffY2 = 0;
		int mul = -1;

		for (int j = 1; j < 4; j++)
		{

			if (i == j) continue;
			diffX2 += mul * _dots[j][0];
			diffY2 += mul * _dots[j][1];
			mul *= -1;
		}

		int calc1 = diffX1 * diffY2;
		int calc2 = diffX2 * diffY1;
		
		if (calc1 != calc2) continue;
		answer = 1;
		break;
	}

	return answer;
}