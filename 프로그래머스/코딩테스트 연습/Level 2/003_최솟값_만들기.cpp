/*
��¥ : 2024. 6. 10
�̸� : �輺��
���� : �ּڰ� �����
	���̰� ���� �迭 A, B �� ������ �ִ�
	�迭�� �ڿ����� �̷��� �ִ�

	�迭 A, B���� ���� �� ���� ���ڸ� �̾�
	�� ���� ���Ѵ�

	�̷��� ������ �迭�� ���̸�ŭ �ݺ��ϸ�,
	�� ���� ���� �� �����Ͽ� ���Ѵ�

	�̶� ���������� ������ ���� �ּҰ� �ǵ���
	����� ���� ��ǥ�̴�

	���⼭ �� �迭���� k��° ���ڸ� �̾Ҵٸ�
	������ k��° ���ڴ� �ٽ� ���� �� ����

	A, B�� ���̴� 1'000������ �ڿ���
	A, B�� ������ ũ��� 1'000������ �ڿ���

	parameter
	{ 1, 4, 2 }, { 5, 4, 4 }

	return
	29
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> _A, vector<int> _B)
{

	int answer = 0;

	sort(_A.begin(), _A.end());
	sort(_B.begin(), _B.end(), greater<int>());

	for (int i = 0; i < _A.size(); i++)
	{

		answer += _A[i] * _B[i];
	}

	return answer;
}