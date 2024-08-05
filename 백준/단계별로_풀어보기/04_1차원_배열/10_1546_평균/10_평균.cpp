/*
날짜 : 2024. 8. 5
이름 : 배성훈
내용 : 평균
	문제번호 : 1546번

	수학, 사칙연산 문제다
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define max(A, B)	A < B ? B : A
using namespace std;

int main(void)
{

	int n, num, m = 0, sum = 0;
	FAST_IO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> num;
		sum += num;
		m = max(num, m);
	}

	cout << 100 * sum / (1.0 * n * m);
	return 0;
}