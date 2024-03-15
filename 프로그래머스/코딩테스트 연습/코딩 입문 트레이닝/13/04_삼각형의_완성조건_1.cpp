#include <vector>

/*
날짜 : 2024. 3. 15
이름 : 배성훈
내용 : 삼각형의 완성조건 1
	선분 세 개로 삼각형을 만들기 위해서는
	다음 조건을 만족해야한다

	가장 긴 변의 길이는 다른 두변의 길이의 합보다
	작아야 한다

	삼각형의 세변의 길이가 담긴 배열 sides가 매개변수로
	주어질 때, 세 변으로 삼각형을 만들 수 있다면 1을
	만들 수 없다면 2를 return 하는 solution 함수 구현
*/

using namespace std;

int solution(vector<int> _sides)
{

	int answer;

	// 정렬해서 하거나 상황 나누는걸로 해도 되나
	// 일일히 확인하는 브루트 포스로 했다
	bool possible = _sides[0] < _sides[1] + _sides[2];
	possible &= _sides[1] < _sides[2] + _sides[0];
	possible &= _sides[2] < _sides[0] + _sides[1];

	answer = possible ? 1 : 2;
	return answer;
}