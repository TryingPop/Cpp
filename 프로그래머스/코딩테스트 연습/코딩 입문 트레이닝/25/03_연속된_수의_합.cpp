#include <vector>

/*
��¥ : 2024. 3. 29
�̸� : �輺��
���� : ���ӵ� ���� ��
	�� ���� num�� total�� �־��� ��,
	���ӵ� �� num���� ���� ���� total�� �� ��,
	���� �迭�� ������������ ��� return �ϵ���
	solution �Լ��� ����

	num�� 1 ~ 100������ �ڿ����̰�,
	total�� 0 �̻� 1000 ������ �����̴�
*/

using namespace std;

vector<int> solution(int _num, int _total)
{

	vector<int> answer;
	answer.reserve(_num);

	// �켱 �ش� ������ �����Ѵ�!
	_total *= 2;
	int calc = _total / _num;

	// mid + r : ���� ������ �ǰ� �� ����
	int mid;
	int r;

	if (_num & 1)
	{

		// Ȧ��
		mid = calc / 2;
		r = _num / 2;
		r = -r;
	}
	else
	{

		// ¦��
		mid = 1 + calc / 2;
		r = _num / 2;
		r = -r;
	}

	for (int i = 0; i < _num; i++)
	{

		answer.push_back(mid + i + r);
	}

	return answer;
}