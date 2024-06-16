/*
날짜 : 2023. 2. 14
이름 : 배성훈
내용 : 교재 418p 문제2
	~ 연산자는 단항 연산자로서 비트단위 not의 의미를 갖는다.
	즉, ~ 연산자는 비트단위로 1은 0으로, 0은 1로 바꾼다.
	이에 우리는 Point 객체를 대상으로 다음과 같이 연산이 가능하도록 ~ 연산자를 오버로딩 하고자 한다.
		Point pos2 = ~pos1;

	위의 ~ 연산의 결과로 반환된 객체의 xpos 멤버에는 pos1의 ypos 값이,
	반환된 객체의 ypos 멤버에는 pos1의 xpos 값이 저장되어야 한다.

	이번에도 하나의 답안에 위의 두 문제에 대한 답을 모두 담아도 된다.
	답지도 그러한 형태로 답안을 제시
*/

#include <iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		: xpos(x), ypos(y) { }

	void ShowPosition() const {

		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	Point& operator~() {

		Point pos(ypos, xpos);
		return pos;
	}
};


int main(void)
{

	Point pos1(1, 2);
	Point pos2 = ~pos1;

	pos2.ShowPosition();
	return 0;
}