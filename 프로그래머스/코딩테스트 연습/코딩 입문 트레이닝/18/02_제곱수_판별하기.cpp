/*
��¥ : 2024. 3. 20
�̸� : �輺��
���� : ������ �Ǻ��ϱ�
	� �ڿ����� �������� ��,
	������ ������ ��������� �Ѵ�
	n�� �Ű������� �־��� ��,
	n�� ��������� 1�� �ƴϸ� 2��
	return �ϴ� solution �Լ��� ����
*/

int solution(int _n)
{

	int answer = 2;

	for (int i = 1; i <= _n; i++)
	{

		if (i * i > _n) break;
		if (i * i < _n) continue;

		answer = 1;
		break;
	}

	return answer;
}