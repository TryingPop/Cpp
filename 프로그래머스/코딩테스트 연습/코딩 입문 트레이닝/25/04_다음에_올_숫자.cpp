#include <vector>

/*
��¥ : 2024. 3. 29
�̸� : �輺��
���� : ������ �� ����
	�������� Ȥ�� ������ common�� �Ű������� �־��� ��,
	������ ���� �������� �� ���ڸ� return �ϵ���
	solution �Լ��� ����

	�������� Ȥ�� �������� ���� ����
	�������� ��� ����� 0�̾ƴ� ����!
*/

using namespace std;

int solution(vector<int> _common)
{

	int answer;

	int d = _common[1] - _common[0];
	int r = _common[1] / _common[0];

	// ���������� ��� ������ ���ϰ�
	if (d == _common[2] - _common[1]) answer = _common.back() + d;
	// ��� �����̸� ���� ���Ѵ�
	else answer = _common.back() * r;

	return answer;
}