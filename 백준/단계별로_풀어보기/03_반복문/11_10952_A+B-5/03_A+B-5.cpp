/*
날짜 : 2024. 8. 3
이름 : 배성훈
내용 : A + B - 5
	문제번호 : 10952번

	수학, 구현, 사칙연산 문제다
*/

#include <iostream>

#define fastio	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define endl '\n'
using namespace std;

int main(void)
{

	int a, b;
	fastio;
	
	while (true)
	{

		cin >> a >> b;
		if (a == 0 && b == 0) break;

		cout << a + b << endl;
	}

	return 0;
}