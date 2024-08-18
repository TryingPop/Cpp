#include <vector>

using namespace std;

inline void Eratosthenes(int _num, vector<bool>& _primes)
{

	// primes ������ ũ�⸦ ���� num �ε������� ���� �� �ְ� 
	// ũ�⸦ �Ҵ��ؾ� �Ѵ�
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