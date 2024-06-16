/*
날짜 : 2023. 2. 13
이름 : 배성훈
내용 : operator+ 라는 이름의 함수
	operator+ 함수 예제

	함수의 이름을 이용한 호출뿐만 아니라, 연산자를 이용한 함수의 호출도 허용
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

	// 덧셈 연산자에 대해 다음과 같은 규칙 적용
	// const 선언도 가능하다
	Point operator+(const Point& ref) {

		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};

int main(void)
{

	Point pos1(3, 4);
	Point pos2(10, 20);

	Point pos3 = pos1.operator+(pos2);
	// pos3의 형태로 변환해서 읽는다
	Point pos4 = pos1 + pos2;

	pos1.ShowPosition();	// [3, 4]
	pos2.ShowPosition();	// [10, 20]
	pos3.ShowPosition();	// [13, 24]
	pos4.ShowPosition();	// [13, 24]
	return 0;
}