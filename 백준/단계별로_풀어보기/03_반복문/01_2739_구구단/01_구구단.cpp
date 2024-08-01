/*
날짜 : 2024. 8. 1
이름 : 배성훈
내용 : 구구단
	문제번호 : 2739번
*/

#include <iostream>

#define endl '\n'
using namespace std;

int main(void)
{

	int dan;
	cin >> dan;

	for (int i = 1; i <= 9; i++)
	{

		cout << dan << " * " << i << " = " << dan * i << endl;
	}

	return 0;
}