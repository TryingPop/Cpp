/*
날짜 : 2024. 8. 24
이름 : 배성훈
내용 : 좌표 정렬하기 2
	문제번호 : 11651번

	정렬 문제다
*/

#include <iostream>
#include <vector>
#include <utility>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define endl	'\n'

using namespace std;

struct Pos
{

	int x;
	int y;

	Pos(int _x, int _y)
		: x(_x), y(_y) { }
};

inline bool MyComp(Pos& _f, Pos& _b)
{

	if (_f.y != _b.y) return _f.y < _b.y;
	return _f.x < _b.x;
}

void HeapSort(vector<Pos>& _arr)
{

	int len = _arr.size();


	for (int i = 1; i < len; i++)
	{

		int cur = i;
		while (cur)
		{

			int parent = (cur - 1) / 2;
			if (MyComp(_arr[parent], _arr[cur]))
			{

				swap(_arr[cur], _arr[parent]);
				cur = parent;
			}
			else break;
		}
	}

	while (len > 1)
	{

		len--;
		swap(_arr[0], _arr[len]);

		int cur = 0;
		while (cur < len)
		{

			int l = cur * 2 + 1;
			int r = cur * 2 + 2;

			if (r < len)
			{

				int next = MyComp(_arr[l], _arr[r]) ? r : l;

				if (MyComp(_arr[cur], _arr[next]))
				{

					swap(_arr[cur], _arr[next]);
					cur = next;
					continue;
				}
			}
			else if (l < len)
			{

				if (MyComp(_arr[cur], _arr[l]))
				{

					swap(_arr[cur], _arr[l]);
					cur = l;
				}
			}

			break;
		}
	}
}

int main(void)
{

	int n, x, y;
	vector<Pos> pos;

	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> x >> y;
		pos.push_back(Pos(x, y));
	}

	HeapSort(pos);

	for (int i = 0; i < n; i++)
	{

		cout << pos[i].x << ' ' << pos[i].y << endl;
	}

	return 0;
}