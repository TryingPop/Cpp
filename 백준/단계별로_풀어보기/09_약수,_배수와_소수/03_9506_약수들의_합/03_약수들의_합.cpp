/*
��¥ : 2024. 8. 14
�̸� : �輺��
���� : ������� ��
	������ȣ : 9506��

	����, ����, ������ ������
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define endl	'\n'
using namespace std;

inline bool FillDiv(const int _n, vector<int>& _div)
{

	int sum = 0;
	_div.clear();

	for (int i = 1; i * i <= _n; i++)
	{

		if (_n % i) continue;

		_div.push_back(i);
		sum += i;

		int j = _n / i;
		if (j == i) continue;

		sum += j;
		_div.push_back(j); 
	}

	sort(_div.begin(), _div.end());
	_div.pop_back();
	return sum == 2 * _n;
}

int main(void)
{

	const string NO = " is NOT perfect.";
	const string EQUAL = " = ";
	const string PLUS = " + ";

	int n;
	vector<int> div;

	div.reserve(1'000);

	while (true)
	{

		cin >> n;
		if (n == -1) break;

		if (FillDiv(n, div))
		{

			cout << n << EQUAL << div[0];

			for (int i = 1; i < div.size(); i++)
			{

				cout << PLUS << div[i];
			}

		}
		else cout << n << NO;

		cout << endl;
	}

	return 0;
}