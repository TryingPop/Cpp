/*
날짜 : 2024. 8. 2
이름 : 배성훈
내용 : A + B - 8
	문제번호 : 11022번

	수학, 구현, 사칙연산 문제다
*/

#include <iostream>
#include <string>

#define fastio	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false);

#define endl '\n'
using namespace std;

const string CASE = "Case #";
const string AND = ": ";
const string PLUS = " + ";
const string EQUAL = " = ";

int main(void)
{

	int test, a, b;
	fastio;

	cin >> test;

	for (int i = 1; i <= test; i++)
	{

		cin >> a >> b;
		cout << CASE << i << AND << a << PLUS << b << EQUAL << a + b << endl;
	}

	return 0;
}