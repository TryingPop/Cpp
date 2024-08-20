/*
날짜 : 2024. 8. 20
이름 : 배성훈
내용 : 블랙잭
	문제번호 : 2798번

	브루트포스 문제다
*/

#include <iostream>
#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int n, m, num, ret;
	vector<int> arr;

	FAST_IO;

	cin >> n >> m;
	arr.reserve(n);

	for (int i = 0; i < n; i++)
	{

		cin >> num;
		arr.push_back(num);
	}

	ret = 0;

	for (int i = 0; i < n; i++)
	{

		for (int j = i + 1; j < n; j++)
		{

			for (int k = j + 1; k < n; k++)
			{

				num = arr[i] + arr[j] + arr[k];
				if (num > m || ret >= num) continue;
				ret = num;
			}
		}
	}

	cout << ret;
	return 0;
}