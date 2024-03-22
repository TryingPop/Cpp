#include <vector>

/*
��¥ : 2024. 3. 22
�̸� : �輺��
���� : ���簢�� ���� ���ϱ�
	2���� ��ǥ ��鿡 ����
	��� ������ ���簢���� �ִ�

	���簢�� �� �������� ��ǥ
	{ { x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 } }
	�� ����ִ� �迭 dots�� �Ű������� �־��� ��,
	���簢���� ���̸� return �ϵ��� solution �Լ� ����

	�� ��ǥ�� -256�� ���� �ʰ�
	�߸� �ԷµǴ� ���� ����
*/

using namespace std;

int solution(vector<vector<int>> _dots)
{

	int answer = 0;

	int w = 0;
	int h = 0;

	for (int i = 1; i < 4; i++)
	{

		if (w == 0) w = _dots[0][0] - _dots[i][0];
		if (h == 0) h = _dots[0][1] - _dots[i][1];
	}

	w = w < 0 ? -w : w;
	h = h < 0 ? -h : h;
	answer = w * h;
	return answer;
}