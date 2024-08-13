/*
날짜 : 2024. 8. 13
이름 : 배성훈
내용 : 달팽이는 올라가고 싶다
	문제번호 : 2869번

	수학
*/

#include <iostream>

using namespace std;

int main(void)
{

	int a, b, v, ret = 1;
	cin >> a >> b >> v;

	v -= a;
	if (v)
	{

		v--;
		ret += 1 + v / (a - b);
	}

	cout << ret;
	return 0;
}