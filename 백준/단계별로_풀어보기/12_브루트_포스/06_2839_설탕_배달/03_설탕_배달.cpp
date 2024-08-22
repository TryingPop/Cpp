/*
날짜 : 2024. 8. 22
이름 : 배성훈
내용 : 설탕 배달
	문제번호 : 2839번

	수학, dp, 그리디 문제다
*/

#include <iostream>
#include <vector>

#define Min(X, Y)	(((X) < (Y)) ? (X) : (Y))
using namespace std;

int main(void)
{

#if first

	int n, m, ret = -1;
	cin >> n;
	// gcd(3, 5) = 1이므로
	// 적당한 수 k 보다 큰 m들은 a * 3 + b * 5 = m 형태로 표현가능하다
	// 손계산으로 해보니 8부터 모든 수를 표현가능
	// 8 ~ 22 까지만 찾고, 그리디 알고리즘으로 8 +15 는 8개수 + 5 짜리 * 3개 넣으면 최소이므로
	// 23 이상의 숫자는 8 ~ 23범위로 만들어 찾는다
	int chkArr[15] = { 2, 3, 2, 3, 4, 3, 4, 3, 4, 5, 4, 5, 4, 5, 6 };

	if (n <= 7)
	{

		// 8 미만 반례처리
		if (n == 3 || n == 5) ret = 1;
		else if (n == 6) ret = 2;
	}
	else 
	{

		n -= 8;
		m = n / 15;
		n %= 15;

		ret = 3 * m + chkArr[n];
	}

	cout << ret;
#else

	int n;
	cin >> n;
	vector<int> arr(5'005, -1);
	arr[0] = 0;
	arr[3] = 1;

	for (int i = 5; i <= n; i++)
	{

		if (arr[i - 3] > -1 && arr[i - 5] > -1) arr[i] = Min(arr[i - 3], arr[i - 5]) + 1;
		else if (arr[i - 3] > -1) arr[i] = arr[i - 3] + 1;
		else if (arr[i - 5] > -1) arr[i] = arr[i - 5] + 1;
	}

	cout << arr[n];
#endif
	return 0;
}