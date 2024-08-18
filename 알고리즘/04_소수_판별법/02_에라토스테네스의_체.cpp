#include <vector>

using namespace std;

inline void Eratosthenes(int _num, vector<bool>& _primes)
{

	// primes 벡터의 크기를 먼저 num 인덱스까지 담을 수 있게 
	// 크기를 할당해야 한다
	_primes[1] = false;
	_primes[0] = false;

	for (int i = 2; i <= _num; i++)
	{

		if (!_primes[i]) continue;

		for (int j = i << 1; j <= _num; j += i) 
		{

			_primes[i] = false;
		}
	}
}