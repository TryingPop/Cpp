/*
날짜 : 2024. 7. 30
이름 : 배성훈
내용 : 시험 성적
	문제번호 : 9498번

	구현 문제다
*/

#include <iostream>

using namespace std;

int main(void)
{

	int score;
	cin >> score;

	if (score >= 90) cout << 'A';
	else if (score >= 80) cout << 'B';
	else if (score >= 70) cout << 'C';
	else if (score >= 60) cout << 'D';
	else cout << 'F';

	return 0;
}