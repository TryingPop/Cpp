/*
��¥ : 2024. 3. 8
�̸� : �輺��
���� : ���� ���� �Ա� 2
	���ڸ� 6�������� �ڸ���
	���ڸ� ���� ���� ����� �� n�� �Ű������� �־�����
	n���� �ֹ��� ���ڸ� ������ �ʰ�
	��� ���� ���� ���� ������ ���� ��,
	�ֹ��ؾ��ϴ� �ּ� ���� �Ǽ��� return�ϴ� solution �Լ� ����
*/

int getgcd(int _a, int _b)
{

	if (_a < _b) 
	{

		int temp = _a;
		_a = _b;
		_b = temp;
	}

	while (_b > 0)
	{

		int temp = _a % _b;
		_a = _b;
		_b = temp;
	}

	return _a;
}

int solution(int _n)
{

	int answer;

	// 6���� �ִ� ������� ������ �̻����
	int gcd = getgcd(_n, 6);
	answer = _n / gcd;

	return answer;
}