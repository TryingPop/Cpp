#include <vector>

#define ull unsigned long long
using namespace std;

inline ull GetMul(ull _n, ull _m, ull _mod)
{

	/*
	
	��ⷯ ���� ����
	_mod�� int ������ ���� ������ �ʿ䰡 ����
	*/
	ull ret = 0;
	while (_m)
	{

		if (_m & 1) ret = (ret + _n) % _mod;

		_n = (_n + _n) % _mod;
		_m >>= 1;
	}

	return ret;
}

inline ull GetPow(ull _n, ull _exp, ull _mod)
{

	/*
	
	������������ pow ���ϱ�
	*/

	ull ret = 1;

	while (_exp)
	{

		if (_exp & 1ULL) ret = GetMul(ret, _n, _mod);

		_n = GetMul(_n, _n, _mod);
		_exp >>= 1;
	}

	return ret;
}

inline bool ChkNotPrime(ull _n, ull _a)
{

	/*
	
	�ռ������� Ȯ��
	*/

	// Ȧ���� ���ؼ��� �� �� �����Ƿ� ¦�� 2�� �ݷ�ó��
    if (_n <= 1) return true;
    else if (_n == 2 || _n == _a) return false;


    ull d = _n - 1;
    while (true)
    {

        ull temp = GetPow(_a, d, _n);
        if (temp == _n - 1) return false;
        else if (temp != 1) return true;

        if ((d & 1) == 1) return temp != 1 && temp != _n - 1;
        d >>= 1;
    }
}


inline bool Miller_Rabin(ull _n)
{

	/*
	
	�Ҽ� �Ǻ� _n�� ������ 
	ull���� unsigned int ���� Ȯ���� chk�� ����Ѵ�
	*/

	// unsinged long long ���� Ȯ��
	vector<int> chk = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41 };

	// unsigned int ����
	// vector<int> chk = { 2, 7, 61 };

	for (int num : chk)
	{

		if (ChkNotPrime(_n, num)) return false;
	}

	return true;
}