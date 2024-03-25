#include <vector>
#include <algorithm>

/*
��¥ : 2024. 3. 26
�̸� : �輺��
���� : Ư���� ����
	���� n�� �������� n�� ����� ������ �����Ϸ��� �Ѵ�
	n���κ����� �Ÿ��� ���ٸ� �� ū ���� �տ� ������ ��ġ
	������ ��� �迭 numlist�� ���� n�� �־��� ��,
	numlist�� ���Ҹ� n���κ��� ����� ������� ������
	�迭�� return �ϵ��� solution �Լ��� ����

	numlist�� ������ 1�̻� 10'000 ����
*/

using namespace std;

#if other
int n;

bool comp(int _f, int _b)
{

	int ret = abs(_f - n) - abs(_b - n);
	if (ret == 0) return _f > _b;
	else if (ret < 0) return 1;
	else return 0;
}
#endif

vector<int> solution(vector<int> _numlist, int _n)
{

	vector<int> answer;
	answer.reserve(_numlist.size());

#if other

	// �������� �ϴ� ���
	n = _n;
	sort(_numlist.begin(), _numlist.end(), comp);

	answer = _numlist;
#else
	// �������� int�� ���� comp�Լ��� ����� ���� �� �� �ִ�
	// pair�� �����غ��� ���� �ٸ� ������� Ǯ����
	vector<pair<int, int>> temp;
	temp.reserve(_numlist.size());

	for (int i = 0 ; i < _numlist.size(); i++)
	{

		pair<int, int> calc;
		// ���� ���� ��� ���� ��찡 �ڷΰ��� �����Ϸ��� 2��
		calc.first = 2 * (_numlist[i] - _n);
		if (calc.first < 0) calc.first = -calc.first + 1;
		calc.second = i;
	}

	sort(temp.begin(), temp.end());

	for (pair<int, int>& p : temp) 
	{

		answer.push_back(_numlist[p.second]);
	}
#endif
	return answer;
}