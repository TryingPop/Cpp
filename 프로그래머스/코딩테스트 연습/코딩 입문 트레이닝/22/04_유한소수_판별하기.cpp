/*
��¥ : 2024. 3. 24
�̸� : �輺��
���� : ���ѼҼ� �Ǻ��ϱ�
	�� ���� a�� b�� �Ű������� �־��� ��,
	a / b�� ���� �Ҽ��̸� 1�� ���� �Ҽ���� 2��
	return �ϴ� solution�Լ��� ����
*/

int getgcd(int _a, int _b)
{

	if (_a < _b)
	{

		int temp = _a;
		_a = _b;
		_b = temp;
	}

	while (_b)
	{

		int temp = _a % _b;
		_a = _b;
		_b = temp;
	}

	return _a;
}

int mydiv(int _a, int _q)
{

	// �ش� �Ҽ��� �ȳ��� ������ ������ ������
	while (!(_a % _q)) 
	{

		_a /= _q;
	}

	return _a;
}

int solution(int _a, int _b)
{

	int answer;

	int gcd = getgcd(_a, _b);
	_b /= gcd;

	_b = mydiv(_b, 2);
	_b = mydiv(_b, 5);

	// 2, 5 �̿��� ����� ����
	answer == _b == 1 ? 1 : 2;
	return answer;
}