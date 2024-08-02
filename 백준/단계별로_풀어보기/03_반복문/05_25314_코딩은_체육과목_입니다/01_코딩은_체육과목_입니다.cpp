/*
날짜 : 2024. 8. 2
이름 : 배성훈
내용 : 코딩은 체육과목 입니다
	문제번호 : 25314번
*/

#include <iostream>
#include <string>

#define fastio cin.tie(NULL);		\
			cout.tie(NULL);			\
			ios_base::sync_with_stdio(false)
using namespace std;

const string LONG = "long ";

int main(void)
{

	int n;
	fastio;

	cin >> n;
	n /= 4;

	for (int i = 0; i < n; i++)
	{

		cout << LONG;
	}

	cout << "int";

	return 0;
}