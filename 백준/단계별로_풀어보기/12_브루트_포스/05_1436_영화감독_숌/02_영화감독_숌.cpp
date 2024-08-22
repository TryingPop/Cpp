/*
��¥ : 2024. 8. 22
�̸� : �輺��
���� : ��ȭ���� ��
	������ȣ : 1436��

	���Ʈ���� ������
*/

#include <iostream>
#include <vector>

#define Min(X, Y)	(((X) < (Y)) ? (X) : (Y))

using namespace std;

#if first
inline int Pow(int _n, int _exp)
{

	int ret = 1;
	while (_exp)
	{

		if (_exp & 1) ret *= _n;
		_exp >>= 1;
		_n *= _n;
	}

	return ret;
}
#else

inline bool Chk666(int _n) 
{

	int cnt = 0;

	while (_n)
	{

		int chk = _n % 10;
		_n /= 10;

		if (chk == 6) cnt++;
		else cnt = 0;

		if (cnt == 3) return true;
	}

	return false;
}
#endif



int main(void)
{

	int n;
	cin >> n;

#if first
	vector<int> arr(9);

	// �þ�� �ڸ��� Ȯ��
	// �տ������� ���� Ȯ���ߴ�
	for (int i = 0; i < arr.size(); i++)
	{

		arr[i] = Pow(10, i);
		for (int j = 1; j <= Min(3, i); j++)
		{

			arr[i] += 9 * arr[i - j];
		}
	}

	// ���� ������ ���� ���� Ȯ��
	int len = 0;
	for (int i = 0; i < arr.size(); i++)
	{

		if (n > arr[i]) len++;
		else break;
	}

	vector<int> ret(len + 3, 0);

	int curLen = 0;
	int std = n - 1;
	int l = 0;
	int r = arr[len] - 1;
	int conn = 0;

	while (curLen < len + 3)
	{

		if (curLen == len) 
		{

			// �ڿ� 666�� �ִ� ���
			for (int i = 0; i < 3 - conn; i++) 
			{

				ret[curLen++] = 6;
			}
			break;
		}

		// �տ������� ���ڸ� ä���ִ´�
		int lSub = std - l;
		int rSub = r - std;
		int lChk = lSub / arr[len - curLen - 1];

		if (lChk < 6)
		{

			// 0 ~ 6 : Ȯ��
			l += lChk * arr[len - curLen - 1];
			r = l + arr[len - curLen - 1] - 1;
			ret[curLen++] = lChk;
			conn = 0;
			continue;
		}

		l += 6 * arr[len - curLen - 1];
		int rChk = rSub / arr[len - curLen - 1];
		if (rChk < 3)
		{

			// 7, 8, 9 Ȯ��
			r -= rChk * arr[len - curLen - 1];
			l = r - arr[len - curLen - 1] + 1;
			ret[curLen++] = 9 - rChk;
			conn = 0;
			continue;
		}

		// 6�ΰ�츸 ���� �ݷ�ó��
		r -= 3 * arr[len - curLen - 1];
		ret[curLen++] = 6;
		conn++;

		// 6�� ���޾� 3��?
		if (conn == 3) break;
	}

	while (curLen < len + 3)
	{

		// 6�� ���޾� 3�� ���°��
		int sub = std - l;
		for (int i = len + 2; i >= curLen; i--)
		{

			ret[i] = sub % 10;
			sub /= 10;
			if (sub == 0) break;
		}

		curLen = len + 3;
	}

	for (int i = 0; i < ret.size(); i++)
	{

		cout << ret[i];
	}
#else

	int num = 665;

	while (n)
	{

		num++;
		if (Chk666(num)) n--;
	}

	cout << num;
#endif
	return 0;
}