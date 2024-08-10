/*
날짜 : 2024. 8. 10
이름 : 배성훈
내용 : 너의 평점은
	문제번호 : 25206번

	수학, 구현, 문자열 문제다
*/

#include <iostream>
#include <string>
#include <map>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define PASS "P"
using namespace std;

int main(void)
{

	double sum = 0.0, time;
	int sTime = 0;
	string str;

	map<string, double> gTc;

	FAST_IO;

	gTc["A+"] = 4.5;
	gTc["A0"] = 4.0;
	gTc["B+"] = 3.5;
	gTc["B0"] = 3.0;
	gTc["C+"] = 2.5;
	gTc["C0"] = 2.0;
	gTc["D+"] = 1.5;
	gTc["D0"] = 1.0;
	gTc["F"] = 0.0;

	for (int i = 0; i < 20; i++)
	{

		cin >> str >> time >> str;
		if (str == PASS) continue;
		sTime += time;
		sum += gTc[str] * time;
	}

	cout << sum / sTime;

	return 0;
}