/*
��¥ : 2024. 2. 10
�̸� : �輺��
���� : n�� ���
	���� num�� n�� �Ű������� �־��� ��,
	num�� n�� ����̸� 1, �ƴϸ� 0�� ����ϴ� �Լ� �����
*/

int solution(int _num, int _n) 
{

	int answer = 0;

	answer = _num % _n == 0;
	return answer;
}