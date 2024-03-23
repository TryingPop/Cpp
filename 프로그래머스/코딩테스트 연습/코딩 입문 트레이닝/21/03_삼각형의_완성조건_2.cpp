#include <vector>

/*
날짜 : 2024. 3. 23
이름 : 배성훈
내용 : 삼각형의 완성조건 2
	선분 세 개로 삼각형을 만들기 위해서는
	가장 긴 변의 길이는 다른 두변의 길이의
	합보다 작아야한다

	삼각형의 두 변의 길이가 담긴 배열
	sides이 매개변수로 주어질 때,

	나머지 한 변이 될 수 있는
	정수의 개수를 return 하도록
	solution 함수를 구현

	sides의 원소의 크기는 1 이상 1000 이하인 자연수이다
*/

using namespace std;

bool ChkTriangle(int _a, int _b, int _c)
{

	// 삼각형이 되는지 확인
	if (_a + _b <= _c || _b + _c <= _a || _c + _a <= _b) return false;
	return true;
}

int solution(vector<int> _sides)
{

	int answer = 0;
	for (int i = 1; i <= 2'000; i++)
	{

		if (ChkTriangle(_sides[0], _sides[1], i)) answer++;
	}

	return answer;
}