/*
날짜 : 2024. 8. 17
이름 : 배성훈
내용 : 대지
	문제번호 : 9063번

	수학, 구현, 기하학
*/

#include <iostream>

#define max(X, Y)	(((X) < (Y)) ? (Y) : (X))
#define min(X, Y)	(((X) < (Y)) ? (X) : (Y))

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int n, x, y, minX = 1e5, minY = 1e5, maxX = -1e5, maxY = -1e5;

	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> x >> y;
		minX = min(minX, x);
		maxX = max(maxX, x);

		minY = min(minY, y);
		maxY = max(maxY, y);
	}

	cout << (maxX - minX) * (maxY - minY);
	return 0;
}