#include <vector>
#include <algorithm>

/*
��¥ : 2024. 3. 13
�̸� : �輺��
���� : �ִ� ����� 1
	���� �迭 numbers�� �Ű������� �־��� ��,
	numbers�� ���� �� �� ���� ���� ���� �� �ִ�
	�ִ��� return �ϴ� solution �Լ� ����

	numbers�� ���Ҵ� ���̾ƴ� �����̰�
	ũ��� 2 �̻��̴�
*/

using namespace std;

int solution(vector<int> _numbers)
{

	int answer;

	// greedy
	sort(_numbers.begin(), _numbers.end(), greater<int>());
	answer = _numbers[0] * _numbers[1];

	return answer;
}