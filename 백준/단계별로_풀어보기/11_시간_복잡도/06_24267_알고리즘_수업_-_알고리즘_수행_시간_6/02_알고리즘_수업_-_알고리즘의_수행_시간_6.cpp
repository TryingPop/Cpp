/*
날짜 : 2024. 8. 19
이름 : 배성훈
내용 : 알고리즘 수업 - 알고리즘의 수행 시간 6
	문제번호 : 24267번

	수학, 구현, 시뮬레이션 문제다
*/

#include <iostream>

#define ll long long
#define endl	'\n'
using namespace std;

int main(void)
{

	ll n;
	cin >> n;

	cout << (n * (n - 1) * (n - 2)) / 6 << endl << 3;
	return 0;
}