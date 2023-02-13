/*
날짜 : 2023. 2. 13
이름 : 배성훈
내용 : operator 함수
	연산자를 오버로딩하는 두 가지 방법
	앞의 예제는 멤버함수로 오버로딩

	이번에는 전역함수로 오버로딩한다

	멤버함수로 오버로딩하고 전역함수 오버로딩도을 함께 하는 경우,
	일반적으로 멤버함수 기반으로 오버로딩 된 함수가 전역함수 기반으로 오버로딩 된 함수보다 우선시되어 호출된다
	단, 일부 오래된 컴파일러는 이러한 상황에서 컴파일 에러를 발생시키기도 한다
	그래서 가급적이면 동시에 사용하는걸 지양
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

	// 앞에서 했던 friend 키워드
	// friend 선언된 구간안에서는 이 클래스의 private 멤버들 이용 가능
	// Point 클래스는 + 연산자 오버로딩이 되었다고도 해석가능
	friend Point operator+(const Point& pos1, const Point& pos2);
};

Point operator+(const Point& pos1, const Point& pos2) {

	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

int main(void)
{

	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}