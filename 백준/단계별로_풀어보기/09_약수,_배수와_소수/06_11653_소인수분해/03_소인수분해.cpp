/*
날짜 : 2024. 8. 15
이름 : 배성훈
내용 : 소인수분해
	문제번호 : 11653번

	수학, 정수론, 소수판정 문제다
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define endl	'\n'
using namespace std;

int main(void)
{

	int n;
	FAST_IO;

	cin >> n;
	for (int i = 2; i * i <= n; i++)
	{

		while (n % i == 0)
		{

			n /= i;
			cout << i << endl;
		}
	}

	if (n > 1) cout << n;
	return 0;
}