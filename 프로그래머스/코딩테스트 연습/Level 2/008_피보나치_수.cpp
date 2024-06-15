/*
��¥ : 2024. 6. 15
�̸� : �輺��
���� : �Ǻ���ġ ��
	�Ǻ���ġ ���� F(0) = 0, F(1) = 1�̰�
	2�̻��� n�� ���Ͽ� F(n) = F(n - 1) + F(n - 2)��
	����Ǵ� ���̴�

	2 �̻��� n�� �ԷµǾ��� ��, n��° �Ǻ���ġ ����
	1234567���� ���� �������� return �ϴ� solution �Լ� ����

	n�� 2 �̻� 100'000 ������ �ڿ���

	parameter 
	5


	return 
	5
*/

int solution(int _n)
{

	int answer = 0;
	int calc = 1;

	for (int i = 1; i <= _n; i++)
	{

		int temp = (calc + answer) % 1234567;
		answer = calc;
		calc = temp;
	}

	return answer;
}