#include <string>
#include <vector>

/*
날짜 : 2024. 3. 22
이름 : 배성훈
내용 : 캐릭터의 좌표
	up, down, left, right의 4개의 방향키가 있으며,
	방향 키를 누르면 현재위치에서 각각
	{ 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 }
	씩 이동합니다

	캐릭터는 항상 { 0, 0 } 에서 시작하고
	입력한 방향키의 배열 keyinput과
	맵의 크기 board가 매개변수로 주어진다

	맵의 범위를 벗어나는 키 입력은 무시할 때,
	키 입력이 모두 끝난 뒤에 캐릭터의 좌표 { x, y }를
	return 하는 solution 함수 구현

	board는 { a, b }의 형태이며,
	a, b는 모두 홀수이다

	예를들어 board = { 5, 3 } 인경우
	x의 범위는 -2 ~ 2까지이고, y의 범위는 -1 ~ 1까지이다
*/

using namespace std;

vector<int> solution(vector<string> _keyinput, vector<int> _board)
{

	vector<int> answer;
	answer.reserve(2);

	// 누른 키
	const string UP = "up";
	const string DOWN = "down";
	const string LEFT = "left";
	const string RIGHT = "right";

	int x = 0;
	int y = 0;

	// 경계선 확인용 변수
	int supX = _board[0] / 2;
	int supY = _board[1] / 2;

	for (const string s : _keyinput)
	{

		// 키입력에 따른 좌표이동
		if (s == UP) y++;
		else if (s == DOWN) y--;
		else if (s == LEFT) x--;
		else if (s == RIGHT) x++;

		// 경계선을 벗어나는 이동인 경우 키 입력 무시
		if (x > supX) x = supX;
		else if (x < -supX) x = -supX;

		if (y > supY) y = supY;
		else if (x < -supY) y = -supY;
	}

	answer.push_back(x);
	answer.push_back(y);

	return answer;
}