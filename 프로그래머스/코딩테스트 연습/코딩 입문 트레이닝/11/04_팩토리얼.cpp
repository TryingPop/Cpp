/*
��¥ : 2024. 3. 12
�̸� : �輺��
���� : ���丮��
	n ���丮�� n!��
	n! = 1 * 2 * 3 * ... * n
	����������̴�

	���� n�� �־��� ��, i! <= n��
	i�� �ִ밪�� return �ϴ� solution �Լ��� ����

	10! = 3'628'800�̴�
*/

int solution(int _n)
{

	int answer = 0;

	int fac = 1;
	for (int i = 1; i <= 10; i++)
	{

		fac *= i;
		// fac�� ū ��� Ż��
		if (_n < fac) break;
		// �۰ų� ���� ��� i�� ����Ѵ�
		answer++;
	}

	return answer;
}