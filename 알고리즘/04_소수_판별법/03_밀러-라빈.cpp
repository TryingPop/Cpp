#include <vector>

#define ull unsigned long long
using namespace std;

inline ull GetMul(ull _n, ull _m, ull _mod)
{

	/*
	
	모듈러 곱셈 정의
	_mod가 int 범위면 따로 정의할 필요가 없다
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
	
	분할정복으로 pow 구하기
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
	
	합성수인지 확인
	*/

	// 홀수에 대해서만 할 수 있으므로 짝수 2는 반례처리
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
	
	소수 판별 _n의 범위가 
	ull인지 unsigned int 인지 확인해 chk를 써야한다
	*/

	// unsinged long long 범위 확인
	vector<int> chk = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41 };

	// unsigned int 범위
	// vector<int> chk = { 2, 7, 61 };

	for (int num : chk)
	{

		if (ChkNotPrime(_n, num)) return false;
	}

	return true;
}