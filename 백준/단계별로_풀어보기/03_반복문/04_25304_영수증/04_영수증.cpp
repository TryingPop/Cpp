/*
날짜 : 2024. 8. 1
이름 : 배성훈
내용 : 영수증
	문제번호 : 25304번

	수학, 구현, 사칙연산 문제다
*/

#include <iostream>

#define fastio cin.tie(NULL);	\
			cout.tie(NULL);		\
			ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int n, sum = 0;
	int len, p, k;
	cin >> n >> len;

	for (int i = 0; i < len; i++)
	{

		cin >> p >> k;
		sum += p * k;
	}

	if (sum == n) cout << "Yes";
	else cout << "No";

	return 0;
}