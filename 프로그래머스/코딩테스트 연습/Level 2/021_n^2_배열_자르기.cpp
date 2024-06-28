/*
��¥ : 2024. 6. 28
�̸� : �輺��
���� : n^2 �迭 �ڸ���
	���� n, left, right�� �־�����
	���� ������ ���ļ� 1���� �迭�� �����
		1. n�� n�� ũ���� ����ִ� 2���� �迭�� �����
		2. i = 1, 2, 3, ..., n�� ���� ���� ������ �ݺ��Ѵ�
			1�� 1������ i�� i�������� �������� ��� �� ĭ�� ���� i�� ä���
		3. 1��, 2��, ..., n���� �߶󳻾� ��� �̾���� ���ο� 1���� �迭�� �����
		4. ���ο� 1���� �迭�� arr�̶� �� ��,
			arr[left], arr[left + 1], ... , arr[right]�� ����� �������� �����

	�ش� ������ ���� ������� 1���� �迭��
	return �ϴ� solution �Լ� ����

	n�� 10^7 ������ �ڿ���
	left <= right�̰�, right�� n^2���� �۴�
	right - left �� 10�� �̸��̴�


	parameter
	3, 2, 5


	return
	{ 3, 2, 2, 3 }


	sol
	3ũ���� 2���� �迭�� ����� ������ ����
		1 2 3
		2 2 3
		3 3 3
	�׸��� 1���� �迭�� �����ϸ�
		1 2 3 2 2 3 3 3 3
	���⼭ 2������ 5��������
		3 2 2 3
*/

#include <string>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> solution(int _n, ll left, ll right)
{

	vector<int> answer;
	int len = right - left + 1;
	answer.reserve(len);

	ll row, col;
	for (ll i = left; i <= right; i++) 
	{

		row = left / _n;
		col = right % _n;

		answer.push_back(max(row, col) + 1);
	}

	return answer;
}