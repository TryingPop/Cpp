/*
��¥ : 2024. 3. 28
�̸� : �輺��
���� : ġŲ ����
	ġŲ�� ���Ѹ����� �� ������ ���� 1���� �ش�
	������ 10�� ������ ġŲ 1������ ���񽺷� ���� �� �ְ�,
	���� ġŲ���� ������ �ش�

	���Ѹ��� ġŲ�� �� chicken�� �Ű������� �־��� ��,
	���� �� �ִ� �ִ� ���� ġŲ�� ����
	return �ϵ��� solution �Լ� ����
*/

int solution(int _chicken)
{

	int answer = 0;

	while (_chicken > 0)
	{

		int temp = _chicken / 10;
		answer += temp;
		_chicken = _chicken % 10 + temp;
	}

	return answer;
}