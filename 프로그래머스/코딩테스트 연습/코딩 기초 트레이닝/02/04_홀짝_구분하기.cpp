#include <iostream>

/*
날짜 : 2024. 2. 8
이름 : 배성훈
내용 : 홀짝 출력하기
	나머지 연산
*/

using namespace std;

int main4(void)
{

	int n;
	cin >> n;

	// if (n % 2 == 0) cout << "is even";
	// else cout << "is odd";

	// 비트 연산
	cout << n << " is " << ((n & 1) ? "even" : "odd");
	return 0;
}