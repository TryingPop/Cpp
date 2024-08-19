/*
��¥ : 2024. 8. 19
�̸� : �輺��
���� : �� ���� ���
	n���� ����� �Ϸķ� ���� ���� �ִ�
	n���� ����鿡�Դ� ���� 1������ n������ ��ȣ�� �Ű��� �ִ�
	n���� ����� ���� ���� ����� �������� ����� �ִ�

	����� �� n�� �ڿ��� k�� �־��� ��,
	����� �����ϴ� ����� ���������� ���� ���� ��,
	k��° ����� return �ϴ� solution �Լ��� ����

	n�� 20������ �ڿ���
	k�� n! ������ �ڿ���


	parameter
	3, 5


	return
	{ 3, 1, 2 }


	sol
	3���� ����� ���� ���� ����� ������ ����
		1,	2,	3
		1,	3,	2
		2,	1,	3
		2,	3,	1
		3,	1,	2
		3,	2,	1

	���⼭ ���������� 5��°��
	{ 3, 1, 2}�� �ȴ�
*/

#include <vector>

#define ll long long

using namespace std;

inline vector<ll> GetChkDigitVec(int _n)
{


	/*
	
	�ڸ� ���� ���ڰ� ���°���� �ٲ���� Ȯ���ϴ� 
	���ڸ� ���ͷ� ��ȯ

	i��° �ڸ��� (n - i - 1)! ���� �ٲ��
	�׷��� (n - 1)!, (n - 2)!, ..., 0! ������ ��´�
	*/
	vector<ll> ret;

	ret.push_back(1);

	ll cur = 1;

	for (int i = 1; i < _n; i++)
	{

		cur *= i;
		ret.push_back(cur);
	}

	for (int i = 0; i < ret.size(); i++)
	{

		int j = ret.size() - 1 - i;
		if (j <= i) break;
		ll temp = ret[i];
		ret[i] = ret[j];
		ret[j] = temp;
	}

	return ret;
}

inline int GetNum(int _nth, vector<bool>& _use)
{

	/*
	
	�����ִ� ��� �� nth ��° ��� ��ȯ
	*/
	for (int i = 1; i < _use.size(); i++)
	{

		if (_use[i]) continue;
		_nth--;

		if (_nth) continue;
		_use[i] = true;
		return i;
	}

	// �ش� �������� ����� �ȿ´�
	return -1;
}

vector<int> solution(int _n, ll _k)
{

	vector<int> answer;

	vector<ll> chkDigitVec = GetChkDigitVec(_n);
	vector<bool> use(_n + 1, false);

	_k--;

	for (int i = 0; i < _n; i++)
	{

		// �ڸ� ���� ����� �����
		int nth = _k / chkDigitVec[i];
		_k -= nth * chkDigitVec[i];

		nth++;
		int add = GetNum(nth, use);
		answer.push_back(add);
	}

	return answer;
}