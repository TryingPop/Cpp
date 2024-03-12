#include <vector>

/*
날짜 : 2024. 3. 12
이름 : 배성훈
내용 : 점의 위치 구하기
	x좌표와 y좌표를 차례대로 담은 (x, y) 정수 배열
	dot이 매개변수로 주어질 때,

	좌표 dot이 데카르트 직교좌표계의 사분면 중
	어디에 속하는지 1, 2, 3, 4 중 하나를
	return 하는 solution 함수 구현

	단 dot의 원소는 0이 아니다
*/

using namespace std;

int solution(vector<int> _dot)
{

	int answer;

	if (_dot[0] > 0 && _dot[1] > 0) answer = 1;
	else if (_dot[1] > 0) answer = 2;
	else if (_dot[0] < 0 && _dot[1] < 0) answer = 3;
	else answer = 4;

	return answer;
}