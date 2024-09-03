/*
날짜 : 2024. 9. 3
이름 : 배성훈
내용 : 팩토리얼
	문제번호 : 10872번

	수학, 구현 문제다
*/

#include <iostream>

using namespace std;

inline int Factorial(int _n)
{

	if (_n <= 0) return 1;
	return _n * Factorial(_n - 1);
}

int main(void)
{

	int n;
	cin >> n;
	cout << Factorial(n);
	return 0;
}