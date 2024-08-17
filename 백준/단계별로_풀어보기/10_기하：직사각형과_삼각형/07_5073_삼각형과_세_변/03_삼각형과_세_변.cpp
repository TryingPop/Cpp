/*
날짜 : 2024. 8. 17
이름 : 배성훈
내용 : 삼각형과 세 변
	문제번호 : 5073번

	수학, 구현, 기하학 문제다
*/

#include <iostream>
#include <string>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

using namespace std;

inline bool ChkInvalid(int _a, int _b, int _c)
{

	return _a + _b <= _c || _b + _c <= _a || _c + _a <= _b;
}

int main(void)
{

	const string INVALID = "Invalid\n";
	const string EQUIL = "Equilateral\n";
	const string ISOS = "Isosceles\n";
	const string SCALENE = "Scalene\n";

	int a, b, c;
	FAST_IO;

	while (true)
	{

		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;

		if (ChkInvalid(a, b, c)) cout << INVALID;
		else if (a == b && b == c && c == a) cout << EQUIL;
		else if (a == b || b == c || c == a) cout << ISOS;
		else cout << SCALENE;
	}

	return 0;
}