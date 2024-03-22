#include <vector>
#include <algorithm>

/*
��¥ : 2024. 3. 22
�̸� : �輺��
���� : �ִ� ����� 2
	���� �迭 numbers�� �Ű������� �־�����,
	numbers�� ���� �� 2���� ���� ���� �� �ִ�
	�ִ��� retun �ϴ� solution �Լ� ����

	numbers�� ������ ������ 1�� �����̴�
*/

using namespace std;

int solution(vector<int> _numbers)
{

	int answer = 0;

	// greedy
	// ��츦 �����ؼ� ���� l�� r�߿� �ִ��� ������ �� �� �ִ�
	sort(_numbers.begin(), _numbers.end());

	int l = _numbers[0] * _numbers[1];
	int r = _numbers[_numbers.size() - 1] * _numbers[_numbers.size() - 2];

	answer = l < r ? r : l;
	return answer;
}