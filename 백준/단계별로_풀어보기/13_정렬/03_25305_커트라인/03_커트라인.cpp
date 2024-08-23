/*
날짜 : 2024. 8. 23
이름 : 배성훈
내용 : 커트라인
	문제번호 : 25305번

	구현, 정렬 문제다
*/


#include <iostream>
#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

bool MyComp(int _f, int _b)
{

	return _b < _f;
}

void HeapSort(vector<int>& _vec)
{

	int len = _vec.size();

	if (len == 1) return;

	for (int i = 1; i < len; i++)
	{

		int cur = i;
		int parent = (cur - 1) >> 1;

		while (cur && MyComp(_vec[parent], _vec[cur]))
		{

			swap(_vec[parent], _vec[cur]);
			cur = parent;
			parent = (cur - 1) >> 1;
		}
	}

	len--;
	swap(_vec[0], _vec[len]);

	while (len > 1)
	{

		int cur = 0;


		while (true)
		{

			int l = cur * 2 + 1;
			int r = cur * 2 + 2;

			if (r < len)
			{

				int next;
				if (MyComp(_vec[l], _vec[r])) next = r;
				else next = l;

				if (MyComp(_vec[cur], _vec[next]))
				{

					swap(_vec[next], _vec[cur]);
					cur = next;
					continue;
				}
			}
			else if (l < len)
			{

				if (MyComp(_vec[cur], _vec[l]))
				{

					swap(_vec[l], _vec[cur]);
					cur = l;
				}
			}

			break;
		}

		len--;
		swap(_vec[0], _vec[len]);
	}
}

int main(void)
{

	int n, k, temp;
	vector<int> arr;

	FAST_IO;

	cin >> n >> k;
	arr.reserve(n);

	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		arr.push_back(temp);
	}

	HeapSort(arr);

	cout << arr[k - 1];
	return 0;
}