/*
날짜 : 2024. 8. 13
이름 : 배성훈
내용 : 벌집
	문제번호 : 2292번

	수학 문제다
*/

#include <iostream>

using namespace std;

int main(void)
{

	int n;
	cin >> n;

	int ret = 1;
	n--;
	int diff = 6;

	while (n > 0)
	{

		n -= diff;
		ret++;
		diff += 6;
	}

	cout << ret;
	return 0;
}