/*
날짜 : 2024. 8. 9
이름 : 배성훈
내용 : 킹, 퀸, 룩, 비숍, 나이트, 폰
	문제번호 : 3003번

	수학, 구현, 사칙연산 문제다
*/

#include <iostream>
#include <vector>

#define EMPTY ' '
using namespace std;

int main(void)
{

	int n;
	vector<int> correct = { 1, 1, 2, 2, 2, 8 };

	for (int i = 0; i < 6; i++)
	{

		cin >> n;
		cout << correct[i] - n << EMPTY;
	}

	return 0;
}