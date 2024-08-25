/*
날짜 : 2024. 8. 25
이름 : 배성훈
내용 : 좌표 압축
	문제번호 : 18870번

	정렬, 좌표 압축 문제다
*/

#include <iostream>
#include <utility>
#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define EMPTY	 ' '

using namespace std;

struct Compact
{

	int num;
	int idx;

	Compact(const int _num, const int _idx)
		: num(_num), idx(_idx) { }
};

bool MyCompNum(const Compact& _f, const Compact& _b)
{

	return _f.num < _b.num;
}

bool MyCompIdx(const Compact& _f, const Compact& _b)
{

	return _f.idx < _b.idx;
}

void HeapSort(vector<Compact>& _arr, bool (*_comp)(const Compact& _f, const Compact& _b))
{

	int len = _arr.size();
	for (int i = 1; i < len; i++)
	{

		int cur = i;
		
		while (cur)
		{

			int parent = (cur - 1) >> 1;
			if (_comp(_arr[parent], _arr[cur]))
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

			int l = 2 * cur + 1;
			int r = 2 * cur + 2;

			if (r < len)
			{

				int next = _comp(_arr[l], _arr[r]) ? r : l;
				if (_comp(_arr[cur], _arr[next])) 
				{

					swap(_arr[cur], _arr[next]);
					cur = next;
					continue;
				}
			}
			else if (l < len)
			{

				if (_comp(_arr[cur], _arr[l]))
					swap(_arr[cur], _arr[l]);
			}

			break;
		}
	}
}

int main(void)
{

	vector<Compact> arr;
	int n, temp, newNum = -1;

	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		arr.push_back(Compact(temp, i));
	}

	bool (*cmp)(const Compact& _f, const Compact& _b) = MyCompNum;
	HeapSort(arr, cmp);

	temp = -(1e9 + 1);
	for (int i = 0; i < n; i++)
	{

		if (temp != arr[i].num) 
		{ 
			
			newNum++; 
			temp = arr[i].num;
		}

		arr[i].num = newNum;
	}

	cmp = MyCompIdx;
	HeapSort(arr, cmp);

	for (int i = 0; i < n; i++)
	{

		cout << arr[i].num << EMPTY;
	}

	return 0;
}