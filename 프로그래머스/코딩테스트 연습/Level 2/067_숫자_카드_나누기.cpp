/*
��¥ : 2024. 8. 11
�̸� : �輺��
���� : ���� ī�� ������
	ö���� ����� ���������κ��� ���ڰ� �ϳ��� ����
	ī����� ���ݾ� ������ ���� ��,
	���� �� ���� �� �ϳ��� �����ϴ� 
	���� ū ���� ���� a�� ���� ���Ϸ��� �Ѵ�

	1. ö���� ���� ī��鿡 ���� ��� ���ڸ� ���� �� �ְ�
	���� ���� ī��鿡 ���� ��� ���ڵ� �� �ϳ��� ���� �� ���� ���� ���� a

	2. ���� ���� ī��鿡 ���� ��� ���ڸ� ���� �� �ְ�,
	ö���� ���� ī��鿡 ���� ��� ���ڵ� �� �ϳ��� ���� �� ���� ���� ���� a

	ö���� ���� ī�忡 ���� ���ڵ��� ��Ÿ���� ���� �迭 arrayA,
	���� ���� ī�忡 ���� ���ڵ��� ��Ÿ���� ���� �迭 arrayB��
	�־��� ��,

	�־��� ������ �����ϴ� ���� ū ���� ���� a�� 
	return �ϴ� solution �Լ��� ����
	���� ������ �����ϴ� a�� ���ٸ� 0�� return

	arrayA�� ���̿� arrayB�� ���̴� ������ 50�� ������ �ڿ����̴�
	arrayA, arrayB�� ���Ҵ� 1�� ������ �ڿ����̰� �ߺ��� ���Ұ� ���� �� �ִ�

	parameter
	{ 10, 20 }, { 5, 17 }


	return
	10

	
	sol
	10�� ö�� ī���� 10, 20�� ��� ������ ���� ū ����
	�ݸ� 5, 17�� ������ ���Ѵ�

	5, 17�� ������ ���� 1�ۿ� ����
	10, 20�� 1�� ���� �������Ƿ�
	����ī�带 ��� ������ ö��ī�带 ������ �ʴ� ���� ����
*/

#include <vector>
#include <cmath>

using namespace std;

inline int EuclidGCD(int _a, int _b)
{

	/*
	
	GCD
	*/

	while (_b)
	{

		int temp = _a % _b;
		_a = _b;
		_b = temp;
	}

	return _a;
}

inline int GetArrGCD(vector<int>& _arr)
{

	/*
	
	arr��ü�� GCD
	*/

	int gcd = _arr[0];
	for (int i = 1; i < _arr.size(); i++)
	{

		gcd = EuclidGCD(gcd, _arr[i]);
		if (gcd == 1) return 1;
	}

	return gcd;
}

inline bool NotDivArr(vector<int>& _arr, int _div)
{

	/*
	
	div�� arr�� ���Ҹ� ��� �ϳ� �������� Ȯ��
	*/

	for (int num : _arr)
	{

		if (num % _div) continue;
		return false;
	}

	return true;
}

int solution(vector<int> _arrayA, vector<int> _arrayB)
{

	/*
	
	����
	��ü�� array?�� gcd��
	array?�� ��� ���ڸ� ���� �� �ִ� ���� ū ����

	�׸���, arrayA�� gcd�� gcdA��
	arrayB�� ��� �ϳ��� ���Ҹ� �����ٸ�
	gcdA�� ��� ������� �� ���Ҹ� ������

	�׷��� gcdA�� arrayB�� �������� Ȯ���ϸ� �ȴ�
	��� �ϳ��� ������ ��� a�� �������� �ʴ´�
	�ݸ� ��� ������ ������ gcdA�� a�� �ĺ��� �ȴ�
	arrayB�� �Ȱ��� Ȯ���Ѵ�
	
	a�� �ĺ��� �������� �ʴ� ��� ������ ����
	a�� �ĺ��� �����ϴ� ��� ���� ū ���� a�� �ȴ�
	*/

	int answer;

	int gcdA = GetArrGCD(_arrayA);
	int gcdB = GetArrGCD(_arrayB);

	bool chk1 = NotDivArr(_arrayB, gcdA);
	bool chk2 = NotDivArr(_arrayA, gcdB);

	if (chk1 && chk2) answer = max(gcdA, gcdB);
	else if (chk1) answer = gcdA;
	else if (chk2) answer = gcdB;
	else answer = 0;

	return answer;
}