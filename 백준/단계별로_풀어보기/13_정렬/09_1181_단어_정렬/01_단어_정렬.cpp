/*
날짜 : 2024. 8. 25
이름 : 배성훈
내용 : 단어 정렬
	문제번호 : 1181번

	문자열, 정렬 문제다
*/

#include <iostream>
#include <string>
#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false);

#define endl	'\n'

using namespace std;

bool MyComp(string& _f, string& _b)
{

	if (_f.length() != _b.length()) return _f.length() < _b.length();
	return _f < _b;
}

void HeapSort(vector<string>& _arr)
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

				swap(_arr[parent], _arr[cur]);
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
					swap(_arr[cur], _arr[l]);
			}

			break;
		}
	}
}

int main(void)
{

	int n;
	vector<string> arr;
	string temp;

	FAST_IO;

	cin >> n;
	arr.reserve(n);

	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		arr.push_back(temp);
	}

	HeapSort(arr);
	temp = "";
	for (int i = 0; i < arr.size(); i++)
	{

		if (temp == arr[i]) continue;
		cout << arr[i] << endl;
		temp = arr[i];
	}

	return 0;
}