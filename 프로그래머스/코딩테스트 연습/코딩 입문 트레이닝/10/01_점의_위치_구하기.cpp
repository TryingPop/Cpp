#include <vector>

/*
��¥ : 2024. 3. 12
�̸� : �輺��
���� : ���� ��ġ ���ϱ�
	x��ǥ�� y��ǥ�� ���ʴ�� ���� (x, y) ���� �迭
	dot�� �Ű������� �־��� ��,

	��ǥ dot�� ��ī��Ʈ ������ǥ���� ��и� ��
	��� ���ϴ��� 1, 2, 3, 4 �� �ϳ���
	return �ϴ� solution �Լ� ����

	�� dot�� ���Ҵ� 0�� �ƴϴ�
*/

using namespace std;

int solution(vector<int> _dot)
{

	int answer;

	if (_dot[0] > 0 && _dot[1] > 0) answer = 1;
	else if (_dot[1] > 0) answer = 2;
	else if (_dot[0] < 0 && _dot[1] < 0) answer = 3;
	else answer = 4;

	return answer;
}