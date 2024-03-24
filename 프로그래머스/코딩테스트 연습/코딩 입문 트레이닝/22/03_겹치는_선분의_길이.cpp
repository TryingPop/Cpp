#include <vector>

/*
��¥ : 2024. 3. 24
�̸� : �輺��
���� : ��ġ�� ������ ����
	������ { start, end } ���·� ���� �ִ�
	�� �� �̻��� ������ ��ġ��
	lines�� �̷��� ������ ��Ƴ��� 2���� �迭�̰�,
	lines�� �Ű������� �־��� ��,
	�κ��� ���̸� return �ϴ� solution �Լ� ����

	lines�� ���� ������ -100 ~ 100�̴�
*/

using namespace std;

int solution(vector<vector<int>> _lines)
{

	int answer = 0;

	// ������
	vector<int> temp(202, 0);

	for (vector<int>& line : _lines) 
	{

		// ���� ��ġ �ε����� ���� ����
		int s = line[0] + 100;
		int e = line[1] + 100;

		// ������ ���������� ������ ����
		temp[s]++;
		temp[e]--;
	}

	int sum = 0;
	for (int i = 0; i < 202; i++)
	{

		// 2�� �̻� ������ ���� ���� ���̸� ī��Ʈ
		sum += temp[i];
		if (2 <= sum) answer++;
	}

	return answer;
}