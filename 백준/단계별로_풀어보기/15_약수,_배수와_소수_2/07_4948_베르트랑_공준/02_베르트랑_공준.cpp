/*
��¥ : 2024. 8. 29
�̸� : �輺��
���� : ����Ʈ�� ����
	������ȣ : 4948��

	����, ������, �Ҽ� ����, �����佺�׳׽� ü ������
*/

#include <iostream>
#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false);

#define endl	'\n'

using namespace std;

inline void Eratosthenes(vector<bool>& _prime)
{

	_prime.resize(250'000, true);
	_prime[0] = false;
	_prime[1] = false;

	for (int i = 2; i < 250'000; i++)
	{

		if (!_prime[i]) continue;
		for (int j = i << 1; j < 250'000; j += i)
		{

			_prime[j] = false;
		}
	}
}

inline void GetRet(const vector<bool>& _prime, vector<int>& _ret)
{

	_ret.resize(123'457, 0);
	int e = 0;
	int cnt = 0;
	for (int s = 1; s <= 123'456; s++)
	{

		if (_prime[s]) cnt--;

		for (int j = 0; j < 2; j++)
		{

			e++;
			if (s == e) continue;
			if (_prime[e]) cnt++;
		}

		_ret[s] = cnt;
	}
}

int main(void)
{

	vector<bool> prime;
	vector<int> ret;
	int n;

	FAST_IO;
	Eratosthenes(prime);
	GetRet(prime, ret);

	while (true)
	{

		cin >> n;
		if (n == 0) break;

		cout << ret[n] << endl;
	}

	return 0;
}