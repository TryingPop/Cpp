#include<vector>

/*
��¥ : 2024. 3. 12
�̸� : �輺��
���� : �� ������
	�������� ���� �� ������ ���̸� �ϴ� ���̴�
	���� �� �տ� �ִ� ��� 1������ ������
	���������� �� ���� �ǳʶٰ� �� ����������� �����Ѵ�

	���� �迭 numbers�� ���� k�� �־��� ��,
	k��°�� ���� ������ ��� ��ȣ��
	return �ϴ� solution �Լ� ����
*/

using namespace std;

int solution(vector<int> _numbers, int _k)
{

	int answer;
	// 2ĭ�� �ǳʶڴ�, 0 -> 2 - > 4 -> ...
	// �׷��� _k * 2�� �ϰ�, ó���� 0�� �ε����̹Ƿ� -2�� ���ش�
	// �����̹Ƿ� ������ ���굵 ���ش�
	int idx = (_k * 2 - 2) % _numbers.size();
	answer = _numbers[idx];
	return answer;
}