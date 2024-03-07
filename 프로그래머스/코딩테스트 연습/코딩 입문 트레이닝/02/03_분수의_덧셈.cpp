#include <vector>

/*
��¥ : 2024. 3. 7
�̸� : �輺��
���� : �м��� ����
	ù ��° �м��� ���ڿ� �и� ���ϴ� numer1, denom1
	�� ��° �м��� ���ڿ� �и� ���ϴ� numer2, denom2
	�� ���� ������ �Ű������� �־�����

	�� �м��� ���� ���� ��� �м��� ��Ÿ���� ��
	���ڿ� �и� ������� ���� �迭��
	return�ϴ� solution �Լ� ����
*/

using namespace std;

int getgcd(int _a, int _b)
{

	// Euclid division algorithm���� gcd�� ã�´�
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

vector<int> solution(int _numer1, int _denom1, int _numer2, int _denom2)
{

	vector<int> answer;
	answer.reserve(2);

	// a / b + c / d = ad / bd + cb / bd
	int numer = _denom2 * _numer1 + _denom1 * _numer2;
	int denom = _denom1 * _denom2;

	// ���� ����� ���м��� �ƴ� ���� �ִ�
	// 1 / 6 + 1 / 6 = 2 / 6
	// �׷��� �ִ� ������� ã�� ������
	int gcd = getgcd(numer, denom);

	// �ִ������� ������ ���м�
	numer /= gcd;
	denom /= gcd;

	answer.push_back(numer);
	answer.push_back(denom);

	return answer;
}