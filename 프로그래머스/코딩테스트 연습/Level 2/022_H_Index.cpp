/*
��¥ : 2024. 7. 1
�̸� : �輺��
���� : H-Index
	H-Index�� ��Ÿ���� ���� h�� ã�ƾ��Ѵ�
	�� n�� ��, h�� �̻� �ο�� ���� h�� �̻��̰�
	������ ���� h�� ���� �ο�Ǿ��ٸ�
	h�� �ִ밪�� H-Index�̴�

	��ǥ�� ���� �ο� Ƚ���� ���� �迭 citations��
	�Ű������� �־��� ��,

	�� �������� H-Index�� return �ϴ�
	solution �Լ� ����


	parameter
	{ 3, 0, 6, 1, 5 }


	return 
	3


	sol
	1 �̻� 4��
	2 �̻� 3��
	3 �̻� 3��
	4 �̻� 2�� -> �Ұ���
	5 �̻� 2�� -> �Ұ���
	6 �̻� 1�� -> �Ұ���
	7 �̻� 0�� -> �Ұ���
	...

	�̹Ƿ� �ִ밪�� 3
*/
#if first
#include <vector>

#define MAX 10'000

using namespace std;

int solution(vector<int> _citations)
{

	int answer = 0;

	// ���������� �̻��� �� ������ ã��
	vector<int> cnt(MAX + 1, 0);

	for (const int i : _citations)
	{

		cnt[i]++;
	}

	for (int i = MAX - 1; i >= 0; i--)
	{

		cnt[i] = cnt[i] + cnt[i + 1];
	}

	int l = 0;
	int r = MAX;

	// ������ ��� �̺�Ž������ ã�´�
	while (l <= r)
	{

		int mid = (l + r) >> 1;

		// ������ ��� ���� ������ ����
		if (cnt[mid] >= mid) l = mid + 1;
		// �Ұ����ϸ� ���� ������ ����
		else r = mid - 1;
	}

	answer = l - 1;
	return answer;
}

#else

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> _citations) {

	// ��� ���Ұ� _citations.size() �̻��� ����
	int answer = _citations.size();

	sort(_citations.begin(), _citations.end(), greater<int>());

	for (int i = 0; i < _citations.size(); i++)
	{

		// ��� _citations[i] > i + 1 �� ���� _citations�� �ּҰ��� i �̻��� �����̴�
		if (_citations[i] > i + 1) continue;

		// _citations[i] <= i
		// �ǹ��ϴ°� _citations�� i�̻��� i�� �ִٴ� �ǹ��̴�
		// i�� �ִ밪���� ���� �� �ִ�
		answer = i;
		break;
	}

	return answer;
}
#endif