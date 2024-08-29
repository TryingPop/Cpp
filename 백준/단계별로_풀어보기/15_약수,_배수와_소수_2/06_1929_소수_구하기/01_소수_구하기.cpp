/*
��¥ : 2024. 8. 29
�̸� : �輺��
���� : �Ҽ� ���ϱ�
	������ȣ : 1929��

	����, ������, �Ҽ� ����, �����佺�׳׽��� ü ������
*/

#include <iostream>
#include <vector>

#define endl	'\n'

using namespace std;

inline void Eratosthenes(vector<bool>& _prime) 
{

	_prime.resize(1'000'001, true);
	_prime[0] = false;
	_prime[1] = false;

	for (int i = 2; i <= 1'000'000; i++)
	{

		if (!_prime[i]) continue;
		for (int j = i << 1; j <= 1'000'000; j += i)
		{

			_prime[j] = false;
		}
	}
}

int main(void)
{

	vector<bool> prime;
	int s, e;

	cin >> s >> e;

	Eratosthenes(prime);

	for (int i = s; i <= e; i++)
	{

		if (prime[i]) cout << i << endl;
	}

	return 0;
}