/*
��¥ : 2024. 6. 19
�̸� : �輺��
���� : ����Ʈ
	����Ʈ�� �۾Ƽ� �� ���� �ִ� 2�� �ۿ� Ż �� ���� ���� ���ѵ� �ִ�
	����Ʈ�� �ִ��� ���� ����Ͽ� ��� ����� �����Ϸ��� �Ѵ�

	������� �����Ը� ���� �迭 people�� 
	����Ʈ�� ���� ���� limit�� �Ű������� �־��� ��,
	��� ����� �����ϱ� ���� �ʿ��� ����Ʈ ������ �ּڰ���
	return �ϴ� solution �Լ� ����

	����Ʈ�� ���� ������ �׻� ������� ������ �� �ִ񰪺��� ũ�� �־�����

	parameter
	{ 70, 50, 80, 50 }


	return
	3
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> _people, int _limit)
{

	int answer = _people.size();

	sort(_people.begin(), _people.end());

	int l = 0;
	int r = _people.size() - 1;

	while (l < r)
	{

		int cur = _people[l] + _people[r];
		if (cur <= _limit)
		{

			l++;
			r--;
			answer--;
		}
		else r--;
	}

	return answer;
}