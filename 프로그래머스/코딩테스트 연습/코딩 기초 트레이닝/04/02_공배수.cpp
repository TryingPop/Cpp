/*
��¥ : 2024. 2. 10
�̸� : �輺��
���� : �����
	���� number, n, m�� �־��� ��,
	number�� n�� ����̸鼭 ���ÿ� m�� ����̸� 1, �ܴ̿� 0�� ��ȭ�ϴ� �Լ� �����
*/

int solution(int _number, int _n, int _m)
{

	int answer = 0;

	answer = (_number % _n == 0) && (_number % _m == 0);
	return 0;
}