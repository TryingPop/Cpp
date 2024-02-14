/*
��¥ : 2024. 2. 14
�̸� : �輺��
���� : �ֻ��� ���� 3
	1 ~ 6���� ���� �ֻ��� 4���� �ִ�
	�� ���� �ֻ������� ���� ���ڰ� ��� p�� ���ٸ� 1111 * p�� ��
	�� �ֻ������� ���� ���ڰ� p�� ���� ������ �ٸ� �ֻ������� ���� ���ڰ� q(!= p)���, (10 * p + q)^2��
	�ֻ����� �� ���� ���� ���� ������, ���� ���ڸ� ���� p, q��� �Ѵٸ� (p + q) * |p - q| (|a|�� a�� ���밪)��
	��� �� �ֻ������� ���� ���ڰ� p�� ���� ������ �� �ֻ������� ���� ���ڰ� ���� p�� �ٸ� q, r(!= q) �̶�� q * r��
	�� �ֻ������� ���� ���ڰ� ��� �ٸ��ٸ� ���� ���� �� ���� ���� ���� ��ŭ�� ������ ��´�

	�ֻ��� 4���� ������ ��, �� ��Ģ�� ������ ������ ��ȯ�ϴ� �Լ� �����
*/

int solution(int _a, int _b, int _c, int _d)
{

	int answer;
	int chk[7] = { 0, 0, 0, 0, 0, 0, 0 };		// C++11���� ����
	
	chk[_a]++;
	chk[_b]++;
	chk[_c]++;
	chk[_d]++;

	if (chk[_a] == 4) answer *= _a * 1111;
	else if (chk[_a] == 3)
	{

		int q = chk[_a] == chk[_b] ?
			(chk[_a] == chk[_c] ? _d : _c) : _b;

		answer = (10 * _a + q);
		answer *= answer;
	}
	else if (chk[_a] == 1 && chk[_b] == 3)
	{

		answer = (10 * _b + _a);
		answer *= answer;
	}
	else if (chk[_a] == 2 && chk[_b] == 2 && chk[_c] == 2)
	{

		if (_a == _b)
		{

			answer = _a - _c;
			answer *= _a + _c;
		}
		else
		{

			answer = _a - _b;
			answer *= _a + _b;
		}

		answer = answer < 0 ? -answer : answer;
	}
	else if (chk[_a] == 2)
	{

		if (_a == _b) answer = _c * _d;
		else if (_a == _c) answer = _b * _d;
		else answer = _b * _c;
	}
	else if (chk[_b] == 2)
	{

		if (_b == _c) answer = _a * _d;
		else answer = _a * _c;
	}
	else if (chk[_c] == 2) answer = _a * _b;
	else 
	{

		int min = _a;
		min = _b < min ? _b : min;
		min = _c < min ? _c : min;
		min = _d < min ? _d : min;

		answer = min;
	}
	return answer;
}