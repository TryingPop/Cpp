/*
날짜 : 2024. 8. 14
이름 : 배성훈
내용 : 배수와 약수
	문제번호 : 5086번

	수학, 사칙연산 문제다
*/

#include <iostream>
#include <string>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	const string MUL = "multiple\n";
	const string FAC = "factor\n";
	const string NEI = "neither\n";

	int a, b;
	bool chk1, chk2;
	FAST_IO;

	while (true)
	{

		cin >> a >> b;

		if (a == 0 && b == 0) break;

		chk1 = b % a == 0;
		chk2 = a % b == 0;

		if (chk1) cout << FAC;
		else if (chk2) cout << MUL;
		else cout << NEI;
	}

	return 0;
}