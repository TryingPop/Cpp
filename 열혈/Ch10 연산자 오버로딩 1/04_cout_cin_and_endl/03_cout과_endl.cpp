/*
날짜 : 2023. 2. 14
이름 : 배성훈
내용 : cout과 endl
	객체의 상태를 표현해주는 cout과 endl을 만들어보자
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

	// cout은 std 이름공간 안에 선언된 ostream의 객체이다
	friend ostream& operator<<(ostream&, const Point&);
};

// cout 객체에 멤버함수 하나를 추가해야하는데 ostream 클래스를 정정해야한다
// 이는 불가능한 방법이므로 전역함숭에 의한 방법을 이용한다
ostream& operator<<(ostream& os, const Point& pos) {

	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{

	Point pos1(1, 3);
	cout << pos1;

	Point pos2(101, 303);
	cout << pos2;
	return 0;
}