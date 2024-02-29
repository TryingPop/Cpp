/*
��¥ : 2024. 2. 29
�̸� : �輺��
���� : �ֻ��� ���� 1
	1 ~ 6���� ���� �ֻ��� 2���� �ִ�
	�� �ֻ����� ������ �� ���� ���� ���� a, b

	a, b �� ��� Ȧ����, a^2 + b^2�� ������ ��´�
	a, b �� �ϳ��� Ȧ���� 2 * (a + b)�� ������ ��´�
	a, b �� �� ¦���� |a - b| �� ������ ��´� ���⼭ |c|�� c�� ������ �ǹ��Ѵ�

	�� ���� a, b�� �־��� ��,
	��� ������ return �ϴ� solution �Լ��� ����
*/

// using namespace std;

int solution(int _a, int _b)
{

	int answer = 0;
	
	if ((_a & 1) && (_b & 1)) answer = _a * _a + _b * _b;
	else if ((_a & 1) || (_b & 1)) answer = 2 * (_a + _b);
	else answer = _a < _b ? _b - _a : _a - _b;

	return answer;
}